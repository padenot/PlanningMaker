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
    ui(new Ui::MainWindow),
    enModification(0)
{
    ui->setupUi(this);

    connect(ui->ongletsCategorie, SIGNAL(currentChanged(int)), ui->stackedWidget, SLOT(setCurrentIndex(int)));
    connect(ui->okCancelOrgas, SIGNAL(rejected()), this, SLOT(onCancelOrgas()));
    connect(ui->okCancelOrgas, SIGNAL(accepted()), this, SLOT(onOkOrgaForm()));
    connect(&model_, SIGNAL(orgaRefresh()), this, SLOT(orgasRefresh()));
    connect(ui->bouttonRechercheOrga, SIGNAL(clicked()), this, SLOT(searchOrgas()));
    connect(ui->listWidgetOrga, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(listOrgaDoubleClicked(QModelIndex)));

    orgasRefresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCancelOrgas()
{
    clearOrgaForm();
}

void MainWindow::clearOrgaForm()
{
    ui->adresseLineEdit_4->clear();
    ui->anneeSpinBox_4->clear();
    ui->dateNaissanceEdit_4->clear();
    ui->nomLineEdit_4->clear();
    ui->prenomLineEdit_4->clear();
    ui->telephoneLineEdit_4->clear();
    ui->operateurLineEdit_4->clear();
    ui->surnomLineEdit_4->clear();
    ui->permisBcheckBox_4->setChecked(false);
    ui->dateNaissanceEdit_4->setDate(QDate(1990, 1, 1));
    ui->emailLineEdit->clear();
}

void MainWindow::onOkOrgaForm()
{
    resetColorOrgaForm();
    if(validateOrgaForm())
    {
    Orga orga;

    if(State_ == Modification)
        orga.m_id = enModification->m_id;
    orga.m_adresse = ui->adresseLineEdit_4->text();
    orga.m_annee = ui->anneeSpinBox_4->value();
    orga.m_dateNaissance = ui->dateNaissanceEdit_4->date();
    orga.m_nom = ui->nomLineEdit_4->text();
    orga.m_prenom = ui->prenomLineEdit_4->text();
    orga.m_telephone = ui->telephoneLineEdit_4->text();
    orga.m_operateur = ui->operateurLineEdit_4->text();
    orga.m_surnom = ui->surnomLineEdit_4->text();
    orga.m_email = ui->emailLineEdit->text();
    orga.m_permis = ui->permisBcheckBox_4->isChecked();
    orga.m_categorie = ui->confianceComboBox_4->currentIndex();
    orga.m_notes = ui->notesTextEdit->toPlainText();

    //TODO future versions :
    orga.m_celibataire = false;
    orga.m_motivation  = 0;
    orga.m_statut = 0;
    //orga.m_departement = ui->departementComboBox_4->currentText();

    if(State_ == Modification)
    {
        model_.addOrga(orga,true);
        State_ = Insertion;
    }
    else
        model_.addOrga(orga);

    }
    clearOrgaForm();
}

void MainWindow::resetColorOrgaForm()
{
    ui->adresseLineEdit_4->setStyleSheet(NoError);
    ui->anneeSpinBox_4->setStyleSheet(NoError);
    ui->dateNaissanceEdit_4->setStyleSheet(NoError);
    ui->nomLineEdit_4->setStyleSheet(NoError);
    ui->prenomLineEdit_4->setStyleSheet(NoError);
    ui->telephoneLineEdit_4->setStyleSheet(NoError);
    ui->operateurLineEdit_4->setStyleSheet(NoError);
    ui->surnomLineEdit_4->setStyleSheet(NoError);
    ui->departementLabel_4->setStyleSheet(NoError);
    ui->emailLineEdit->setStyleSheet(NoError);
    ui->notesTextEdit->setStyleSheet(NoError);
}

bool MainWindow::validateOrgaForm()
{
    bool valid = true;
    if(ui->adresseLineEdit_4->text().isEmpty())
    {
        ui->adresseLineEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(ui->anneeSpinBox_4->value() == 0)
    {
        ui->anneeSpinBox_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(! ui->dateNaissanceEdit_4->date().isValid())
    {
        ui->dateNaissanceEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(ui->nomLineEdit_4->text().isEmpty())
    {
        ui->nomLineEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(ui->prenomLineEdit_4->text().isEmpty())
    {
        ui->prenomLineEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(ui->telephoneLineEdit_4->text().isEmpty())
    {    ui->telephoneLineEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if(ui->operateurLineEdit_4->text().isEmpty())
    {
        ui->operateurLineEdit_4->setStyleSheet(ErrorStyle);
        valid = false;
    }
    if((ui->anneeSpinBox_4->value() > 2 && ui->departementComboBox_4->currentText() == "PC"))
    {
        ui->anneeSpinBox_4->setStyleSheet(ErrorStyle);
        ui->departementLabel_4->setStyleSheet(ErrorStyleText);
        valid = false;
    }

    QRegExp emailValidator("[A-Z0-9._+-]+@(?:[A-Z0-9-]+\.)+[A-Z]{2,4}");
    emailValidator.setCaseSensitivity(Qt::CaseInsensitive);
    if( ! emailValidator.exactMatch(ui->emailLineEdit->text()))
    {
        ui->emailLineEdit->setStyleSheet(ErrorStyle);
        valid = false;
    }
    return valid;
}

void MainWindow::orgasRefresh()
{
    list_orga orgas = model_.getOrgasByName(ui->champRechercheOrga->text());

    ui->listWidgetOrga->clear();

    qDebug() << "Size:" << orgas.size();

    _foreach(Orga_ptr orga, orgas)
    {
        QListWidgetItem* item = new QListWidgetItem(orga->m_prenom + " " + orga->m_nom);

        QVariant v;
        v.setValue<Orga_ptr>(orga);

        item->setData(PointerRole, v);

        ui->listWidgetOrga->addItem(item);
    }
}

void MainWindow::searchOrgas()
{
    orgasRefresh();
}

void MainWindow::loadInPanel(Orga_ptr orga)
{
    enModification = orga;
    ui->adresseLineEdit_4->setText(orga->m_adresse);
    ui->anneeSpinBox_4->setValue(orga->m_annee);
    ui->dateNaissanceEdit_4->setDate(orga->m_dateNaissance);
    ui->nomLineEdit_4->setText(orga->m_nom);
    ui->prenomLineEdit_4->setText(orga->m_prenom);
    ui->telephoneLineEdit_4->setText(orga->m_telephone);
    ui->operateurLineEdit_4->setText(orga->m_operateur);
    ui->surnomLineEdit_4->setText(orga->m_surnom);
    ui->emailLineEdit->setText(orga->m_email);
    ui->permisBcheckBox_4->setChecked(orga->m_permis);
    ui->confianceComboBox_4->setCurrentIndex(orga->m_categorie);
    ui->notesTextEdit->setPlainText(orga->m_notes);
}

void MainWindow::listOrgaDoubleClicked(QModelIndex index)
{
    State_ = Modification;
    QListWidgetItem * item = ui->listWidgetOrga->item(index.row());
    if(item->data(PointerRole).canConvert<Orga_ptr>())
    {
        Orga_ptr orga = item->data(PointerRole).value<Orga_ptr>();
        loadInPanel(orga);
    }
}
