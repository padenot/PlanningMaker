
#ifndef _QX_PMNG_TACHE_H_
#define _QX_PMNG_TACHE_H_

#include "orga.h"
#include "groupetaches.h"
#include "lieu.h"


class QX_PMNG_DLL_EXPORT Tache;

typedef std::pair<QDateTime,QDateTime> plageHoraire;
typedef std::vector<plageHoraire> List_plageHoraire;

typedef std::pair<int,int> orgaNecessairesParEquipe;
typedef std::vector<orgaNecessairesParEquipe> List_orgaNecessairesParEquipe;

typedef std::pair<int,int> orgaNecessairesParCategorie;
typedef std::vector<orgaNecessairesParCategorie> List_orgaNecessairesParCategorie;

typedef QSharedPointer<Tache> Tache_ptr;
typedef qx::QxCollection<long, Tache_ptr> list_tache;

#include "materiel.h"

class QX_PMNG_DLL_EXPORT Tache
{
protected:


public:

   long         m_id;
   Groupetaches_ptr m_groupetaches;
   QString      m_nom;
   int          m_statut;
   List_plageHoraire m_plagesHoraires;
   QString      m_instructions;
   QString      m_consignesSecu;
   Lieu_ptr     m_lieu;
   bool         m_respNecessaire;
   List_orgaNecessairesParCategorie m_orgaNecessairesParCategorie;
   List_orgaNecessairesParEquipe m_orgaNecessairesParEquipe;
   int          m_orgaNecessaires;
   int          m_confiance;

   list_materiel    m_materielX;
   int          m_priorite;




   Tache() : m_id(0) { ; }

   virtual ~Tache() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Tache, qx::trait::no_base_class_defined, 0)



#endif

