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
struct QxDao_Save_Generic
{

   static QSqlError save(T & t, QSqlDatabase * pDatabase)
   {
      qx::dao::detail::QxDao_Helper<T> dao(t, pDatabase, "save");
      if (! dao.isValid()) { return dao.error(); }
      if (! pDatabase) { dao.transaction(); }
      dao.quiet();

      qx_bool bExist = dao.isValidPrimaryKey(t);
      if (bExist) { bExist = qx::dao::exist(t, (& dao.database())); }
      if (bExist) { dao.updateError(qx::dao::update(t, (& dao.database()))); }
      else { dao.updateError(qx::dao::insert(t, (& dao.database()))); }

      return dao.error();
   }

};

template <class T>
struct QxDao_Save_Container
{

   static QSqlError save(T & t, QSqlDatabase * pDatabase)
   {
      if (qx::trait::generic_container<T>::size(t) <= 0) { return QSqlError(); }
      qx::dao::detail::QxDao_Helper_Container<T> dao(t, pDatabase, "save");
      if (! dao.isValid()) { return dao.error(); }
      if (! pDatabase) { dao.transaction(); }
      dao.quiet();

      for (typename T::iterator it = t.begin(); it != t.end(); ++it)
      { if (! saveItem((* it), dao)) { return dao.error(); } }

      return dao.error();
   }

private:

   template <typename U>
   static inline bool saveItem(U & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
   { return saveItem_Helper<U, boost::is_pointer<U>::value || qx::trait::is_smart_ptr<U>::value>::save(item, dao); }

   template <typename U, bool bIsPointer /* = true */>
   struct saveItem_Helper
   {
      static inline bool save(U & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      { return (item ? qx::dao::detail::QxDao_Save_Container<T>::saveItem((* item), dao) : false); }
   };

   template <typename U1, typename U2>
   struct saveItem_Helper<std::pair<U1, U2>, false>
   {
      static inline bool save(std::pair<U1, U2> & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      { return qx::dao::detail::QxDao_Save_Container<T>::saveItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct saveItem_Helper<const std::pair<U1, U2>, false>
   {
      static inline bool save(const std::pair<U1, U2> & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      { return qx::dao::detail::QxDao_Save_Container<T>::saveItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct saveItem_Helper<QPair<U1, U2>, false>
   {
      static inline bool save(QPair<U1, U2> & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      { return qx::dao::detail::QxDao_Save_Container<T>::saveItem(item.second, dao); }
   };

   template <typename U1, typename U2>
   struct saveItem_Helper<const QPair<U1, U2>, false>
   {
      static inline bool save(const QPair<U1, U2> & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      { return qx::dao::detail::QxDao_Save_Container<T>::saveItem(item.second, dao); }
   };

   template <typename U>
   struct saveItem_Helper<U, false>
   {
      static bool save(U & item, qx::dao::detail::QxDao_Helper_Container<T> & dao)
      {
         qx_bool bExist = dao.isValidPrimaryKey(item);
         if (bExist) { bExist = qx::dao::exist(item, (& dao.database())); }
         if (bExist) { dao.updateError(qx::dao::update(item, (& dao.database()))); }
         else { dao.updateError(qx::dao::insert(item, (& dao.database()))); }

         return dao.isValid();
      }
   };

};

template <class T>
struct QxDao_Save_Ptr
{

   static inline QSqlError save(T & t, QSqlDatabase * pDatabase)
   { qAssert(t != NULL); return (t ? qx::dao::save((* t), pDatabase) : QSqlError()); }

};

template <class T>
struct QxDao_Save
{

   static inline QSqlError save(T & t, QSqlDatabase * pDatabase)
   {
      typedef typename boost::mpl::if_c< boost::is_pointer<T>::value, qx::dao::detail::QxDao_Save_Ptr<T>, qx::dao::detail::QxDao_Save_Generic<T> >::type type_dao_1;
      typedef typename boost::mpl::if_c< qx::trait::is_smart_ptr<T>::value, qx::dao::detail::QxDao_Save_Ptr<T>, type_dao_1 >::type type_dao_2;
      typedef typename boost::mpl::if_c< qx::trait::is_container<T>::value, qx::dao::detail::QxDao_Save_Container<T>, type_dao_2 >::type type_dao_3;
      return type_dao_3::save(t, pDatabase);
   }

};

} // namespace detail
} // namespace dao
} // namespace qx
