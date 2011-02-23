
#ifndef _QX_PMNG_CRENEAU_H_
#define _QX_PMNG_CRENEAU_H_

class QX_PMNG_DLL_EXPORT Creneau;


typedef std::pair<QDateTime,QDateTime> plageHoraire;
typedef std::vector<plageHoraire> List_plageHoraire;

typedef QSharedPointer<Creneau> Creneau_ptr;
typedef qx::QxCollection<long, Creneau_ptr> list_creneau;


#include "orga.h"
#include "lieu.h"
#include "materiel.h"

class QX_PMNG_DLL_EXPORT Creneau
{
protected:


public:

   long         m_id;
   plageHoraire m_plageHoraire;
   Tache_ptr    m_tache;
   list_orga    m_orgasAffectes;




   Creneau() : m_id(0) { ; }

   virtual ~Creneau() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Creneau, qx::trait::no_base_class_defined, 0)



#endif

