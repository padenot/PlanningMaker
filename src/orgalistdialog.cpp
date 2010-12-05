#include "orgalistdialog.h"
#include "ui_orgalistdialog.h"

#include <QtSql>

OrgaListDialog::OrgaListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrgaListDialog)
{
    ui->setupUi(this);
    QSqlQueryModel *qsqm = new QSqlQueryModel;
    qx::QxSqlDatabase *qdb = qx::QxSqlDatabase::getSingleton();
qdb->getDatabase().open();

qsqm->setQuery("SELECT * FROM Orga",qdb->getDatabase());

ui->tableView->setModel(qsqm);


}

OrgaListDialog::~OrgaListDialog()
{
    delete ui;
}
