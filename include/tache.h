
#ifndef _QX_PMNG_TACHE_H_
#define _QX_PMNG_TACHE_H_

#include "orga.h"
#include "groupetaches.h"
#include "lieu.h"


class QX_PMNG_DLL_EXPORT Tache;

typedef std::pair<QDateTime,QDateTime> plageHoraire;
typedef std::vector<plageHoraire> List_plageHoraire;
typedef boost::shared_ptr<Tache> Tache_ptr;
typedef std::vector<Tache_ptr> List_tache;

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
   //orgas nécessaires
   int          m_confiance;

   List_materiel    m_materielX;
   int          m_priorite;




   Tache() : m_id(0) { ; }

   virtual ~Tache() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Tache, qx::trait::no_base_class_defined, 0)



#endif

