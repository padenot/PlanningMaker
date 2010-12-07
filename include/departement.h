#ifndef _QX_PMNG_DEPARTEMENT_H_
#define _QX_PMNG_DEPARTEMENT_H_



class QX_PMNG_DLL_EXPORT Departement
{
protected:


public:

   long         m_id;
   QString      m_nom;
   QString      m_abbreviation;
   QString      m_adresse;


   void becomeIf();
   void becomePc();
   Departement() : m_id(0) { ; }

   virtual ~Departement() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Departement, qx::trait::no_base_class_defined, 0)

typedef boost::shared_ptr<Departement> Departement_ptr;
typedef std::vector<Departement_ptr> List_departement;

#endif
