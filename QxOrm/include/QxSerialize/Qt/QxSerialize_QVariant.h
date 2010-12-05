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

#ifndef _QX_SERIALIZE_QVARIANT_H_
#define _QX_SERIALIZE_QVARIANT_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/version.hpp>
#include <boost/serialization/nvp.hpp>

#include <QtCore/qvariant.h>

#include <QxSerialize/Qt/QxSerialize_QString.h>
#include <QxSerialize/Qt/QxSerialize_QDate.h>
#include <QxSerialize/Qt/QxSerialize_QDateTime.h>
#include <QxSerialize/Qt/QxSerialize_QTime.h>
#include <QxSerialize/Qt/QxSerialize_QByteArray.h>
#include <QxSerialize/Qt/QxSerialize_QBrush.h>
#include <QxSerialize/Qt/QxSerialize_QColor.h>
#include <QxSerialize/Qt/QxSerialize_QFont.h>
#include <QxSerialize/Qt/QxSerialize_QImage.h>
#include <QxSerialize/Qt/QxSerialize_QPixmap.h>
#include <QxSerialize/Qt/QxSerialize_QPoint.h>
#include <QxSerialize/Qt/QxSerialize_QRect.h>
#include <QxSerialize/Qt/QxSerialize_QRegExp.h>
#include <QxSerialize/Qt/QxSerialize_QRegion.h>
#include <QxSerialize/Qt/QxSerialize_QSize.h>
#include <QxSerialize/Qt/QxSerialize_QUrl.h>

#include <QxSerialize/QxSerializeFastCompil.h>

BOOST_CLASS_VERSION(QVariant, 0)

QX_SERIALIZE_FAST_COMPIL_SAVE_LOAD_HPP(QX_DLL_EXPORT, QVariant)

#endif // _QX_SERIALIZE_QVARIANT_H_
