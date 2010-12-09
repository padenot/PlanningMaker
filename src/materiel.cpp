#include "../include/precompiled.h"

#include "../include/materiel.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Materiel)

namespace qx {
template <> void register_class(QxClass<Materiel> & t)
{
   t.id(& Materiel::m_id, "materiel_id");
   t.data(& Materiel::m_nom, "nom");
t.data(& Materiel::m_volume, "volume");
t.data(& Materiel::m_description, "description");
t.relationManyToMany(& Materiel::m_tacheX, "list_tache", "materiel_tache", "tache_id", "materiel_id");


}}
