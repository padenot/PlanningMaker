#include "orgaeditwidget.h"
#include "ui_orgaeditwidget.h"



orgaEditWidget::orgaEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orgaEditWidget)
{

ui->setupUi(this);
    State_=Insertion;



}

orgaEditWidget::~orgaEditWidget()
{
    delete ui;
}

void orgaEditWidget::onCancelOrgas()
{
    clearOrgaForm();
    State_ = Insertion;
}

void orgaEditWidget::clearOrgaForm()
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
    ui->departementComboBox_4->clear();
   // ui->confianceComboBox_4->clear();
    ui->dateNaissanceEdit_4->setDate(QDate(1990, 1, 1));
    ui->emailLineEdit->clear();
}

void orgaEditWidget::onOkOrgaForm()
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
    //orga.m_categorie = ui->confianceComboBox_4->currentIndex();
    orga.m_notes = ui->notesTextEdit->toPlainText();

    //TODO future versions :
    orga.m_celibataire = false;
    orga.m_motivation  = 0;
    orga.m_statut = 0;
    //orga.m_departement = ui->departementComboBox_4->currentText();

    if(State_ == Modification)
    {
        model_->addOrga(orga,true);
        State_ = Insertion;
    }
    else
        model_->addOrga(orga);

    clearOrgaForm();
    }
}

void orgaEditWidget::resetColorOrgaForm()
{
    ui->adresseLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->anneeSpinBox_4->setStyleSheet(MainWindow::NoError);
    ui->dateNaissanceEdit_4->setStyleSheet(MainWindow::NoError);
    ui->nomLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->prenomLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->telephoneLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->operateurLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->surnomLineEdit_4->setStyleSheet(MainWindow::NoError);
    ui->departementLabel_4->setStyleSheet(MainWindow::NoError);
    ui->emailLineEdit->setStyleSheet(MainWindow::NoError);
    ui->notesTextEdit->setStyleSheet(MainWindow::NoError);
}

bool orgaEditWidget::validateOrgaForm()
{
    bool valid = true;
    if(ui->adresseLineEdit_4->text().isEmpty())
    {
        ui->adresseLineEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(ui->anneeSpinBox_4->value() == 0)
    {
        ui->anneeSpinBox_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(! ui->dateNaissanceEdit_4->date().isValid())
    {
        ui->dateNaissanceEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(ui->nomLineEdit_4->text().isEmpty())
    {
        ui->nomLineEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(ui->prenomLineEdit_4->text().isEmpty())
    {
        ui->prenomLineEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(ui->telephoneLineEdit_4->text().isEmpty())
    {    ui->telephoneLineEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if(ui->operateurLineEdit_4->text().isEmpty())
    {
        ui->operateurLineEdit_4->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    if((ui->anneeSpinBox_4->value() > 2 && ui->departementComboBox_4->currentText() == "PC"))
    {
        ui->anneeSpinBox_4->setStyleSheet(MainWindow::ErrorStyle);
        ui->departementLabel_4->setStyleSheet(MainWindow::ErrorStyleText);
        valid = false;
    }

    QRegExp emailValidator("[A-Z0-9._+-]+@(?:[A-Z0-9-]+\.)+[A-Z]{2,4}");
    emailValidator.setCaseSensitivity(Qt::CaseInsensitive);
    if( ! emailValidator.exactMatch(ui->emailLineEdit->text()))
    {
        ui->emailLineEdit->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }
    return valid;
}





void orgaEditWidget::loadInPanel(Orga_ptr orga)
{
    // This will store the orga that will be loaded in the panel,
    // to keep the data not displayed, such as the ID.


    State_=Modification;
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
    //ui->confianceComboBox_4->setCurrentIndex(orga->m_categorie);
    ui->notesTextEdit->setPlainText(orga->m_notes);

    // A valid record has been loaded : reset the colors
    resetColorOrgaForm();
}

void orgaEditWidget::setCategorie(Categorie_ptr item)
{


    ui->catPushButton->setText(item->m_nom);
}



void orgaEditWidget::on_okCancelOrgas_clicked(QAbstractButton* button)
{

    if ( ui->okCancelOrgas->standardButton(button) == QDialogButtonBox::Reset){
    onCancelOrgas();



    }else if ( ui->okCancelOrgas->standardButton(button) == QDialogButtonBox::Save){
    onOkOrgaForm();



    }
}
