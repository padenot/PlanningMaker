#include "../include/precompiled.h"

#include <QxMemLeak.h>

#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QSqlError>
#include <QtDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Setup support for accented chars
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));

    //Setups SQLITE DB connection
    qx::QxSqlDatabase::getSingleton()->setDriverName("QSQLITE");
       qx::QxSqlDatabase::getSingleton()->setDatabaseName("./planningDatabase.db");
       qx::QxSqlDatabase::getSingleton()->setHostName("localhost");
       qx::QxSqlDatabase::getSingleton()->setUserName("root");
       qx::QxSqlDatabase::getSingleton()->setPassword("");



MainWindow w;
w.show();

    return a.exec();
}
