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

#ifndef _QX_IS_SMART_PTR_H_
#define _QX_IS_SMART_PTR_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/mpl/if.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/logical.hpp>

#include <QxTraits/is_boost_intrusive_ptr.h>
#include <QxTraits/is_boost_scoped_ptr.h>
#include <QxTraits/is_boost_shared_ptr.h>
#include <QxTraits/is_boost_weak_ptr.h>
#include <QxTraits/is_qt_shared_data_ptr.h>
#include <QxTraits/is_qt_scoped_ptr.h>
#include <QxTraits/is_qt_shared_ptr.h>
#include <QxTraits/is_qt_weak_ptr.h>

namespace qx {
namespace trait {

template <typename T>
class is_smart_ptr
{

private:

   typedef typename boost::mpl::or_< qx::trait::is_boost_intrusive_ptr<T>, 
                                     qx::trait::is_boost_scoped_ptr<T>, 
                                     qx::trait::is_boost_shared_ptr<T>, 
                                     qx::trait::is_boost_weak_ptr<T> >::type cond_is_boost_smart_ptr;

   typedef typename boost::mpl::or_< typename qx::trait::is_smart_ptr<T>::cond_is_boost_smart_ptr, 
                                     qx::trait::is_qt_scoped_ptr<T>, 
                                     qx::trait::is_qt_shared_ptr<T>, 
                                     qx::trait::is_qt_weak_ptr<T>, 
                                     qx::trait::is_qt_shared_data_ptr<T> >::type cond_is_smart_ptr;

   typedef typename boost::mpl::if_< typename qx::trait::is_smart_ptr<T>::cond_is_smart_ptr, 
                                     boost::mpl::true_, 
                                     boost::mpl::false_ >::type type_is_smart_ptr;

public:

   enum { value = qx::trait::is_smart_ptr<T>::type_is_smart_ptr::value };

   typedef typename qx::trait::is_smart_ptr<T>::type_is_smart_ptr type;

};

} // namespace trait
} // namespace qx

#endif // _QX_IS_SMART_PTR_H_
