#include "orgalistdialog.h"
#include "ui_orgalistdialog.h"
#include "orga.h"
#include "tache.h"

#include <QtDebug>


OrgaListDialog::OrgaListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrgaListDialog)
{
ui->setupUi(this);

qx::dao::create_table<Orga>();
qx::dao::create_table<Departement>();
qx::dao::create_table<Groupetaches>();
qx::dao::create_table<Tache>();
qx::dao::create_table<Materiel>();
qx::dao::create_table<Lieu>();
qx::dao::create_table<Categorie>();
qx::dao::create_table<Equipe>();


QSqlDatabase db = qx::QxSqlDatabase::getDatabase();

qDebug()<<db.exec("CREATE TABLE materiel_tache (materiel_id INTEGER, tache_id INTEGER)").lastError();



QSqlError daoError;


Tache_ptr tac = Tache_ptr(new Tache);
Materiel_ptr mat = Materiel_ptr(new Materiel);
daoError = qx::dao::insert(tac);
daoError = qx::dao::insert(mat);
tac->m_materielX.insert(mat->m_id,mat);
daoError =qx::dao::save_with_all_relation(tac);

qDebug()<<daoError;

db =  QSqlDatabase::addDatabase("QSQLITE");
db.setHostName("localhost");
db.setDatabaseName("planningDatabase.db");

qsqm = new QSqlTableModel;
qsqm->setTable("Orga");
qsqm->select();


ui->tableView->setModel(qsqm);



}

OrgaListDialog::~OrgaListDialog()
{

    delete ui;
}

void OrgaListDialog::on_pushButton_clicked() //Ajoute 2 orgas et rafraichit le modèle
{
    QSqlError daoError;

    Departement_ptr info = Departement_ptr(new Departement); info->becomeIf();daoError = qx::dao::insert(info);
    Orga_ptr jeanCapelle = Orga_ptr(new Orga); jeanCapelle->becomeJeanCapelle();
    jeanCapelle->m_departement = info;
    daoError = qx::dao::insert(jeanCapelle);
    Orga_ptr michelRoti = Orga_ptr(new Orga); michelRoti->becomeMichelRoti();
michelRoti->m_departement = info;
    daoError = qx::dao::insert(michelRoti);
    qsqm->select();





    //dataChanged(qsqm->index(0,0),qsqm->index(qsqm->rowCount(),qsqm->columnCount()));

}
