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

#ifndef _QX_CONSTRUCT_PTR_H_
#define _QX_CONSTRUCT_PTR_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include <boost/type_traits/is_abstract.hpp>
#include <boost/type_traits/remove_pointer.hpp>

#include <QtCore/qsharedpointer.h>

#if (QT_VERSION >= 0x040600)
#include <QtCore/qscopedpointer.h>
#endif // (QT_VERSION >= 0x040600)

namespace qx {
namespace trait {

template <typename T>
struct construct_ptr
{

private:

   typedef typename boost::remove_pointer<T>::type type_ptr;

public:

   static inline void get(T & t)
   { qx::trait::construct_ptr<T>::new_ptr<boost::is_abstract<type_ptr>::value, 0>::get(t); }

private:

   template <bool isAbstract /* = false */, int dummy>
   struct new_ptr
   { static inline void get(T & t) { t = new type_ptr(); } };

   template <int dummy>
   struct new_ptr<true, dummy>
   { static inline void get(T & t) { Q_UNUSED(t); qDebug("[QxOrm] qx::trait::construct_ptr<T> : %s", "cannot instantiate abstract class"); } };

};

template <typename T>
struct construct_ptr< boost::scoped_ptr<T> >
{ static inline void get(boost::scoped_ptr<T> & t) { t.reset(new T()); } };

template <typename T>
struct construct_ptr< boost::shared_ptr<T> >
{ static inline void get(boost::shared_ptr<T> & t) { t.reset(new T()); } };

template <typename T>
struct construct_ptr< boost::intrusive_ptr<T> >
{ static inline void get(boost::intrusive_ptr<T> & t) { t.reset(new T()); } };

template <typename T>
struct construct_ptr< QSharedPointer<T> >
{ static inline void get(QSharedPointer<T> & t) { t = QSharedPointer<T>(new T()); } };

#if (QT_VERSION >= 0x040600)
template <typename T>
struct construct_ptr< QScopedPointer<T> >
{ static inline void get(QScopedPointer<T> & t) { t = QScopedPointer<T>(new T()); } };
#endif // (QT_VERSION >= 0x040600)

} // namespace trait
} // namespace qx

#endif // _QX_CONSTRUCT_PTR_H_
