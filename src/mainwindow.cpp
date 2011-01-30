#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orga.h"

#include <QRegExp>
#include <QListWidgetItem>
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
    oew = new orgaEditWidget::orgaEditWidget(this);
    oew->model_=&model_;
    ui->stackedWidget->addWidget(oew);

    osw = new orgaSelectWidget::orgaSelectWidget(this);
    osw->model_=&model_;
    ui->ongletsCategorie->insertTab(0,osw,"Orga");


   connect(ui->ongletsCategorie, SIGNAL(currentChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));

   connect(&model_, SIGNAL(orgaRefresh()), osw, SLOT(Refresh()));
connect(osw, SIGNAL(orgaSelected(Orga_ptr)), oew, SLOT(loadInPanel(Orga_ptr)));




}

MainWindow::~MainWindow()
{
    delete ui;
}










void MainWindow::listOrgaDoubleClicked(QModelIndex index)
{
    State_ = Modification;
    QListWidgetItem * item = ui->listWidgetOrga->item(index.row());
    if(item->data(PointerRole).canConvert<Orga_ptr>())
    {
        Orga_ptr orga = item->data(PointerRole).value<Orga_ptr>();
        qDebug() << orga->m_categorie;

    }
}
