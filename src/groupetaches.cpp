
#include "../include/precompiled.h"

#include "../include/groupetaches.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Groupetaches)

namespace qx {
template <> void register_class(QxClass<Groupetaches> & t)
{
    t.id(& Groupetaches::m_id, "groupetaches_id");
    t.data(& Groupetaches::m_nom, "nom");
    t.data(& Groupetaches::m_statut, "statut");
    t.relationManyToOne(& Groupetaches::m_createur, "orga_id");
    t.relationManyToOne(& Groupetaches::m_equipe, "equipe_id");



}}
