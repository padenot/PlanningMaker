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

#ifndef _QX_IS_CONTAINER_TO_POD_H_
#define _QX_IS_CONTAINER_TO_POD_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>

#include <QxTraits/is_container.h>
#include <QxTraits/is_qx_pod.h>

namespace qx {
namespace trait {

template <typename T>
class is_container_to_pod
{

private:

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const std::vector<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const std::list<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const std::set<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const QVector<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const QList<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const QSet<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const QLinkedList<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const boost::unordered_set<U> &);

   template <typename U>
   static typename boost::mpl::if_c<qx::trait::is_qx_pod<U>::value, char, int>::type removeContainer(const boost::unordered_multiset<U> &);

   static int removeContainer(...);
   static T t;

public:

   enum { value = (qx::trait::is_container<T>::value && (sizeof(qx::trait::is_container_to_pod<T>::removeContainer(t)) == sizeof(char))) };

   typedef typename boost::mpl::if_c<qx::trait::is_container_to_pod<T>::value, boost::mpl::true_, boost::mpl::false_>::type type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_CONTAINER_TO_POD_H_
