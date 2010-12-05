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

#ifndef _QX_HASH_VALUE_H_
#define _QX_HASH_VALUE_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <QtCore/qstring.h>
#include <QtCore/qdatetime.h>
#include <QtCore/qvariant.h>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>

inline std::size_t hash_value(const QString & s)      { return qHash(s); }
inline std::size_t hash_value(const QDate & d)        { return qHash(d.toJulianDay()); }
inline std::size_t hash_value(const QTime & t)        { return qHash(t.toString()); }
inline std::size_t hash_value(const QDateTime & dt)   { return qHash(dt.toString()); }
inline std::size_t hash_value(const QVariant & v)     { return qHash(v.toString()); }

template <typename T0, typename T1>
inline std::size_t hash_value(const boost::tuple<T0, T1> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   return seed;
}

template <typename T0, class T1, typename T2>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4, T5> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   boost::hash_combine(seed, boost::get<5>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4, T5, T6> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   boost::hash_combine(seed, boost::get<5>(tu));
   boost::hash_combine(seed, boost::get<6>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4, T5, T6, T7> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   boost::hash_combine(seed, boost::get<5>(tu));
   boost::hash_combine(seed, boost::get<6>(tu));
   boost::hash_combine(seed, boost::get<7>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   boost::hash_combine(seed, boost::get<5>(tu));
   boost::hash_combine(seed, boost::get<6>(tu));
   boost::hash_combine(seed, boost::get<7>(tu));
   boost::hash_combine(seed, boost::get<8>(tu));
   return seed;
}

template <typename T0, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
inline std::size_t hash_value(const boost::tuple<T0, T1, T2, T3, T4, T5, T6, T7, T8, T9> & tu)
{
   std::size_t seed = 0;
   boost::hash_combine(seed, boost::get<0>(tu));
   boost::hash_combine(seed, boost::get<1>(tu));
   boost::hash_combine(seed, boost::get<2>(tu));
   boost::hash_combine(seed, boost::get<3>(tu));
   boost::hash_combine(seed, boost::get<4>(tu));
   boost::hash_combine(seed, boost::get<5>(tu));
   boost::hash_combine(seed, boost::get<6>(tu));
   boost::hash_combine(seed, boost::get<7>(tu));
   boost::hash_combine(seed, boost::get<8>(tu));
   boost::hash_combine(seed, boost::get<9>(tu));
   return seed;
}

#endif // _QX_HASH_VALUE_H_
