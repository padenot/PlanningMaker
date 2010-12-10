
#ifndef _QX_PMNG_GROUPETACHES_H_
#define _QX_PMNG_GROUPETACHES_H_

#include "orga.h"

class QX_PMNG_DLL_EXPORT Groupetaches;

typedef QSharedPointer<Groupetaches> Groupetaches_ptr;
typedef qx::QxCollection<long, Groupetaches_ptr> list_groupetaches;

class QX_PMNG_DLL_EXPORT Groupetaches
{
protected:


public:

   long         m_id;
   QString      m_nom;
   int          m_statut;
   Orga_ptr     m_createur;
   Equipe_ptr   m_equipe;



   Groupetaches() : m_id(0) { ; }

   virtual ~Groupetaches() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Groupetaches, qx::trait::no_base_class_defined, 0)



#endif

