#include "../include/precompiled.h"

#include "../include/lieu.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Lieu)

namespace qx {
template <> void register_class(QxClass<Lieu> & t)
{
   t.id(& Lieu::m_id, "lieu_id");
   t.data(& Lieu::m_nom, "nom");
//t.data(& Lieu::m_latitude, "latitude");
//t.data(& Lieu::m_longitude, "longitude");



}}
