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

#ifndef _QX_MACRO_H_
#define _QX_MACRO_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <QxCommon/QxConfig.h>

#ifndef qAssert
#if _QX_USE_ASSERT
#define qAssert Q_ASSERT
#else // _QX_USE_ASSERT
#define qAssert(x) /* Nothing */
#endif // _QX_USE_ASSERT
#endif // qAssert

#ifndef QX_PRAGMA
#ifdef __GNUC__
#define QX_PRAGMA(x) _Pragma( #x )
#endif // __GNUC__
#ifdef _MSC_VER
#define QX_PRAGMA(x) __pragma( x )
#endif // _MSC_VER
#ifndef QX_PRAGMA
#define QX_PRAGMA(x) /* Nothing */
#endif // QX_PRAGMA
#endif // QX_PRAGMA

#ifndef QX_DLL_EXPORT_HELPER
#ifdef Q_OS_WIN
#define QX_DLL_EXPORT_HELPER __declspec(dllexport)
#elif (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#define QX_DLL_EXPORT_HELPER __attribute__ ((visibility("default")))
#else
#define QX_DLL_EXPORT_HELPER /* Nothing */
#endif // Q_OS_WIN
#endif // QX_DLL_EXPORT_HELPER

#ifndef QX_DLL_IMPORT_HELPER
#ifdef Q_OS_WIN
#define QX_DLL_IMPORT_HELPER __declspec(dllimport)
#elif (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#define QX_DLL_IMPORT_HELPER __attribute__ ((visibility("default")))
#else
#define QX_DLL_IMPORT_HELPER /* Nothing */
#endif // Q_OS_WIN
#endif // QX_DLL_IMPORT_HELPER

#ifdef __GNUC__
#if _QX_USE_GCC_EXPORT_ALL_SYMBOLS
#undef QX_DLL_EXPORT_HELPER
#undef QX_DLL_IMPORT_HELPER
#define QX_DLL_EXPORT_HELPER /* Nothing */
#define QX_DLL_IMPORT_HELPER /* Nothing */
#endif // _QX_USE_GCC_EXPORT_ALL_SYMBOLS
#endif // __GNUC__

#ifndef QX_DLL_INTERNAL_HELPER
#if (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#define QX_DLL_INTERNAL_HELPER __attribute__ ((visibility("hidden")))
#else
#define QX_DLL_INTERNAL_HELPER /* Nothing */
#endif // (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#endif // QX_DLL_INTERNAL_HELPER

#ifndef QX_DLL_EXPORT_TEMPLATE_HELPER
#ifdef _MSC_VER
#define QX_DLL_EXPORT_TEMPLATE_HELPER QX_DLL_EXPORT_HELPER
#else // _MSC_VER
#define QX_DLL_EXPORT_TEMPLATE_HELPER /* Nothing */
#endif // _MSC_VER
#endif // QX_DLL_EXPORT_TEMPLATE_HELPER

#ifndef QX_DLL_IMPORT_TEMPLATE_HELPER
#ifdef _MSC_VER
#define QX_DLL_IMPORT_TEMPLATE_HELPER QX_DLL_IMPORT_HELPER
#else // _MSC_VER
#define QX_DLL_IMPORT_TEMPLATE_HELPER /* Nothing */
#endif // _MSC_VER
#endif // QX_DLL_IMPORT_TEMPLATE_HELPER

#ifndef QX_PRAGMA_VISIBILITY_BEGIN
#ifndef Q_OS_WIN
#if (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#define QX_PRAGMA_VISIBILITY_BEGIN QX_PRAGMA(GCC visibility push( default ))
#endif // (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#endif // Q_OS_WIN
#ifndef QX_PRAGMA_VISIBILITY_BEGIN
#define QX_PRAGMA_VISIBILITY_BEGIN /* Nothing */
#endif // QX_PRAGMA_VISIBILITY_BEGIN
#endif // QX_PRAGMA_VISIBILITY_BEGIN

#ifndef QX_PRAGMA_VISIBILITY_END
#ifndef Q_OS_WIN
#if (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#define QX_PRAGMA_VISIBILITY_END QX_PRAGMA(GCC visibility pop)
#endif // (_QX_USE_GCC_VISIBILITY && (__GNUC__ >= 4))
#endif // Q_OS_WIN
#ifndef QX_PRAGMA_VISIBILITY_END
#define QX_PRAGMA_VISIBILITY_END /* Nothing */
#endif // QX_PRAGMA_VISIBILITY_END
#endif // QX_PRAGMA_VISIBILITY_END

