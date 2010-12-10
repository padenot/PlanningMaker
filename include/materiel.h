#ifndef _QX_PMNG_MATERIEL_H_
#define _QX_PMNG_MATERIEL_H_

class QX_PMNG_DLL_EXPORT Materiel;

typedef QSharedPointer<Materiel> Materiel_ptr;
typedef qx::QxCollection<long, Materiel_ptr> list_materiel;

#include "tache.h"


class QX_PMNG_DLL_EXPORT Materiel
{
protected:


public:

   long         m_id;
   QString      m_nom;
   int          m_volume;
   QString      m_description;
   list_tache   m_tacheX;


   Materiel() : m_id(0) { ; }

   virtual ~Materiel() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Materiel, qx::trait::no_base_class_defined, 0)



#endif
