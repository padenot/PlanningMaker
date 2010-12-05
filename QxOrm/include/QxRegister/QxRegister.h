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

#ifndef _QX_REGISTER_H_
#define _QX_REGISTER_H_

#ifdef _MSC_VER
#pragma once
#endif

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4996)
#pragma warning(disable:4094)
#endif // _MSC_VER

#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/static_assert.hpp>

#include <QxCommon/QxConfig.h>
#include <QxCommon/QxMacro.h>

#include <QxRegister/QxClass.h>

#include <QxFactory/QxFactory.h>

#include <QxSerialize/QxSerializeInvoker.h>
#include <QxSerialize/QxBoostSerializeHelper/QxBoostSerializeRegisterHelper.h>
#include <QxSerialize/boost/QxExportDllMacroHpp.h>
#include <QxSerialize/boost/QxExportDllMacroCpp.h>

#include <QxTraits/is_qx_registered.h>

#define QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(Archive, className) \
namespace boost { namespace serialization { \
inline void serialize(Archive & ar, className & t, const unsigned int file_version) \
{ \
   BOOST_STATIC_ASSERT(qx::trait::is_qx_registered< className >::value); \
   typedef boost::mpl::if_c< Archive::is_saving::value, qx::serialization::detail::saver< Archive, className >, qx::serialization::detail::loader< Archive, className > >::type type_invoker; \
   type_invoker::invoke(ar, t, file_version); \
} } } // namespace boost::serialization

#define QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, Archive, className) \
namespace boost { namespace serialization { \
dllImportExport void serialize(Archive & ar, className & t, const unsigned int file_version) BOOST_USED; \
} } // namespace boost::serialization

#define QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(Archive, className) \
namespace boost { namespace serialization { \
inline void serialize(Archive & ar, className & t, const unsigned int file_version) \
{ Q_UNUSED(ar); Q_UNUSED(t); Q_UNUSED(file_version); \
} } } // namespace boost::serialization

#define QX_SERIALIZE_ARCHIVE_TEMPLATE_HPP(className) \
namespace boost { namespace serialization { \
template <class Archive> \
void serialize(Archive & ar, className & t, const unsigned int file_version); \
} } // namespace boost::serialization

#if _QX_SERIALIZE_POLYMORPHIC
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_POLYMORPHIC_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::polymorphic_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::polymorphic_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_binary_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_binary_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_text_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_text_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_xml_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::polymorphic_xml_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::binary_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::binary_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::text_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::text_iarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::xml_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_EMPTY_CPP(boost::archive::xml_iarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_POLYMORPHIC_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::polymorphic_oarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::polymorphic_iarchive, className) \
QX_SERIALIZE_ARCHIVE_TEMPLATE_HPP(className)
#else // _QX_SERIALIZE_POLYMORPHIC
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_POLYMORPHIC_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_POLYMORPHIC_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_POLYMORPHIC

#if _QX_SERIALIZE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::binary_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::binary_iarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::binary_oarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::binary_iarchive, className)
#else // _QX_SERIALIZE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_BINARY_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_BINARY_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_BINARY

#if _QX_SERIALIZE_TEXT
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_TEXT_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::text_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::text_iarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_TEXT_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::text_oarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::text_iarchive, className)
#else // _QX_SERIALIZE_TEXT
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_TEXT_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_TEXT_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_TEXT

#if _QX_SERIALIZE_XML
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_XML_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::xml_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::xml_iarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_XML_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::xml_oarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::xml_iarchive, className)
#else // _QX_SERIALIZE_XML
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_XML_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_XML_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_XML

#if _QX_SERIALIZE_PORTABLE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_PORTABLE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(eos::portable_oarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(eos::portable_iarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_PORTABLE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, eos::portable_oarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, eos::portable_iarchive, className)
#else // _QX_SERIALIZE_PORTABLE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_PORTABLE_BINARY_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_PORTABLE_BINARY_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_PORTABLE_BINARY

#if _QX_SERIALIZE_WIDE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::binary_woarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::binary_wiarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::binary_woarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::binary_wiarchive, className)
#else // _QX_SERIALIZE_WIDE_BINARY
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_BINARY_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_BINARY_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_WIDE_BINARY

