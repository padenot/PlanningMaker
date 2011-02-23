#include "lieueditwidget.h"
#include "ui_lieueditwidget.h"



lieuEditWidget::lieuEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lieuEditWidget)
{

ui->setupUi(this);

editAct = new QAction("Modifier", this);
connect(editAct, SIGNAL(triggered()), this, SLOT(edit()));
ui->listWidget->addAction(editAct);

ui->listWidget->setContextMenuPolicy(Qt::ActionsContextMenu);


    State_=Insertion;





}

lieuEditWidget::~lieuEditWidget()
{
    delete ui;
}

void lieuEditWidget::onCancel()
{
    clearForm();
    State_ = Insertion;
}

void lieuEditWidget::clearForm()
{
    ui->nomLineEdit->clear();

}

void lieuEditWidget::onOk()
{
    resetColorForm();
    if(validateForm())
    {
    Lieu item;

    if(State_ == Modification)
        item.m_id = enModification->m_id;


    item.m_nom=ui->nomLineEdit->text();



    if(State_ == Modification)
    {
        model_->addLieu(item,true);
        State_ = Insertion;
    }
    else
        model_->addLieu(item);

    clearForm();
    }

}

void lieuEditWidget::resetColorForm()
{
    ui->nomLineEdit->setStyleSheet(MainWindow::NoError);


}

bool lieuEditWidget::validateForm()
{
    bool valid = true;
    if(ui->nomLineEdit->text().isEmpty())
    {
        ui->nomLineEdit->setStyleSheet(MainWindow::ErrorStyle);
        valid = false;
    }



    return valid;
}





void lieuEditWidget::load(Lieu_ptr item)
{



    State_=Modification;
    enModification = item;

    ui->nomLineEdit->setText(item->m_nom);




    resetColorForm();
}




void lieuEditWidget::on_btns_clicked(QAbstractButton* button)
{

    if ( ui->btns->standardButton(button) == QDialogButtonBox::Reset){
    onCancel();



    }else if ( ui->btns->standardButton(button) == QDialogButtonBox::Save){
    onOk();



    }
}


void lieuEditWidget::refresh()
{
    list_lieu lieux = model_->getLieux();
    ui->listWidget->clear();

    _foreach(Lieu_ptr lieu, lieux)
    {

        QListWidgetItem* item = new QListWidgetItem(lieu->m_nom);

        QVariant v;
        v.setValue<Lieu_ptr>(lieu);

        item->setData(PointerRole, v);

        ui->listWidget->addItem(item);

    }
}

void lieuEditWidget::del(){


}


void lieuEditWidget::edit(){

    if (!ui->listWidget->selectedItems().isEmpty()){
    QListWidgetItem * item = ui->listWidget->selectedItems()[0];

    if(item->data(PointerRole).canConvert<Lieu_ptr>())
    {
        Lieu_ptr lieu = item->data(PointerRole).value<Lieu_ptr>();

        load(lieu);
    }

}
}

void lieuEditWidget::on_listWidget_doubleClicked(QModelIndex index)
{
    if (!ui->listWidget->selectedItems().isEmpty()){
    QListWidgetItem * item = ui->listWidget->selectedItems()[0];

    if(item->data(PointerRole).canConvert<Lieu_ptr>())
    {
        Lieu_ptr lieu = item->data(PointerRole).value<Lieu_ptr>();

        emit selected(lieu);
    }

}
}
