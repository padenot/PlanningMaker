#include "../include/precompiled.h"

#include "../include/orga.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Orga)

namespace qx {
template <> void register_class(QxClass<Orga> & t)
{
   t.id(& Orga::m_id, "orga_id");

   t.data(& Orga::m_nom, "nom");

}}

