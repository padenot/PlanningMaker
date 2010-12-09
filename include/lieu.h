#ifndef _QX_PMNG_LIEU_H_
#define _QX_PMNG_LIEU_H_



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

typedef boost::shared_ptr<Lieu> Lieu_ptr;
typedef std::vector<Lieu_ptr> List_lieu;

#endif
