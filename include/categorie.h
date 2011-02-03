#ifndef _QX_PMNG_CATEGORIE_H_
#define _QX_PMNG_CATEGORIE_H_



class QX_PMNG_DLL_EXPORT Categorie
{
protected:


public:

   long         m_id;
   QString      m_nom;
   int          m_confiance;



   Categorie() : m_id(0) { ; }

   virtual ~Categorie() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Categorie, qx::trait::no_base_class_defined, 0)

        typedef QSharedPointer<Categorie> Categorie_ptr;
        typedef qx::QxCollection<long, Categorie_ptr> list_categorie;

Q_DECLARE_METATYPE(Categorie)

Q_DECLARE_METATYPE(Categorie_ptr)

#endif
