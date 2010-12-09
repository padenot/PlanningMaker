#ifndef _QX_PMNG_EQUIPE_H_
#define _QX_PMNG_EQUIPE_H_

class QX_PMNG_DLL_EXPORT Equipe;

typedef boost::shared_ptr<Equipe> Equipe_ptr;
typedef std::vector<Equipe_ptr> List_equipe;

#include "orga.h"

class QX_PMNG_DLL_EXPORT Equipe
{
protected:


public:

   long         m_id;
   QString      m_nom;
   Orga_ptr     m_responsable;



   Equipe() : m_id(0) { ; }

   virtual ~Equipe() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Equipe, qx::trait::no_base_class_defined, 0)



#endif
