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

qx::dao::fetch_all(categories);
    qx::dao::fetch_all(orgas);

    emit refresh();

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
    emit refresh();
}

void PlanningModel::removeOrga(Orga orga)
{
    QSqlError error = qx::dao::delete_by_id(orga);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(orgas);
    emit refresh();
}

void PlanningModel::addCategorie(Categorie categorie, bool update)
{
    QSqlError error;
    if(update)
         error = qx::dao::update(categorie);
    else
         error = qx::dao::insert(categorie);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(categories);
    emit refresh();
}

void PlanningModel::removeCategorie(Categorie categorie)
{
    QSqlError error = qx::dao::delete_by_id(categorie);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(categories);
    emit refresh();
}

void PlanningModel::addEquipe(Equipe equipe, bool update)
{
    QSqlError error;
    if(update)
         error = qx::dao::update(equipe);
    else
         error = qx::dao::insert(equipe);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(equipes);
    emit refresh();
}

void PlanningModel::removeEquipe(Equipe equipe)
{
    QSqlError error = qx::dao::delete_by_id(equipe);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(equipes);
    emit refresh();
}

void PlanningModel::addLieu(Lieu lieu, bool update)
{
    QSqlError error;
    if(update)
         error = qx::dao::update(lieu);
    else
         error = qx::dao::insert(lieu);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(lieux);
    emit refresh();
}

void PlanningModel::removeLieu(Lieu lieu)
{
    QSqlError error = qx::dao::delete_by_id(lieu);
    if( ! error.isValid())
    {
        qDebug() << error;
    }
    qx::dao::fetch_all(lieux);
    emit refresh();
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

list_categorie PlanningModel::getCategories()
{

    list_categorie toReturn;

    _foreach(Categorie_ptr categorie, categories)
    {

            toReturn.insert(toReturn.size(),categorie);


    }
    return toReturn;
}

list_equipe PlanningModel::getEquipes(){

    list_equipe toReturn;

    _foreach(Equipe_ptr equipe, equipes)
    {

            toReturn.insert(toReturn.size(),equipe);


    }
    return toReturn;



}

list_lieu PlanningModel::getLieux(){

    list_lieu toReturn;

    _foreach(Lieu_ptr lieu, lieux)
    {

            toReturn.insert(toReturn.size(),lieu);


    }
    return toReturn;



}

void PlanningModel::refreshModel(){

    emit refresh();
}

