#include "../include/precompiled.h"

#include "../include/categorie.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Categorie)

namespace qx {
template <> void register_class(QxClass<Categorie> & t)
{
   t.id(& Categorie::m_id, "categorie_id");
   t.data(& Categorie::m_nom, "nom");
   t.data(& Categorie::m_confiance, "confiance");



}}
