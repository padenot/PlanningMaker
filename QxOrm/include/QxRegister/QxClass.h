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

#ifndef _QX_CLASS_H_
#define _QX_CLASS_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/serialization/version.hpp>

#include <QxRegister/IxClass.h>

#include <QxDataMember/QxDataMemberX.h>

#include <QxFunction/QxFunctionInclude.h>

#include <QxSingleton/QxSingleton.h>

#include <QxTraits/get_class_name.h>
#include <QxTraits/get_base_class.h>
#include <QxTraits/get_primary_key.h>

namespace qx {

template <class T>
void register_class(T & t) { Q_UNUSED(t); qAssert(false); };

template <class T>
class QxClass : public IxClass, public QxSingleton< QxClass<T> >
{

   friend class QxSingleton< QxClass<T> >;

public:

   typedef typename qx::trait::get_primary_key<T>::type type_primary_key;
   typedef typename qx::trait::get_base_class<T>::type type_base_class;
   typedef IxFunction::type_any_params type_any_params;

   enum { is_valid_base_class = ((! boost::is_same<type_base_class, T>::value) && (boost::is_base_of<type_base_class, T>::value || boost::is_same<type_base_class, qx::trait::no_base_class_defined>::value)) };

protected:

   QMutex m_oMutexClass;   // Mutex -> 'QxClass' is thread-safe

protected:

   QxClass() : IxClass(), QxSingleton< QxClass<T> >(QString("qx::QxClass_") + qx::trait::get_class_name<T>::get_xml_tag()) { init(); }
   virtual ~QxClass() { ; }

public:

   inline QxDataMemberX<T> * dataMemberX() const   { return static_cast<QxDataMemberX<T> *>(m_pDataMemberX); }
   inline IxFunctionX * fctMemberX() const         { return m_pFctMemberX.get(); }

   IxDataMember * id(type_primary_key T::* pDataMemberId, const QString & sKey);
   IxDataMember * id(type_primary_key T::* pDataMemberId, const QString & sKey, long lVersion);

   template <typename V> IxDataMember * data(V T::* pData, const QString & sKey);
   template <typename V> IxDataMember * data(V T::* pData, const QString & sKey, long lVersion);
   template <typename V> IxDataMember * data(V T::* pData, const QString & sKey, long lVersion, bool bSerialize);
   template <typename V> IxDataMember * data(V T::* pData, const QString & sKey, long lVersion, bool bSerialize, bool bDao);

   template <typename V> IxSqlRelation * relationOneToOne(V T::* pData, const QString & sKey);
   template <typename V> IxSqlRelation * relationOneToOne(V T::* pData, const QString & sKey, long lVersion);
   template <typename V> IxSqlRelation * relationManyToOne(V T::* pData, const QString & sKey);
   template <typename V> IxSqlRelation * relationManyToOne(V T::* pData, const QString & sKey, long lVersion);
   template <typename V> IxSqlRelation * relationOneToMany(V T::* pData, const QString & sKey, const QString & sForeignKey);
   template <typename V> IxSqlRelation * relationOneToMany(V T::* pData, const QString & sKey, const QString & sForeignKey, long lVersion);
   template <typename V> IxSqlRelation * relationManyToMany(V T::* pData, const QString & sKey, const QString & sExtraTable, const QString & sForeignKeyOwner, const QString & sForeignKeyDataType);
   template <typename V> IxSqlRelation * relationManyToMany(V T::* pData, const QString & sKey, const QString & sExtraTable, const QString & sForeignKeyOwner, const QString & sForeignKeyDataType, long lVersion);

   template <typename R> IxFunction * fct_0(const typename QxFunction_0<T, R>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1> IxFunction * fct_1(const typename QxFunction_1<T, R, P1>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2> IxFunction * fct_2(const typename QxFunction_2<T, R, P1, P2>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3> IxFunction * fct_3(const typename QxFunction_3<T, R, P1, P2, P3>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4> IxFunction * fct_4(const typename QxFunction_4<T, R, P1, P2, P3, P4>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5> IxFunction * fct_5(const typename QxFunction_5<T, R, P1, P2, P3, P4, P5>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6> IxFunction * fct_6(const typename QxFunction_6<T, R, P1, P2, P3, P4, P5, P6>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7> IxFunction * fct_7(const typename QxFunction_7<T, R, P1, P2, P3, P4, P5, P6, P7>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8> IxFunction * fct_8(const typename QxFunction_8<T, R, P1, P2, P3, P4, P5, P6, P7, P8>::type_fct & fct, const QString & sKey);
   template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9> IxFunction * fct_9(const typename QxFunction_9<T, R, P1, P2, P3, P4, P5, P6, P7, P8, P9>::type_fct & fct, const QString & sKey);

   static qx_bool invoke(const QString & sKey, T * pOwner, const QString & params = QString(), boost::any * ret = NULL) { return QxClass<T>::getSingleton()->invokeHelper(sKey, pOwner, params, ret); }
   static qx_bool invoke(const QString & sKey, T * pOwner, const type_any_params & params, boost::any * ret = NULL)     { return QxClass<T>::getSingleton()->invokeHelper(sKey, pOwner, params, ret); }

private:

   void init();
   IxFunction * insertFct(IxFunction_ptr pFct, const QString & sKey);

   void registerClass() { qx::register_class(* this); }

   void beforeRegisterClass()
   {
      BOOST_STATIC_ASSERT(is_valid_base_class);
      QMutexLocker locker(& m_oMutexClass);
      QxClass<type_base_class>::getSingleton();
      bool bNeedReg = (m_pDataMemberX && (m_pDataMemberX->count() <= 0));
      bNeedReg = (bNeedReg && m_pFctMemberX && (m_pFctMemberX->count() <= 0));
      if (bNeedReg) { registerClass(); }
   }

   qx_bool invokeHelper(const QString & sKey, T * pOwner, const QString & params, boost::any * ret)
   { return ((pOwner && m_pFctMemberX && m_pFctMemberX->exist(sKey)) ? m_pFctMemberX->getByKey(sKey)->invoke(pOwner, params, ret) : QxClass<type_base_class>::invoke(sKey, dynamic_cast<type_base_class *>(pOwner), params, ret)); }

   qx_bool invokeHelper(const QString & sKey, T * pOwner, const type_any_params & params, boost::any * ret)
   { return ((pOwner && m_pFctMemberX && m_pFctMemberX->exist(sKey)) ? m_pFctMemberX->getByKey(sKey)->invoke(pOwner, params, ret) : QxClass<type_base_class>::invoke(sKey, dynamic_cast<type_base_class *>(pOwner), params, ret)); }

};

} // namespace qx

#include "../../inl/QxRegister/QxClass.inl"

#endif // _QX_CLASS_H_
