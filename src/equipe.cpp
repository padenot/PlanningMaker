#include "../include/precompiled.h"

#include "equipe.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Equipe)

namespace qx {
template <> void register_class(QxClass<Equipe> & t)
{
   t.id(& Equipe::m_id, "equipe_id");
   t.data(& Equipe::m_nom, "nom");
   t.relationManyToOne(& Equipe::m_responsable, "responsable_id");




}}
