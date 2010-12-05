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

#ifndef _QX_REMOVE_ATTR_H_
#define _QX_REMOVE_ATTR_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/mpl/if.hpp>
#include <boost/mpl/logical.hpp>

#include <boost/type_traits/remove_pointer.hpp>
#include <boost/type_traits/remove_const.hpp>
#include <boost/type_traits/remove_reference.hpp>
#include <boost/type_traits/remove_volatile.hpp>

namespace qx {
namespace trait {

template <typename T, bool bRemovePtr = true, bool bRemoveConst = true, bool bRemoveRef = true, bool bRemoveVolatile = true>
class remove_attr
{

private:

   typedef typename boost::mpl::if_c<bRemovePtr, typename boost::remove_pointer<T>::type, T>::type type_1;
   typedef typename boost::mpl::if_c<bRemoveConst, typename boost::remove_const<type_1>::type, type_1>::type type_2;
   typedef typename boost::mpl::if_c<bRemoveRef, typename boost::remove_reference<type_2>::type, type_2>::type type_3;
   typedef typename boost::mpl::if_c<bRemoveVolatile, typename boost::remove_volatile<type_3>::type, type_3>::type type_4;

public:

   typedef type_4 type;

};

} // namespace trait
} // namespace qx

#endif // _QX_REMOVE_ATTR_H_
