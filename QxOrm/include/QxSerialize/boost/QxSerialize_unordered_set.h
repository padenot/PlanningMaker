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

#ifndef _QX_SERIALIZATION_BOOST_UNORDERED_SET_H_
#define _QX_SERIALIZATION_BOOST_UNORDERED_SET_H_

#ifdef _MSC_VER
#pragma once
#endif

#include <boost/unordered_set.hpp>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/collections_save_imp.hpp>
#include <boost/serialization/collections_load_imp.hpp>
#include <boost/serialization/split_free.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/nvp.hpp>

namespace boost {
namespace serialization {

template <class Archive, class Key>
inline void save(Archive & ar, const boost::unordered_set<Key> & t, const unsigned int /* file_version */)
{
   boost::serialization::stl::save_collection< Archive, boost::unordered_set<Key> >(ar, t);
}

template <class Archive, class Key>
inline void load(Archive & ar, boost::unordered_set<Key> & t, const unsigned int /* file_version */)
{
   boost::serialization::stl::load_collection< Archive, boost::unordered_set<Key>,
      boost::serialization::stl::archive_input_set< Archive, boost::unordered_set<Key> >,
      boost::serialization::stl::no_reserve_imp<boost::unordered_set< Key > > >(ar, t);
}

template <class Archive, class Key>
inline void serialize(Archive & ar, boost::unordered_set<Key> & t, const unsigned int file_version)
{
   boost::serialization::split_free(ar, t, file_version);
}

template <class Archive, class Key>
inline void save(Archive & ar, const boost::unordered_multiset<Key> & t, const unsigned int /* file_version */)
{
   boost::serialization::stl::save_collection< Archive, boost::unordered_multiset<Key> >(ar, t);
}

template <class Archive, class Key>
inline void load(Archive & ar, boost::unordered_multiset<Key> & t, const unsigned int /* file_version */)
{
#if (BOOST_VERSION >= 104200)
   boost::serialization::stl::load_collection< Archive, boost::unordered_multiset<Key>,
      boost::serialization::stl::archive_input_set< Archive, boost::unordered_multiset<Key> >,
      boost::serialization::stl::no_reserve_imp< boost::unordered_multiset<Key> > >(ar, t);
#else // (BOOST_VERSION >= 104200)
   boost::serialization::stl::load_collection< Archive, boost::unordered_multiset<Key>,
      boost::serialization::stl::archive_input_multiset< Archive, boost::unordered_multiset<Key> >,
      boost::serialization::stl::no_reserve_imp< boost::unordered_multiset<Key> > >(ar, t);
#endif // (BOOST_VERSION >= 104200)
}

template <class Archive, class Key>
inline void serialize(Archive & ar, boost::unordered_multiset<Key> & t, const unsigned int file_version)
{
   boost::serialization::split_free(ar, t, file_version);
}

} // namespace serialization
} // namespace boost

#endif // _QX_SERIALIZATION_BOOST_UNORDERED_SET_H_
