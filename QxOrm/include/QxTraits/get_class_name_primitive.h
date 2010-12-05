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

#ifndef _QX_GET_CLASS_NAME_PRIMITIVE_H_
#define _QX_GET_CLASS_NAME_PRIMITIVE_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/unordered_set.hpp>
#include <boost/tuple/tuple.hpp>

#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtCore/qstringlist.h>
#include <QtCore/qvector.h>
#include <QtCore/qlist.h>
#include <QtCore/qmap.h>
#include <QtCore/qset.h>
#include <QtCore/qhash.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qvariant.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qlinkedlist.h>
#include <QtCore/qpair.h>
#include <QtCore/qpoint.h>
#include <QtCore/qrect.h>
#include <QtCore/qregexp.h>
#include <QtCore/qsharedpointer.h>
#include <QtCore/qsize.h>
#include <QtCore/qurl.h>
#include <QtCore/QWeakPointer>

#include <QtGui/qcolor.h>
#include <QtGui/qfont.h>
#include <QtGui/qimage.h>
#include <QtGui/qbrush.h>
#include <QtGui/qmatrix.h>
#include <QtGui/qpicture.h>
#include <QtGui/qpixmap.h>
#include <QtGui/qregion.h>

#if (QT_VERSION >= 0x040600)
#include <QtCore/qscopedpointer.h>
#endif // (QT_VERSION >= 0x040600)

#include <QxTraits/get_class_name.h>

QX_REGISTER_CLASS_NAME(bool)
QX_REGISTER_CLASS_NAME(int)
QX_REGISTER_CLASS_NAME(short)
QX_REGISTER_CLASS_NAME(long)
QX_REGISTER_CLASS_NAME(float)
QX_REGISTER_CLASS_NAME(double)
QX_REGISTER_CLASS_NAME(long double)
QX_REGISTER_CLASS_NAME(char)
QX_REGISTER_CLASS_NAME(unsigned int)
QX_REGISTER_CLASS_NAME(unsigned short)
QX_REGISTER_CLASS_NAME(unsigned long)
QX_REGISTER_CLASS_NAME(unsigned char)

QX_REGISTER_CLASS_NAME(std::string)
QX_REGISTER_CLASS_NAME(std::wstring)

QX_REGISTER_CLASS_NAME(QObject)
QX_REGISTER_CLASS_NAME(QString)
QX_REGISTER_CLASS_NAME(QStringList)
QX_REGISTER_CLASS_NAME(QBrush)
QX_REGISTER_CLASS_NAME(QByteArray)
QX_REGISTER_CLASS_NAME(QColor)
QX_REGISTER_CLASS_NAME(QDate)
QX_REGISTER_CLASS_NAME(QDateTime)
QX_REGISTER_CLASS_NAME(QFont)
QX_REGISTER_CLASS_NAME(QImage)
QX_REGISTER_CLASS_NAME(QMatrix)
QX_REGISTER_CLASS_NAME(QPicture)
QX_REGISTER_CLASS_NAME(QPixmap)
QX_REGISTER_CLASS_NAME(QPoint)
QX_REGISTER_CLASS_NAME(QRect)
QX_REGISTER_CLASS_NAME(QRegExp)
QX_REGISTER_CLASS_NAME(QRegion)
QX_REGISTER_CLASS_NAME(QSize)
QX_REGISTER_CLASS_NAME(QTime)
QX_REGISTER_CLASS_NAME(QUrl)
QX_REGISTER_CLASS_NAME(QVariant)

QX_REGISTER_CLASS_NAME_TEMPLATE_1(std::allocator)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(std::vector)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(std::list)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(std::set)

QX_REGISTER_CLASS_NAME_TEMPLATE_1(boost::shared_ptr)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(boost::scoped_ptr)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(boost::weak_ptr)

QX_REGISTER_CLASS_NAME_TEMPLATE_1(QVector)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(QList)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(QLinkedList)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(QSharedPointer)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(QWeakPointer)

QX_REGISTER_CLASS_NAME_TEMPLATE_2(std::pair)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(std::map)

QX_REGISTER_CLASS_NAME_TEMPLATE_2(boost::unordered_map)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(boost::unordered_multimap)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(boost::unordered_set)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(boost::unordered_multiset)

QX_REGISTER_CLASS_NAME_TEMPLATE_2(QPair)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(QHash)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(QMultiHash)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(QMap)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(QMultiMap)

QX_REGISTER_CLASS_NAME_TEMPLATE_1(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_2(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_3(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_4(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_5(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_6(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_7(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_8(boost::tuple)
QX_REGISTER_CLASS_NAME_TEMPLATE_9(boost::tuple)

#if (QT_VERSION >= 0x040600)
QX_REGISTER_CLASS_NAME_TEMPLATE_1(QScopedPointer)
#endif // (QT_VERSION >= 0x040600)

#endif // _QX_GET_CLASS_NAME_PRIMITIVE_H_
