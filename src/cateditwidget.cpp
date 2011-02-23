#include "cateditwidget.h"
#include "ui_cateditwidget.h"



catEditWidget::catEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::catEditWidget)
{

ui->setupUi(this);

editAct = new QAction("Modifier", this);
connect(editAct, SIGNAL(triggered()), this, SLOT(edit()));
ui->listWidget->addAction(editAct);

ui->listWidget->setContextMenuPolicy(Qt::ActionsContextMenu);


    State_=Insertion;





}

catEditWidget::~catEditWidget()
{
    delete ui;
}

void catEditWidget::onCancel()
{
    clearForm();
    State_ = Insertion;
}

void catEditWidget::clearForm()
{
    ui->nomLineEdit->clear();
    ui->confLineEdit->clear();
}

void catEditWidget::onOk()
{
    resetColorForm();
    if(validateForm())
    {
    Categorie item;

    if(State_ == Modification)
        item.m_id = enModification->m_id;


    item.m_nom=ui->nomLineEdit->text();
item.m_confiance=ui->confLineEdit->text().toInt();


    if(State_ == Modification)
    {
        model_->addCategorie(item,true);
        State_ = Insertion;
    }
    else
        model_->addCategorie(item);

    clearForm();
    }

}

void catEditWidget::resetColorForm()
{
    ui->nomLineEdit->setStyleSheet(MainWindow::NoError);
    ui->confLineEdit->setStyleSheet(MainWindow::NoError);

}

bool catEditWidget::validateForm()
{
    bool valid = true;
    if(ui->nomLineEdit->text().isEmpty())
    {
        ui->nomLineEdit->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }

    if(ui->confLineEdit->text().isEmpty())
    {
        ui->confLineEdit->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }

    return valid;
}





void catEditWidget::load(Categorie_ptr item)
{



    State_=Modification;
    enModification = item;

    ui->nomLineEdit->setText(item->m_nom);

    QString conf;
    conf = QString("%1").arg(item->m_confiance);
    ui->confLineEdit->setText(conf);



    resetColorForm();
}




void catEditWidget::on_btns_clicked(QAbstractButton* button)
{

    if ( ui->btns->standardButton(button) == QDialogButtonBox::Reset){
    onCancel();



    }else if ( ui->btns->standardButton(button) == QDialogButtonBox::Save){
    onOk();



    }
}


void catEditWidget::refresh()
{
    list_categorie categories = model_->getCategories();
    ui->listWidget->clear();

    _foreach(Categorie_ptr categorie, categories)
    {

        QListWidgetItem* item = new QListWidgetItem(categorie->m_nom);

        QVariant v;
        v.setValue<Categorie_ptr>(categorie);

        item->setData(PointerRole, v);

        ui->listWidget->addItem(item);

    }
}

void catEditWidget::del(){


}


void catEditWidget::edit(){

    if (!ui->listWidget->selectedItems().isEmpty()){
    QListWidgetItem * item = ui->listWidget->selectedItems()[0];

    if(item->data(PointerRole).canConvert<Categorie_ptr>())
    {
        Categorie_ptr categorie = item->data(PointerRole).value<Categorie_ptr>();

        load(categorie);
    }

}
}

void catEditWidget::on_listWidget_doubleClicked(QModelIndex index)
{
    if (!ui->listWidget->selectedItems().isEmpty()){
    QListWidgetItem * item = ui->listWidget->selectedItems()[0];

    if(item->data(PointerRole).canConvert<Categorie_ptr>())
    {
        Categorie_ptr categorie = item->data(PointerRole).value<Categorie_ptr>();

        emit selected(categorie);
    }

}
}
