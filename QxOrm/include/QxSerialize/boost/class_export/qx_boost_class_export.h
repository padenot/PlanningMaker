/****************************************************************************
**
** http://www.qxorm.com/
** http://sourceforge.net/projects/qxorm/
** Original file by Lionel Marty
**
** This file is part of the QxOrm library
**
** This software is provided 'as-is', without any express or implied
** warranty. In no event will the authors be held liable for any
** damages arising from the use of this software.
**
** GNU Lesser General Public License Usage
** This file must be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file 'license.lgpl.txt' included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact :
** contact@qxorm.com
**
****************************************************************************/

#ifndef _QX_BOOST_SERIALIZATION_EXPORT_HPP_
#define _QX_BOOST_SERIALIZATION_EXPORT_HPP_

#ifdef _MSC_VER
#pragma once
#endif

#include <QxCommon/QxConfig.h>

#if _QX_USE_MODIFY_BOOST_SERIALIZATION_EXPORT_HPP

#include <utility>
#include <cstddef> // NULL

#include <boost/config.hpp>
#include <boost/static_assert.hpp>
#include <boost/preprocessor/stringize.hpp>
#include <boost/type_traits/is_polymorphic.hpp>

#ifndef BOOST_SERIALIZATION_DEFAULT_TYPE_INFO   
    #include <boost/serialization/extended_type_info_typeid.hpp>   
#endif // BOOST_SERIALIZATION_DEFAULT_TYPE_INFO

#include <boost/serialization/static_warning.hpp>
#include <boost/serialization/type_info_implementation.hpp>
#include <boost/serialization/assume_abstract.hpp>
#include <boost/serialization/force_include.hpp>
#include <boost/serialization/singleton.hpp>

#include <boost/archive/detail/register_archive.hpp>
#include <boost/mpl/assert.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/mpl/bool.hpp>

#include <iostream>

namespace boost {
namespace archive {
namespace detail {

class basic_pointer_iserializer;
class basic_pointer_oserializer;

template<class Archive, class T>
class pointer_iserializer;
template<class Archive, class T>
class pointer_oserializer;

template <class Archive, class Serializable>
struct export_impl
{
    static const basic_pointer_iserializer &
    enable_load(mpl::true_){
        return boost::serialization::singleton<
            pointer_iserializer<Archive, Serializable> 
        >::get_const_instance();
    }

    static const basic_pointer_oserializer &
    enable_save(mpl::true_){
        return boost::serialization::singleton<
            pointer_oserializer<Archive, Serializable> 
        >::get_const_instance();
    }
    inline static void enable_load(mpl::false_) {}
    inline static void enable_save(mpl::false_) {}
};

// On many platforms, naming a specialization of this template is
// enough to cause its argument to be instantiated.
template <void(*)()>
struct instantiate_function {};

template <class Archive, class Serializable>
struct ptr_serialization_support
{
# if defined(BOOST_MSVC)
    virtual BOOST_DLLEXPORT void instantiate() BOOST_USED;
# elif defined(__BORLANDC__)   
    static BOOST_DLLEXPORT void instantiate() BOOST_USED;
    enum { x = sizeof(instantiate(),3) };
# else
    static BOOST_DLLEXPORT void instantiate() BOOST_USED;
    typedef instantiate_function<
        &ptr_serialization_support::instantiate
    > x;
# endif
};

template <class Archive, class Serializable>
BOOST_DLLEXPORT void 
ptr_serialization_support<Archive,Serializable>::instantiate()
{
    export_impl<Archive,Serializable>::enable_save(
        #if ! defined(__BORLANDC__)
        BOOST_DEDUCED_TYPENAME 
        #endif
        Archive::is_saving()
    );

    export_impl<Archive,Serializable>::enable_load(
        #if ! defined(__BORLANDC__)
        BOOST_DEDUCED_TYPENAME 
        #endif
        Archive::is_loading()
    );
}

template<class T>
struct guid_initializer
{  
    const guid_initializer & export_guid(char const* /* key */, mpl::false_){
        // generates the statically-initialized objects whose constructors
        // register the information allowing serialization of T objects
        // through pointers to their base classes.
        instantiate_ptr_serialization((T*)0, 0, adl_tag());
        return *this;
    }
    const guid_initializer & export_guid(char const* /*key*/, mpl::true_){
        return *this;
    }
    const guid_initializer & export_guid(char const* key){
        BOOST_STATIC_WARNING(boost::is_polymorphic<T>::value);
        assert(NULL != key);
        boost::serialization::singleton<
            BOOST_DEDUCED_TYPENAME 
            boost::serialization::type_info_implementation<T>::type
        >::get_mutable_instance().key_register(key);
        // note: exporting an abstract base class will have no effect
        // and cannot be used to instantitiate serialization code
        // (one might be using this in a DLL to instantiate code)
        //BOOST_STATIC_WARNING(! boost::serialization::is_abstract<T>::value);
        return export_guid(key, boost::serialization::is_abstract<T>());
    }
};

} // namespace detail
} // namespace archive
} // namespace boost

#define BOOST_CLASS_EXPORT_GUID(T, K)                                               \
namespace                                                                           \
{                                                                                   \
    ::boost::archive::detail::guid_initializer< T > const &                         \
        boost_serialization_guid_initializer_##T                                    \
        = ::boost::serialization::singleton<                                        \
            ::boost::archive::detail::guid_initializer< T >                         \
          >::get_mutable_instance().export_guid(K);                                 \
}

// check for unnecessary export.  T isn't polymorphic so there is no
// need to export it.
#define BOOST_CLASS_EXPORT_CHECK(T)                              \
    BOOST_STATIC_WARNING(                                        \
        boost::is_polymorphic<U>::value                          \
    );                                                           \
    /**/

// the default exportable class identifier is the class name
// the default list of archives types for which code id generated
// are the originally included with this serialization system
#define BOOST_CLASS_EXPORT(T)                   \
    BOOST_CLASS_EXPORT_GUID(                    \
        T,                                      \
        BOOST_PP_STRINGIZE(T)                   \
    )                                           \
    /**/

#endif // _QX_USE_MODIFY_BOOST_SERIALIZATION_EXPORT_HPP
#endif // _QX_BOOST_SERIALIZATION_EXPORT_HPP_
