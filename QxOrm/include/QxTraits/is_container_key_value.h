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

#ifndef _QX_IS_CONTAINER_KEY_VALUE_H_
#define _QX_IS_CONTAINER_KEY_VALUE_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/logical.hpp>

#include <QxTraits/is_container.h>

namespace qx {
namespace trait {

template <typename T>
class is_container_key_value
{

private:

   typedef typename boost::mpl::or_< qx::trait::is_boost_unordered_map<T>, 
                                     qx::trait::is_std_map<T>, 
                                     qx::trait::is_qt_map<T>, 
                                     qx::trait::is_qt_hash<T> >::type cond_is_container_key_value_1;

   typedef typename boost::mpl::or_< typename qx::trait::is_container_key_value<T>::cond_is_container_key_value_1, 
                                     qx::trait::is_qt_multi_map<T>, 
                                     qx::trait::is_qt_multi_hash<T>, 
                                     qx::trait::is_qx_collection<T> >::type cond_is_container_key_value_2;

   typedef typename boost::mpl::if_< typename qx::trait::is_container_key_value<T>::cond_is_container_key_value_2, 
                                     boost::mpl::true_, 
                                     boost::mpl::false_ >::type type_is_container_key_value;

public:

   enum { value = (qx::trait::is_container<T>::value && qx::trait::is_container_key_value<T>::type_is_container_key_value::value) };

   typedef typename boost::mpl::if_c<qx::trait::is_container_key_value<T>::value, boost::mpl::true_, boost::mpl::false_>::type type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_CONTAINER_KEY_VALUE_H_
