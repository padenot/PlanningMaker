    #include "../include/precompiled.h"

#include <QxMemLeak.h>

#include <QtGui/QApplication>
#include "mainwindow.h"
#include "orga.h"
#include "tache.h"

#include <QSqlError>
#include <QtDebug>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Setup support for accented chars
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));


//    qx::QxSqlDatabase::deleteSingleton();
//       qx::QxSqlDatabase::getSingleton()->setDriverName("QMYSQL");
//          qx::QxSqlDatabase::getSingleton()->setDatabaseName("test");
//          qx::QxSqlDatabase::getSingleton()->setHostName("127.0.0.1");
//          qx::QxSqlDatabase::getSingleton()->setUserName("root");
//          qx::QxSqlDatabase::getSingleton()->setPassword("GEN:3Dv[)J2I");



    MainWindow w;
    w.showMaximized();

    return a.exec();
}
