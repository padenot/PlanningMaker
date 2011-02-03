#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QRegExp>
#include <QListWidgetItem>
#include <QtGui>
#include <QxCollection/QxForeach.h>

const QString MainWindow::ErrorStyle = "background-color: #f44";
const QString MainWindow::ErrorMessage = trUtf8("Des informations manquent pour valider la création de l'orga");
const QString MainWindow::ErrorDepartAnnee = trUtf8("Erreur de cohérence année/département");
const QString MainWindow::ErrorStyleText = "color: #f44";
const QString MainWindow::NoError = "background-color: none;";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->orgaSelectWidget_2->model_=&model_;
    ui->orgaEditWidget_1->model_=&model_;

readSettings();


//connect(ui->ongletsCategorie, SIGNAL(currentChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

connect(&model_, SIGNAL(orgaRefresh()), ui->orgaSelectWidget_2, SLOT(Refresh()));
//connect(&model_, SIGNAL(orgaRefresh()), mew, SLOT(Refresh()));
connect(ui->orgaSelectWidget_2, SIGNAL(orgaSelected(Orga_ptr)), ui->orgaEditWidget_1, SLOT(loadInPanel(Orga_ptr)));
connect(ui->orgaSelectWidget_2, SIGNAL(orgaSelected(Orga_ptr)), this, SLOT(showOrgaEditPanel()));


}


void MainWindow::writeSettings()
{
    QSettings settings("MyCompany", "MyApp");

    settings.beginGroup("mainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState());
    settings.endGroup();
}

void MainWindow::readSettings()
{
    QSettings settings("MyCompany", "MyApp");


    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());

}


void MainWindow::closeEvent(QCloseEvent *event)
{
    QSettings settings("MyCompany", "MyApp");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    QMainWindow::closeEvent(event);
}


void MainWindow::showOrgaEditPanel(){
ui->orgaEditDockWidget->show();

}





MainWindow::~MainWindow()
{
    delete ui;
}












