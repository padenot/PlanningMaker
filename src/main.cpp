#include "../include/precompiled.h"

#include <QxMemLeak.h>

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "orga.h"
#include <QSqlError>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    std::cout<<"ha"<<std::endl;

    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
       qx::QxSqlDatabase::getSingleton()->setDatabaseName("./test_qxorm.db");
       qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
       qx::QxSqlDatabase::getSingleton()->setUserName("root");
       qx::QxSqlDatabase::getSingleton()->setPassword("");




QSqlError daoError = qx::dao::create_table<Orga>();
Orga_ptr jeanCapelle = Orga_ptr(new Orga); jeanCapelle->m_nom="Jean Capelle";
Orga_ptr michelRoti = Orga_ptr(new Orga); michelRoti->m_nom="Michel Roti";
daoError = qx::dao::insert(jeanCapelle);
daoError = qx::dao::insert(michelRoti);


    return a.exec();
}
