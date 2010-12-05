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

#ifndef _QX_ORM_PRECOMPILED_HEADER_H_
#define _QX_ORM_PRECOMPILED_HEADER_H_

#ifdef _MSC_VER
#pragma once
#endif

#define BOOST_ALL_NO_LIB /* -- Disable auto-link feature provided by boost -- */

#ifdef _MSC_VER
#pragma warning(disable:4503) /* -- Disable 4503 warning because of boost template -- */
#pragma warning(disable:4100) /* -- Disable warning 'unreferenced formal parameter' -- */
#pragma warning(disable:4996)
#pragma warning(disable:4661)
#endif // _MSC_VER

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

#include <QtCore/qglobal.h>
#include <QtCore/qobject.h>
#include <QtCore/qdebug.h>
#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvector.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qset.h>
#include <QtCore/qhash.h>
#include <QtCore/qthread.h>
#include <QtCore/qmutex.h>
#include <QtCore/qdir.h>
#include <QtCore/qfile.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qvariant.h>
#include <QtCore/qpair.h>

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4396)
#endif // _MSC_VER

#include <boost/config.hpp>
#include <boost/serialization/force_include.hpp>

#ifdef BOOST_DLLEXPORT
#undef BOOST_DLLEXPORT
#define BOOST_DLLEXPORT /* Nothing */
#endif // BOOST_DLLEXPORT

#include <boost/version.hpp>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/foreach.hpp>
#include <boost/bind.hpp>

#ifdef _MSC_VER
#include <boost/serialization/serialization.hpp> /* -- To avoid warning 4100 => header in precompiled header -- */
#include <boost/archive/detail/iserializer.hpp>
#include <boost/archive/detail/oserializer.hpp>
#endif // _MSC_VER

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER

#include <QxCommon/QxConfig.h>
#include <QxCommon/QxMacro.h>

#endif // _QX_ORM_PRECOMPILED_HEADER_H_
