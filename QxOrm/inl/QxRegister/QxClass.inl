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

namespace qx {

template <class T>
void QxClass<T>::init()
{
   m_pDataMemberX = QxDataMemberX<T>::getSingleton();
   m_pDataMemberX->setClass(this);
   m_pFctMemberX.reset(new IxFunctionX());
   m_lVersion = boost::serialization::version<T>::value;
   m_sKey = qx::trait::get_class_name<T>::get();
   m_sKeyBaseClass = qx::trait::get_class_name<typename QxClass<T>::type_base_class>::get();
   this->setName(qx::trait::get_class_name<T>::get_xml_tag());
   this->updateClassX();
   beforeRegisterClass();
}

template <class T>
template <typename V>
IxDataMember * QxClass<T>::data(V T::* pData, const QString & sKey, long lVersion, bool bSerialize, bool bDao)
{ return this->dataMemberX()->add(pData, sKey, lVersion, bSerialize, bDao); }

template <class T>
template <typename V>
IxDataMember * QxClass<T>::data(V T::* pData, const QString & sKey, long lVersion, bool bSerialize)
{ return this->dataMemberX()->add(pData, sKey, lVersion, bSerialize); }

template <class T>
template <typename V>
IxDataMember * QxClass<T>::data(V T::* pData, const QString & sKey, long lVersion)
{ return this->dataMemberX()->add(pData, sKey, lVersion); }

template <class T>
template <typename V>
IxDataMember * QxClass<T>::data(V T::* pData, const QString & sKey)
{ return this->dataMemberX()->add(pData, sKey); }

template <class T>
IxDataMember * QxClass<T>::id(typename QxClass<T>::type_primary_key T::* pDataMemberId, const QString & sKey)
{ return this->dataMemberX()->id(pDataMemberId, sKey); }

template <class T>
IxDataMember * QxClass<T>::id(typename QxClass<T>::type_primary_key T::* pDataMemberId, const QString & sKey, long lVersion)
{ return this->dataMemberX()->id(pDataMemberId, sKey, lVersion); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationOneToOne(V T::* pData, const QString & sKey)
{ return this->dataMemberX()->relationOneToOne(pData, sKey); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationOneToOne(V T::* pData, const QString & sKey, long lVersion)
{ return this->dataMemberX()->relationOneToOne(pData, sKey, lVersion); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationManyToOne(V T::* pData, const QString & sKey)
{ return this->dataMemberX()->relationManyToOne(pData, sKey); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationManyToOne(V T::* pData, const QString & sKey, long lVersion)
{ return this->dataMemberX()->relationManyToOne(pData, sKey, lVersion); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationOneToMany(V T::* pData, const QString & sKey, const QString & sForeignKey)
{ return this->dataMemberX()->relationOneToMany(pData, sKey, sForeignKey); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationOneToMany(V T::* pData, const QString & sKey, const QString & sForeignKey, long lVersion)
{ return this->dataMemberX()->relationOneToMany(pData, sKey, sForeignKey, lVersion); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationManyToMany(V T::* pData, const QString & sKey, const QString & sExtraTable, const QString & sForeignKeyOwner, const QString & sForeignKeyDataType)
{ return this->dataMemberX()->relationManyToMany(pData, sKey, sExtraTable, sForeignKeyOwner, sForeignKeyDataType); }

template <class T>
template <typename V>
IxSqlRelation * QxClass<T>::relationManyToMany(V T::* pData, const QString & sKey, const QString & sExtraTable, const QString & sForeignKeyOwner, const QString & sForeignKeyDataType, long lVersion)
{ return this->dataMemberX()->relationManyToMany(pData, sKey, sExtraTable, sForeignKeyOwner, sForeignKeyDataType, lVersion); }

template <class T>
IxFunction * QxClass<T>::insertFct(IxFunction_ptr pFct, const QString & sKey)
{
   if (! m_pFctMemberX || sKey.isEmpty() || m_pFctMemberX->exist(sKey)) { qAssert(false); return NULL; }
   bool bInsertOk = m_pFctMemberX->insert(sKey, pFct);
   return (bInsertOk ? pFct.get() : NULL);
}

template <class T>
template <typename R>
IxFunction * QxClass<T>::fct_0(const typename QxFunction_0<T, R>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_0<T, R>(fct), sKey); }

template <class T>
template <typename R, typename P1>
IxFunction * QxClass<T>::fct_1(const typename QxFunction_1<T, R, P1>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_1<T, R, P1>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2>
IxFunction * QxClass<T>::fct_2(const typename QxFunction_2<T, R, P1, P2>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_2<T, R, P1, P2>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3>
IxFunction * QxClass<T>::fct_3(const typename QxFunction_3<T, R, P1, P2, P3>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_3<T, R, P1, P2, P3>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4>
IxFunction * QxClass<T>::fct_4(const typename QxFunction_4<T, R, P1, P2, P3, P4>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_4<T, R, P1, P2, P3, P4>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5>
IxFunction * QxClass<T>::fct_5(const typename QxFunction_5<T, R, P1, P2, P3, P4, P5>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_5<T, R, P1, P2, P3, P4, P5>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6>
IxFunction * QxClass<T>::fct_6(const typename QxFunction_6<T, R, P1, P2, P3, P4, P5, P6>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_6<T, R, P1, P2, P3, P4, P5, P6>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7>
IxFunction * QxClass<T>::fct_7(const typename QxFunction_7<T, R, P1, P2, P3, P4, P5, P6, P7>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_7<T, R, P1, P2, P3, P4, P5, P6, P7>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8>
IxFunction * QxClass<T>::fct_8(const typename QxFunction_8<T, R, P1, P2, P3, P4, P5, P6, P7, P8>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_8<T, R, P1, P2, P3, P4, P5, P6, P7, P8>(fct), sKey); }

template <class T>
template <typename R, typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7, typename P8, typename P9>
IxFunction * QxClass<T>::fct_9(const typename QxFunction_9<T, R, P1, P2, P3, P4, P5, P6, P7, P8, P9>::type_fct & fct, const QString & sKey)
{ return this->insertFct(qx::function::bind_member_fct_9<T, R, P1, P2, P3, P4, P5, P6, P7, P8, P9>(fct), sKey); }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
QxClass<qx::trait::no_base_class_defined>::QxClass() : IxClass(), QxSingleton< QxClass<qx::trait::no_base_class_defined> >("qx::QxClass_no_base_class_defined") { setName("qx::trait::no_base_class_defined"); m_bFinalClass = true; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
QxClass<QObject>::QxClass() : IxClass(), QxSingleton< QxClass<QObject> >("qx::QxClass_QObject") { setName("QObject"); m_bFinalClass = true; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
void QxClass<qx::trait::no_base_class_defined>::registerClass() { ; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
void QxClass<QObject>::registerClass() { ; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
void QxClass<qx::trait::no_base_class_defined>::beforeRegisterClass() { ; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
void QxClass<QObject>::beforeRegisterClass() { ; }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
qx_bool QxClass<qx::trait::no_base_class_defined>::invokeHelper(const QString & sKey, qx::trait::no_base_class_defined * pOwner, const QString & params, boost::any * ret)
{ Q_UNUSED(sKey); Q_UNUSED(pOwner); Q_UNUSED(params); Q_UNUSED(ret); return qx_bool(false); }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
qx_bool QxClass<QObject>::invokeHelper(const QString & sKey, QObject * pOwner, const QString & params, boost::any * ret)
{ Q_UNUSED(sKey); Q_UNUSED(pOwner); Q_UNUSED(params); Q_UNUSED(ret); return qx_bool(false); }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
qx_bool QxClass<qx::trait::no_base_class_defined>::invokeHelper(const QString & sKey, qx::trait::no_base_class_defined * pOwner, const type_any_params & params, boost::any * ret)
{ Q_UNUSED(sKey); Q_UNUSED(pOwner); Q_UNUSED(params); Q_UNUSED(ret); return qx_bool(false); }

template <> QX_GCC_WORKAROUND_TEMPLATE_SPEC_INLINE
qx_bool QxClass<QObject>::invokeHelper(const QString & sKey, QObject * pOwner, const type_any_params & params, boost::any * ret)
{ Q_UNUSED(sKey); Q_UNUSED(pOwner); Q_UNUSED(params); Q_UNUSED(ret); return qx_bool(false); }

} // namespace qx
