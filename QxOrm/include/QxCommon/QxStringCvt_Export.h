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

#ifndef _QX_STRING_CVT_EXPORT_H_
#define _QX_STRING_CVT_EXPORT_H_
#if _QX_USE_QX_STRING_CVT_EXPORT

#ifdef _MSC_VER
#pragma once
#endif

#include <QxCommon/QxStringCvt.h>
#include <QxCommon/QxStringCvt_Impl.h>

QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, qx::trait::no_type)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QString)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QDate)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QDateTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QByteArray)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QVariant)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, qx_bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, char)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, float)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, double)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, unsigned short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, unsigned int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, unsigned long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, unsigned long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, std::string)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, std::wstring)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QBrush)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QColor)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QFont)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QMatrix)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QObject)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QPoint)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QRect)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QRegExp)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QRegion)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QSize)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QStringList)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QUrl)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QImage)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QPicture)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToString, QPixmap)

QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, qx::trait::no_type)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QString)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QDate)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QDateTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QByteArray)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QVariant)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, qx_bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, char)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, float)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, double)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, unsigned short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, unsigned int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, unsigned long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, unsigned long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, std::string)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, std::wstring)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QBrush)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QColor)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QFont)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QMatrix)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QObject)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QPoint)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QRect)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QRegExp)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QRegion)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QSize)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QStringList)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QUrl)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QImage)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QPicture)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromString, QPixmap)

QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, qx::trait::no_type)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QString)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QDate)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QDateTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QByteArray)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QVariant)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, qx_bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, char)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, float)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, double)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, unsigned short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, unsigned int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, unsigned long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, unsigned long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, std::string)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, std::wstring)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QBrush)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QColor)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QFont)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QMatrix)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QObject)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QPoint)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QRect)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QRegExp)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QRegion)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QSize)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QStringList)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QUrl)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QImage)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QPicture)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_ToVariant, QPixmap)

QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, qx::trait::no_type)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QString)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QDate)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QDateTime)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QByteArray)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QVariant)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, qx_bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, bool)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, char)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, float)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, double)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, unsigned short)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, unsigned int)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, unsigned long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, unsigned long long)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, std::string)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, std::wstring)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QBrush)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QColor)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QFont)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QMatrix)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QObject)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QPoint)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QRect)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QRegExp)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QRegion)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QSize)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QStringList)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QUrl)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QImage)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QPicture)
QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(struct, qx::cvt::detail::QxStringCvt_FromVariant, QPixmap)

#endif // _QX_USE_QX_STRING_CVT_EXPORT
#endif // _QX_STRING_CVT_EXPORT_H_
