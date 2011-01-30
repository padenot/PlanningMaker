#include "planningmodel.h"
// We use enum for departements for now
// #include "departement.h"
#include "groupetaches.h"
#include "tache.h"
#include "materiel.h"
#include "lieu.h"
#include "categorie.h"
#include "equipe.h"
#include "orga.h"
#include <QxCollection/QxForeach.h>


PlanningModel::PlanningModel()
{
    //Setups SQLITE DB connection
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
    qx::QxSqlDatabase::getSingleton()->setDatabaseName("./planningDatabase.db");

    qx::dao::create_table<Orga>();
    qx::dao::create_table<Departement>();
    qx::dao::create_table<Groupetaches>();
    qx::dao::create_table<Tache>();
    qx::dao::create_table<Materiel>();
    qx::dao::create_table<Lieu>();
    qx::dao::create_table<Categorie>();
    qx::dao::create_table<Equipe>();


    qx::dao::fetch_all(orgas);

}


void PlanningModel::addOrga(Orga orga, bool update)
{
    QSqlError error;
    if(update)
         error = qx::dao::update(orga);
    else
         error = qx::dao::insert(orga);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(orgas);
    emit orgaRefresh();
}

void PlanningModel::removeOrga(Orga orga)
{
    QSqlError error = qx::dao::delete_by_id(orga);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(orgas);
    emit orgaRefresh();
}

list_orga PlanningModel::getOrgasByName(const QString& search)
{
    qDebug() << __func__;
    if(search.isEmpty())
    {
        qDebug() << "empty, size :" << orgas.size();
        return orgas;
    }

    list_orga toReturn;

    _foreach(Orga_ptr orga, orgas)
    {
        QString searchInto(orga->m_prenom + " " + orga->m_nom);
        qDebug() << "Search into" << searchInto;
        if(searchInto.contains(search, Qt::CaseInsensitive))
        {
            qDebug() << "match:" << orga->m_prenom + " " + orga->m_nom;
            toReturn.insert(toReturn.size(),orga);
            qDebug() << "taille:" << toReturn.size();
        }
    }
    return toReturn;
}


