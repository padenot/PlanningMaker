
#include "../include/precompiled.h"

#include "tache.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Tache)

namespace qx {
template <> void register_class(QxClass<Tache> & t)
{


   t.id(& Tache::m_id, "tache_id");
   t.data(& Tache::m_nom, "nom");
   t.data(& Tache::m_statut, "statut");
   t.data(& Tache::m_instructions, "instructions");
   t.data(& Tache::m_consignesSecu, "consignesSecu");
   t.data(& Tache::m_confiance, "confiance");
   t.data(& Tache::m_priorite, "priorite");
   t.data(& Tache::m_plagesHoraires, "plagesHoraires");

   t.relationManyToOne(& Tache::m_groupetaches, "groupetaches_id");
    t.relationManyToOne(& Tache::m_lieu, "lieu_id");
    t.relationManyToMany(& Tache::m_materielX, "list_materiel", "materiel_tache", "materiel_id", "tache_id");




}}