#if _QX_SERIALIZE_WIDE_TEXT
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_TEXT_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::text_woarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::text_wiarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_TEXT_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::text_woarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::text_wiarchive, className)
#else // _QX_SERIALIZE_WIDE_TEXT
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_TEXT_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_TEXT_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_WIDE_TEXT

#if _QX_SERIALIZE_WIDE_XML
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_XML_CPP(className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::xml_woarchive, className) \
QX_SERIALIZE_IMPLEMENT_ARCHIVE_CPP(boost::archive::xml_wiarchive, className)
// ---
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_XML_HPP(dllImportExport, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::xml_woarchive, className) \
QX_SERIALIZE_ARCHIVE_HPP(dllImportExport, boost::archive::xml_wiarchive, className)
#else // _QX_SERIALIZE_WIDE_XML
#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_XML_CPP(className) /* Nothing */
#define QX_SERIALIZE_LIST_ARCHIVE_WIDE_XML_HPP(dllImportExport, className) /* Nothing */
#endif // _QX_SERIALIZE_WIDE_XML

#define QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_POLYMORPHIC_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_TEXT_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_XML_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_PORTABLE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_BINARY_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_TEXT_CPP(className) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_WIDE_XML_CPP(className)

#define QX_SERIALIZE_LIST_ARCHIVE_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_POLYMORPHIC_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_TEXT_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_XML_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_PORTABLE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_WIDE_BINARY_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_WIDE_TEXT_HPP(dllImportExport, className) \
QX_SERIALIZE_LIST_ARCHIVE_WIDE_XML_HPP(dllImportExport, className)

#if _QX_WRITE_BOOST_CLASS_EXPORT_IN_HPP_FILE
#define QX_BOOST_CLASS_EXPORT_HPP(className) BOOST_CLASS_EXPORT_GUID(className, #className)
#else
#define QX_BOOST_CLASS_EXPORT_HPP(className) /* Nothing */
#endif // _QX_WRITE_BOOST_CLASS_EXPORT_IN_HPP_FILE

#if _QX_WRITE_BOOST_CLASS_EXPORT_IN_CPP_FILE
#define QX_BOOST_CLASS_EXPORT_CPP(className) BOOST_CLASS_EXPORT_GUID(className, #className)
#else
#define QX_BOOST_CLASS_EXPORT_CPP(className) /* Nothing */
#endif // _QX_WRITE_BOOST_CLASS_EXPORT_IN_CPP_FILE

#define QX_REGISTER_FRIEND_CLASS(className) \
template <class T> friend void qx::register_class(T & t);

#define QX_DLL_EXPORT_TEMPLATE_QX_CLASS_HPP(className) \
QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxDataMemberX< className >) \
QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxSingleton< qx::QxDataMemberX< className > >) \
QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxClass< className >) \
QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxSingleton< qx::QxClass< className > >)

#define QX_DLL_EXPORT_TEMPLATE_QX_CLASS_CPP(className) \
QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxDataMemberX< className >) \
QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxSingleton< qx::QxDataMemberX< className > >) \
QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxClass< className >) \
QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxSingleton< qx::QxClass< className > >)

#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP(className, baseClass, version, classNameFormatted) \
QX_SET_REGISTERED(className) \
QX_REGISTER_CLASS_NAME(className) \
QX_REGISTER_BASE_CLASS(className, baseClass) \
QX_REGISTER_FACTORY_COMPLEX_CLASS_NAME_HPP(className, classNameFormatted) \
QX_REGISTER_BOOST_SERIALIZE_HELPER_COMPLEX_CLASS_NAME(className, classNameFormatted) \
QX_BOOST_CLASS_EXPORT_HPP(className) \
BOOST_CLASS_VERSION(className, version)

#define QX_REGISTER_HPP(className, baseClass, version) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP(className, baseClass, version, className)

#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted) \
QX_BOOST_CLASS_EXPORT_CPP(className) \
QX_REGISTER_FACTORY_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted) \
QX_REGISTER_BOOST_SERIALIZE_HELPER_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted) \
QX_SERIALIZE_IMPLEMENT_LIST_ARCHIVE_CPP(className)

