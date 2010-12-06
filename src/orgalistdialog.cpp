#include "orgalistdialog.h"
#include "ui_orgalistdialog.h"
#include "orga.h"
#include <QtDebug>


OrgaListDialog::OrgaListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrgaListDialog)
{
ui->setupUi(this);

qx::dao::create_table<Orga>();


QSqlDatabase db =  QSqlDatabase::addDatabase("QSQLITE");
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

    Orga_ptr jeanCapelle = Orga_ptr(new Orga); jeanCapelle->becomeJeanCapelle();daoError = qx::dao::insert(jeanCapelle);
    Orga_ptr michelRoti = Orga_ptr(new Orga); michelRoti->becomeMichelRoti(); daoError = qx::dao::insert(michelRoti);
    qsqm->select();





    //dataChanged(qsqm->index(0,0),qsqm->index(qsqm->rowCount(),qsqm->columnCount()));

}
