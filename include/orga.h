#ifndef _QX_PMNG_ORGA_H_
#define _QX_PMNG_ORGA_H_
#include <QDate>
#include <QPixmap>
#include "departement.h"
#include "equipe.h"


class QX_PMNG_DLL_EXPORT Orga
{
protected:


public:

   long         m_id;
   QString      m_nom;
   QString      m_prenom;
   QString      m_surnom;
   QPixmap      m_photo;
   QDate        m_dateNaissance;
   QString      m_adresse;
   QString      m_telephone;
   QString      m_operateur;
   QString      m_email;
   Equipe_ptr   m_equipe;
   //TODO : Categorie
   int          m_annee;
   Departement_ptr m_departement;
   bool         m_permis;
   int          m_statut;
   QString      m_notes;
   int          m_motivation;
   bool         m_celibataire;



   Orga() : m_id(0) { ; }
   void becomeJeanCapelle();
   void becomeMichelRoti();
   virtual ~Orga() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Orga, qx::trait::no_base_class_defined, 0)

typedef boost::shared_ptr<Orga> Orga_ptr;
typedef std::vector<Orga_ptr> List_orga;

#endif
