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
namespace dao {
namespace detail {

template <class T>
struct QxDao_FetchById_WithRelation_Generic
{

   typedef qx::dao::detail::QxDao_Helper<T> type_dao_helper;
   typedef qx::dao::detail::QxSqlQueryHelper_FetchById_WithRelation<T> type_query_helper;

   static QSqlError fetchById(const QStringList & relation, T & t, QSqlDatabase * pDatabase)
   {
      type_dao_helper dao(t, pDatabase, "fetch by id with relation");
      if (! dao.isValid()) { return dao.error(); }
      if (! dao.isValidPrimaryKey(t)) { return dao.errInvalidId(); }
      if (! dao.updateSqlRelationX(relation)) { return dao.errInvalidRelation(); }

      QString sql = dao.builder().fetchById_WithRelation(dao.getSqlRelationX()).getSqlQuery();
      if (! dao.getDataId() || sql.isEmpty()) { return dao.errEmpty(); }

      dao.query().prepare(sql);
      type_query_helper::resolveInput(dao.getSqlRelationX(), t, dao.query(), dao.builder());
      if (! dao.query().exec()) { return dao.errFailed(); }

      if (dao.getCartesianProduct()) { fetchById_Complex(t, dao); }
      else { fetchById_Simple(t, dao); }

      return dao.error();
   }

private:

   static inline void fetchById_Simple(T & t, type_dao_helper & dao)
   {
      if (! dao.nextRecord()) { dao.errNoData(); return; }
      type_query_helper::resolveOutput(dao.getSqlRelationX(), t, dao.query(), dao.builder());
   }

   static inline void fetchById_Complex(T & t, type_dao_helper & dao)
   {
      while (dao.nextRecord())
      { type_query_helper::resolveOutput(dao.getSqlRelationX(), t, dao.query(), dao.builder()); }
   }

};

template <class T>
struct QxDao_FetchById_WithRelation_Container
{

   typedef qx::dao::detail::QxDao_Helper_Container<T> type_dao_helper;
   typedef qx::dao::detail::QxDao_FetchById_WithRelation_Container<T> type_this;

   static QSqlError fetchById(const QStringList & relation, T & t, QSqlDatabase * pDatabase)
   {
      if (qx::trait::generic_container<T>::size(t) <= 0) { return QSqlError(); }
      type_dao_helper dao(t, pDatabase, "fetch by id with relation");
      if (! dao.isValid()) { return dao.error(); }
      if (! dao.updateSqlRelationX(relation)) { return dao.errInvalidRelation(); }

      QString sql = dao.builder().fetchById_WithRelation(dao.getSqlRelationX()).getSqlQuery();
      if (! dao.getDataId() || sql.isEmpty()) { return dao.errEmpty(); }
      dao.query().prepare(sql);

      for (typename T::iterator it = t.begin(); it != t.end(); ++it)
      { if (! fetchItem((* it), dao)) { return dao.error(); } }

      return dao.error();
   }

private:

   template <typename U>
   static inline bool fetchItem(U & item, type_dao_helper & dao)
   { return fetchItem_Helper<U, boost::is_pointer<U>::value || qx::trait::is_smart_ptr<U>::value>::fetch(item, dao); }

   template <typename U, bool bIsPointer /* = true */>
   struct fetchItem_Helper
   {
      static inline bool fetch(U & item, type_dao_helper & dao)
      { return (item ? type_this::fetchItem((* item), dao) : true); }
   };

   template <typename U1, typename U2>
   struct fetchItem_Helper<std::pair<U1, U2>, false>
   {
      static inline bool fetch(std::pair<U1, U2> & item, type_dao_helper & dao)
      { return type_this::fetchItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct fetchItem_Helper<const std::pair<U1, U2>, false>
   {
      static inline bool fetch(const std::pair<U1, U2> & item, type_dao_helper & dao)
      { return type_this::fetchItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct fetchItem_Helper<QPair<U1, U2>, false>
   {
      static inline bool fetch(QPair<U1, U2> & item, type_dao_helper & dao)
      { return type_this::fetchItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct fetchItem_Helper<const QPair<U1, U2>, false>
   {
      static inline bool fetch(const QPair<U1, U2> & item, type_dao_helper & dao)
      { return type_this::fetchItem(item.second, dao); }
   };

   template <typename U>
   struct fetchItem_Helper<U, false>
   {

      typedef qx::dao::detail::QxSqlQueryHelper_FetchById_WithRelation<U> type_query_helper;

      static bool fetch(U & item, type_dao_helper & dao)
      {
         if (! dao.isValidPrimaryKey(item)) { dao.errInvalidId(); return false; }
         type_query_helper::resolveInput(dao.getSqlRelationX(), item, dao.query(), dao.builder());
         if (! dao.query().exec()) { dao.errFailed(); return false; }
         if (dao.getCartesianProduct()) { fetch_Complex(item, dao); }
         else { fetch_Simple(item, dao); }

         return dao.isValid();
      }

      static inline void fetch_Simple(U & item, type_dao_helper & dao)
      {
         if (! dao.nextRecord()) { dao.errNoData(); return; }
         type_query_helper::resolveOutput(dao.getSqlRelationX(), item, dao.query(), dao.builder());
      }

      static inline void fetch_Complex(U & item, type_dao_helper & dao)
      {
         while (dao.nextRecord())
         { type_query_helper::resolveOutput(dao.getSqlRelationX(), item, dao.query(), dao.builder()); }
      }

   };

};

template <class T>
struct QxDao_FetchById_WithRelation_Ptr
{

   static inline QSqlError fetchById(const QStringList & relation, T & t, QSqlDatabase * pDatabase)
   { if (! t) { qx::trait::construct_ptr<T>::get(t); }; return qx::dao::fetch_by_id_with_relation(relation, (* t), pDatabase); }

};

template <class T>
struct QxDao_FetchById_WithRelation
{

   static inline QSqlError fetchById(const QString & relation, T & t, QSqlDatabase * pDatabase)
   { return QxDao_FetchById_WithRelation<T>::fetchById((relation.isEmpty() ? QStringList() : (QStringList() << relation)), t, pDatabase); }

   static inline QSqlError fetchById(const QStringList & relation, T & t, QSqlDatabase * pDatabase)
   {
      typedef typename boost::mpl::if_c< boost::is_pointer<T>::value, qx::dao::detail::QxDao_FetchById_WithRelation_Ptr<T>, qx::dao::detail::QxDao_FetchById_WithRelation_Generic<T> >::type type_dao_1;
      typedef typename boost::mpl::if_c< qx::trait::is_smart_ptr<T>::value, qx::dao::detail::QxDao_FetchById_WithRelation_Ptr<T>, type_dao_1 >::type type_dao_2;
      typedef typename boost::mpl::if_c< qx::trait::is_container<T>::value, qx::dao::detail::QxDao_FetchById_WithRelation_Container<T>, type_dao_2 >::type type_dao_3;
      return type_dao_3::fetchById(relation, t, pDatabase);
   }

};

} // namespace detail
} // namespace dao
} // namespace qx