#define QX_DLL_EXPORT_TEMPLATE_HPP(CL, T) QX_PRAGMA_VISIBILITY_BEGIN extern template CL QX_DLL_IMPORT_TEMPLATE_HELPER T; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_P1_HPP(CL, T, P1) QX_PRAGMA_VISIBILITY_BEGIN extern template CL QX_DLL_IMPORT_TEMPLATE_HELPER T< P1 >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_U_P1_HPP(CL, T, U, P1) QX_PRAGMA_VISIBILITY_BEGIN extern template CL QX_DLL_IMPORT_TEMPLATE_HELPER T< U< P1 > >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_P1_P2_HPP(CL, T, P1, P2) QX_PRAGMA_VISIBILITY_BEGIN extern template CL QX_DLL_IMPORT_TEMPLATE_HELPER T< P1, P2 >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_U_P1_P2_HPP(CL, T, U, P1, P2) QX_PRAGMA_VISIBILITY_BEGIN extern template CL QX_DLL_IMPORT_TEMPLATE_HELPER T< U< P1, P2 > >; QX_PRAGMA_VISIBILITY_END

#define QX_DLL_EXPORT_TEMPLATE_CPP(CL, T) QX_PRAGMA_VISIBILITY_BEGIN template CL QX_DLL_EXPORT_TEMPLATE_HELPER T; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_P1_CPP(CL, T, P1) QX_PRAGMA_VISIBILITY_BEGIN template CL QX_DLL_EXPORT_TEMPLATE_HELPER T< P1 >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_U_P1_CPP(CL, T, U, P1) QX_PRAGMA_VISIBILITY_BEGIN template CL QX_DLL_EXPORT_TEMPLATE_HELPER T< U< P1 > >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_P1_P2_CPP(CL, T, P1, P2) QX_PRAGMA_VISIBILITY_BEGIN template CL QX_DLL_EXPORT_TEMPLATE_HELPER T< P1, P2 >; QX_PRAGMA_VISIBILITY_END
#define QX_DLL_EXPORT_TEMPLATE_T_U_P1_P2_CPP(CL, T, U, P1, P2) QX_PRAGMA_VISIBILITY_BEGIN template CL QX_DLL_EXPORT_TEMPLATE_HELPER T< U< P1, P2 > >; QX_PRAGMA_VISIBILITY_END

#define QX_TEMPLATE_T(T) T<>
#define QX_TEMPLATE_T_P1(T, P1) T< P1 >
#define QX_TEMPLATE_T_P1_P2(T, P1, P2) T< P1, P2 >
#define QX_TEMPLATE_T_P1_P2_P3(T, P1, P2, P3) T< P1, P2, P3 >
#define QX_TEMPLATE_T_U_P1(T, U, P1) T< U< P1 > >
#define QX_TEMPLATE_T_U_P1_P2(T, U, P1, P2) T< U< P1, P2 > >
#define QX_TEMPLATE_T_U_P1_P2_P3(T, U, P1, P2, P3) T< U< P1, P2, P3 > >

#ifndef QX_DLL_EXPORT
#ifdef _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT QX_DLL_EXPORT_HELPER
#else // _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT QX_DLL_IMPORT_HELPER
#endif // _QX_BUILDING_QX_ORM
#endif // QX_DLL_EXPORT

#ifndef QX_DLL_EXPORT_QX_SINGLETON_HPP
#ifdef _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT_QX_SINGLETON_HPP(x) /* Nothing */
#else // _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT_QX_SINGLETON_HPP(x) QX_DLL_EXPORT_TEMPLATE_HPP(class, qx::QxSingleton< x >)
#endif // _QX_BUILDING_QX_ORM
#endif // QX_DLL_EXPORT_QX_SINGLETON_HPP

#ifndef QX_DLL_EXPORT_QX_SINGLETON_CPP
#ifdef _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT_QX_SINGLETON_CPP(x) QX_DLL_EXPORT_TEMPLATE_CPP(class, qx::QxSingleton< x >)
#else // _QX_BUILDING_QX_ORM
#define QX_DLL_EXPORT_QX_SINGLETON_CPP(x) /* Nothing */
#endif // _QX_BUILDING_QX_ORM
#endif // QX_DLL_EXPORT_QX_SINGLETON_CPP

#ifndef QX_DLL_EXPORT_INLINE_FCT
#ifdef _MSC_VER
#define QX_DLL_EXPORT_INLINE_FCT QX_DLL_EXPORT
#else // _MSC_VER
#define QX_DLL_EXPORT_INLINE_FCT /* Nothing */
#endif // _MSC_VER
#endif // QX_DLL_EXPORT_INLINE_FCT

#ifdef __GNUC__
#define QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE inline
#else
#define QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE /* Nothing */
#endif // __GNUC__

#ifdef _MSC_VER
#define QX_STRNCPY strncpy_s
#define QX_VSPRINTF vsprintf_s
#else // _MSC_VER
#define QX_STRNCPY strncpy
#define QX_VSPRINTF vsprintf
#endif // _MSC_VER

#endif // _QX_MACRO_H_
