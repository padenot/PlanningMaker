#ifndef _QX_PMNG_CLASS_H_
#define _QX_PMNG_CLASS_H_



class QX_PMNG_DLL_EXPORT Orga
{
public:

   long           m_id;
   QString        m_nom;

   Orga() : m_id(0) { ; }
   virtual ~Orga() { ; }
};

QX_REGISTER_HPP_QX_PMNG(Orga, qx::trait::no_base_class_defined, 0)

typedef boost::shared_ptr<Orga> Orga_ptr;
typedef std::vector<Orga_ptr> List_orga;

#endif
