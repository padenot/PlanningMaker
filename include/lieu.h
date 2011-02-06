#ifndef _QX_PMNG_LIEU_H_
#define _QX_PMNG_LIEU_H_

class Lieu;

typedef QSharedPointer<Lieu> Lieu_ptr;
typedef qx::QxCollection<long, Lieu_ptr> list_lieu;

class QX_PMNG_DLL_EXPORT Lieu
{
protected:


public:

   long         m_id;
   QString      m_nom;
   double      m_latitude;
   double      m_longitude;



   Lieu() : m_id(0) { ; }

   virtual ~Lieu() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Lieu, qx::trait::no_base_class_defined, 0)

        Q_DECLARE_METATYPE(Lieu)

        Q_DECLARE_METATYPE(Lieu_ptr)



#endif
