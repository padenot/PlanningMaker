#ifndef _QX_PMNG_EQUIPE_H_
#define _QX_PMNG_EQUIPE_H_

class QX_PMNG_DLL_EXPORT Equipe;

typedef QSharedPointer<Equipe> Equipe_ptr;
typedef qx::QxCollection<long, Equipe_ptr> list_equipe;

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

        Q_DECLARE_METATYPE(Equipe)

        Q_DECLARE_METATYPE(Equipe_ptr)

#endif