#define QX_REGISTER_CPP(className) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP(className, className)

#ifdef _MSC_VER
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(className, baseClass, version, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP(className, baseClass, version, classNameFormatted) \
QX_SERIALIZE_LIST_ARCHIVE_HPP(QX_DLL_EXPORT_HELPER, className) \
namespace qx { template <> QX_DLL_EXPORT_HELPER void register_class(QxClass< className > & t) BOOST_USED; }
// ---
#define QX_REGISTER_HPP_EXPORT_DLL(className, baseClass, version) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(className, baseClass, version, className)
#else // _MSC_VER
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(className, baseClass, version, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP(className, baseClass, version, classNameFormatted) \
QX_DLL_EXPORT_TEMPLATE_QX_CLASS_HPP(className) \
QX_BOOST_EXPORT_SERIALIZATION_HPP(className) \
QX_SERIALIZE_LIST_ARCHIVE_HPP(QX_DLL_EXPORT_HELPER, className) \
namespace qx { template <> QX_DLL_EXPORT_HELPER void register_class(QxClass< className > & t) BOOST_USED; }
// ---
#define QX_REGISTER_HPP_EXPORT_DLL(className, baseClass, version) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL(className, baseClass, version, className)
#endif // _MSC_VER

#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_IMPORT_DLL(className, baseClass, version, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP(className, baseClass, version, classNameFormatted) \
QX_DLL_EXPORT_TEMPLATE_QX_CLASS_HPP(className) \
QX_BOOST_EXPORT_SERIALIZATION_HPP(className) \
QX_SERIALIZE_LIST_ARCHIVE_HPP(QX_DLL_IMPORT_HELPER, className) \
namespace qx { template <> QX_DLL_IMPORT_HELPER void register_class(QxClass< className > & t) BOOST_USED; }

#define QX_REGISTER_HPP_IMPORT_DLL(className, baseClass, version) \
QX_REGISTER_COMPLEX_CLASS_NAME_HPP_IMPORT_DLL(className, baseClass, version, className)

#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL(className, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted) \
QX_DLL_EXPORT_TEMPLATE_QX_CLASS_CPP(className) \
QX_BOOST_EXPORT_SERIALIZATION_CPP(className)

#define QX_REGISTER_CPP_EXPORT_DLL(className) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL(className, className)

#ifdef _MSC_VER
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL(className, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted)
// ---
#define QX_REGISTER_CPP_IMPORT_DLL(className) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL(className, className)
#else // _MSC_VER
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL(className, classNameFormatted) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP(className, classNameFormatted) \
QX_DLL_EXPORT_TEMPLATE_QX_CLASS_CPP(className) \
QX_BOOST_EXPORT_SERIALIZATION_CPP(className)
// ---
#define QX_REGISTER_CPP_IMPORT_DLL(className) \
QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL(className, className)
#endif // _MSC_VER

/* -- Create your macro (in your precompiled header) replacing "MY_DLL"
#ifdef _BUILDING_MY_DLL
#define QX_REGISTER_HPP_MY_DLL QX_REGISTER_HPP_EXPORT_DLL
#define QX_REGISTER_CPP_MY_DLL QX_REGISTER_CPP_EXPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MY_DLL QX_REGISTER_COMPLEX_CLASS_NAME_HPP_EXPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MY_DLL QX_REGISTER_COMPLEX_CLASS_NAME_CPP_EXPORT_DLL
#else
#define QX_REGISTER_HPP_MY_DLL QX_REGISTER_HPP_IMPORT_DLL
#define QX_REGISTER_CPP_MY_DLL QX_REGISTER_CPP_IMPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_HPP_MY_DLL QX_REGISTER_COMPLEX_CLASS_NAME_HPP_IMPORT_DLL
#define QX_REGISTER_COMPLEX_CLASS_NAME_CPP_MY_DLL QX_REGISTER_COMPLEX_CLASS_NAME_CPP_IMPORT_DLL
#endif // _BUILDING_MY_DLL
*/

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#endif // _QX_REGISTER_H_
