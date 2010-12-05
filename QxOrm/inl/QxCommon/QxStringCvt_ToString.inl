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
namespace cvt {
namespace detail {

template <> struct QxStringCvt_ToString< qx::trait::no_type > {
static inline QString toString(const qx::trait::no_type & t, const QString & format)
{ Q_UNUSED(t); Q_UNUSED(format); return ""; } };

template <> struct QxStringCvt_ToString< QString > {
static inline QString toString(const QString & t, const QString & format)
{ Q_UNUSED(format); return t; } };

template <> struct QxStringCvt_ToString< QDate > {
static inline QString toString(const QDate & t, const QString & format)
{ return t.toString(format.isEmpty() ? QX_STR_CVT_QDATE_FORMAT : format); } };

template <> struct QxStringCvt_ToString< QTime > {
static inline QString toString(const QTime & t, const QString & format)
{ return t.toString(format.isEmpty() ? QX_STR_CVT_QTIME_FORMAT : format); } };

template <> struct QxStringCvt_ToString< QDateTime > {
static inline QString toString(const QDateTime & t, const QString & format)
{ return t.toString(format.isEmpty() ? QX_STR_CVT_QDATETIME_FORMAT : format); } };

template <> struct QxStringCvt_ToString< QByteArray > {
static inline QString toString(const QByteArray & t, const QString & format)
{ Q_UNUSED(format); return QString(t); } };

template <> struct QxStringCvt_ToString< QVariant > {
static inline QString toString(const QVariant & t, const QString & format)
{ Q_UNUSED(format); return t.toString(); } };

template <> struct QxStringCvt_ToString< qx_bool > {
static inline QString toString(const qx_bool & t, const QString & format)
{ Q_UNUSED(format); return (t ? "1" : "0"); } };

template <> struct QxStringCvt_ToString< bool > {
static inline QString toString(const bool & t, const QString & format)
{ Q_UNUSED(format); return (t ? "1" : "0"); } };

template <> struct QxStringCvt_ToString< char > {
static inline QString toString(const char & t, const QString & format)
{ Q_UNUSED(format); return QString(t); } };

template <> struct QxStringCvt_ToString< short > {
static inline QString toString(const short & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< int > {
static inline QString toString(const int & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< long > {
static inline QString toString(const long & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< long long > {
static inline QString toString(const long long & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< float > {
static inline QString toString(const float & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< double > {
static inline QString toString(const double & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< unsigned short > {
static inline QString toString(const unsigned short & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< unsigned int > {
static inline QString toString(const unsigned int & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< unsigned long > {
static inline QString toString(const unsigned long & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< unsigned long long > {
static inline QString toString(const unsigned long long & t, const QString & format)
{ return (format.isEmpty() ? QString::number(t) : QString().sprintf(qPrintable(format), t)); } };

template <> struct QxStringCvt_ToString< std::string > {
static inline QString toString(const std::string & t, const QString & format)
{ Q_UNUSED(format); return QString::fromStdString(t); } };

template <> struct QxStringCvt_ToString< std::wstring > {
static inline QString toString(const std::wstring & t, const QString & format)
{ Q_UNUSED(format); return QString::fromStdWString(t); } };

template <typename T1, typename T2> struct QxStringCvt_ToString< std::pair<T1, T2> > {
static inline QString toString(const std::pair<T1, T2> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2> struct QxStringCvt_ToString< QPair<T1, T2> > {
static inline QString toString(const QPair<T1, T2> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< std::vector<T> > {
static inline QString toString(const std::vector<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< std::list<T> > {
static inline QString toString(const std::list<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< std::set<T> > {
static inline QString toString(const std::set<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< boost::unordered_set<T> > {
static inline QString toString(const boost::unordered_set<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< boost::unordered_multiset<T> > {
static inline QString toString(const boost::unordered_multiset<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< QVector<T> > {
static inline QString toString(const QVector<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< QList<T> > {
static inline QString toString(const QList<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T> struct QxStringCvt_ToString< QLinkedList<T> > {
static inline QString toString(const QLinkedList<T> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< std::map<Key, Value> > {
static inline QString toString(const std::map<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< boost::unordered_map<Key, Value> > {
static inline QString toString(const boost::unordered_map<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< boost::unordered_multimap<Key, Value> > {
static inline QString toString(const boost::unordered_multimap<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< QHash<Key, Value> > {
static inline QString toString(const QHash<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< QMultiHash<Key, Value> > {
static inline QString toString(const QMultiHash<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< QMap<Key, Value> > {
static inline QString toString(const QMap<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< QMultiMap<Key, Value> > {
static inline QString toString(const QMultiMap<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename Key, typename Value> struct QxStringCvt_ToString< qx::QxCollection<Key, Value> > {
static inline QString toString(const qx::QxCollection<Key, Value> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1> struct QxStringCvt_ToString< boost::tuple<T1> > {
static inline QString toString(const boost::tuple<T1> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2> struct QxStringCvt_ToString< boost::tuple<T1, T2> > {
static inline QString toString(const boost::tuple<T1, T2> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3> > {
static inline QString toString(const boost::tuple<T1, T2, T3> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4, typename T5> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4, T5> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4, T5> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4, T5, T6> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4, T5, T6> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4, T5, T6, T7> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4, T5, T6, T7> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4, T5, T6, T7, T8> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4, T5, T6, T7, T8> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> struct QxStringCvt_ToString< boost::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> > {
static inline QString toString(const boost::tuple<T1, T2, T3, T4, T5, T6, T7, T8, T9> & t, const QString & format)
{ Q_UNUSED(format); return QX_STR_CVT_DEFAULT_ARCHIVE::to_string(t); } };

} // namespace detail
} // namespace cvt
} // namespace qx
