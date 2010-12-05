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

#ifndef _QX_IS_CONTAINER_BASE_OF_H_
#define _QX_IS_CONTAINER_BASE_OF_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>
#include <boost/type_traits/is_base_of.hpp>

#include <QxTraits/is_container.h>

#define qx_container_base_of_test_0() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer(b, d)) == sizeof(char))
#define qx_container_base_of_test_1() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_std_vector), d)) == sizeof(char))
#define qx_container_base_of_test_2() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_std_list), d)) == sizeof(char))
#define qx_container_base_of_test_3() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_std_set), d)) == sizeof(char))
#define qx_container_base_of_test_4() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_qt_vector), d)) == sizeof(char))
#define qx_container_base_of_test_5() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_qt_list), d)) == sizeof(char))
#define qx_container_base_of_test_6() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_qt_set), d)) == sizeof(char))
#define qx_container_base_of_test_7() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_qt_linked_list), d)) == sizeof(char))
#define qx_container_base_of_test_8() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_boost_unordered_set), d)) == sizeof(char))
#define qx_container_base_of_test_9() (sizeof(qx::trait::is_container_base_of<B, D>::removeContainer((* b_boost_unordered_multi_set), d)) == sizeof(char))

#define qx_container_base_of_all_test() \
qx_container_base_of_test_1() || qx_container_base_of_test_2() || qx_container_base_of_test_3() || \
qx_container_base_of_test_4() || qx_container_base_of_test_5() || qx_container_base_of_test_6() || \
qx_container_base_of_test_7() || qx_container_base_of_test_8() || qx_container_base_of_test_9()

namespace qx {
namespace trait {

template <typename B, typename D>
class is_container_base_of
{

private:

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const std::vector<V> &, const std::vector<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const std::list<V> &, const std::list<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const std::set<V> &, const std::set<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const QVector<V> &, const QVector<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const QList<V> &, const QList<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const QSet<V> &, const QSet<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const QLinkedList<V> &, const QLinkedList<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const boost::unordered_set<V> &, const boost::unordered_set<W> &);

   template <typename V, typename W>
   static typename boost::mpl::if_c<boost::is_base_of<V, W>::value, char, int>::type removeContainer(const boost::unordered_multiset<V> &, const boost::unordered_multiset<W> &);

   static int removeContainer(...);
   static B b;
   static D d;

   static std::vector<B> * b_std_vector;
   static std::list<B> * b_std_list;
   static std::set<B> * b_std_set;
   static QVector<B> * b_qt_vector;
   static QList<B> * b_qt_list;
   static QSet<B> * b_qt_set;
   static QLinkedList<B> * b_qt_linked_list;
   static boost::unordered_set<B> * b_boost_unordered_set;
   static boost::unordered_multiset<B> * b_boost_unordered_multi_set;

   enum { value_0 = (qx::trait::is_container<D>::value) };
   enum { value_1 = (qx::trait::is_container<B>::value) };
   enum { value_2 = ((value_0 && value_1) ? qx_container_base_of_test_0() : 0) };
   enum { value_3 = ((value_0 && ! value_1) ? qx_container_base_of_all_test() : 0) };

public:

   enum { value = (qx::trait::is_container_base_of<B, D>::value_2 || qx::trait::is_container_base_of<B, D>::value_3) };

   typedef typename boost::mpl::if_c<qx::trait::is_container_base_of<B, D>::value, boost::mpl::true_, boost::mpl::false_>::type type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_CONTAINER_BASE_OF_H_
