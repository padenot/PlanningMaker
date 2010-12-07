#include "../include/precompiled.h"

#include "../include/departement.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Departement)

namespace qx {
template <> void register_class(QxClass<Departement> & t)
{
   t.id(& Departement::m_id, "departement_id");
   t.data(& Departement::m_nom, "nom");
t.data(& Departement::m_abbreviation, "abbreviation");
t.data(& Departement::m_adresse, "adresse");



}}
void Departement::becomeIf(){
this->m_abbreviation="IF";
this->m_adresse="Bâtiment Blaise Pascal";
this->m_nom="Informatique";




}

void Departement::becomePc(){
    this->m_abbreviation="PC";
    this->m_adresse="Bâtiment Louis Néel";
    this->m_nom="Premier Cycle";




}

