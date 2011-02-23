
#include "../include/precompiled.h"

#include "creneau.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Creneau)

namespace qx {
template <> void register_class(QxClass<Creneau> & t)
{


   t.id(& Creneau::m_id, "creneau_id");
  t.data(& Creneau::m_plageHoraire, "plageHoraire");
 t.relationManyToMany(& Creneau::m_orgasAffectes, "list_orgasAffectes", "orga_creneau", "orga_id", "creneau_id");




}}

