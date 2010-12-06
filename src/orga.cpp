#include "../include/precompiled.h"

#include "../include/orga.h"

#include <QxMemLeak.h>

QX_REGISTER_CPP_QX_PMNG(Orga)

namespace qx {
template <> void register_class(QxClass<Orga> & t)
{
   t.id(& Orga::m_id, "orga_id");

   t.data(& Orga::m_nom, "nom");
   t.data(& Orga::m_prenom, "prenom");
   t.data(& Orga::m_surnom, "surnom");
   t.data(& Orga::m_photo, "photo");
   t.data(& Orga::m_dateNaissance, "dateNaissance");
   t.data(& Orga::m_adresse, "adresse");
   t.data(& Orga::m_telephone, "telephone");
   t.data(& Orga::m_operateur, "operateur");
   t.data(& Orga::m_email, "email");
   t.data(& Orga::m_annee, "annee");
   t.data(& Orga::m_permis, "permis");
   t.data(& Orga::m_statut, "statut");
   t.data(& Orga::m_notes, "notes");
   t.data(& Orga::m_motivation, "motivation");
   t.data(& Orga::m_celibataire, "celibataire");



}}

void Orga::becomeJeanCapelle(){

    this->m_prenom = "Jean";
    this->m_nom = "Capelle";
    this->m_adresse = "INSA de Lyon";
    this->m_annee = 5;
    this->m_celibataire = false;
    this->m_dateNaissance = QDate::QDate(1957,9,1);
    this->m_email = "jean.capelle@insa-lyon.fr";
    this->m_motivation= 2000;
    this->m_notes = QString("Créateur de l'INSA de Lyon");
    this->m_operateur = "Orange";
    this->m_statut = 2;
    this->m_surnom = "JC";
    this->m_telephone = "+33472430000";

}

void Orga::becomeMichelRoti(){

    this->m_prenom = "Michel";
    this->m_nom = "Rôti";
    this->m_adresse = "Bureau des Élèves";
    this->m_annee = 3;
    this->m_celibataire = true;
    this->m_dateNaissance = QDate::QDate(1980,3,2);
    this->m_email = "michel.roti@bde.insa-lyon.fr";
    this->m_motivation= 3000;
    this->m_notes = QString("Rôti 24/7");
    this->m_operateur = "Rôti Télécom";
    this->m_statut = 2;
    this->m_surnom = "Rôti";
    this->m_telephone = "0623456789";

}
