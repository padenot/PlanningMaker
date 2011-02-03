#include "orgaselectwidget.h"
#include "ui_orgaselectwidget.h"



orgaSelectWidget::orgaSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orgaSelectWidget)
{
    ui->setupUi(this);

    connect(ui->bouttonRechercheOrga, SIGNAL(clicked()), this, SLOT(Refresh()));
    connect(ui->listWidgetOrga, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(listOrgaDoubleClicked(QModelIndex)));

    editAct = new QAction("Modifier", this);
    editAct->setStatusTip("Modifier les informations sur l'Orga");
    connect(editAct, SIGNAL(triggered()), this, SLOT(editOrga()));
    ui->listWidgetOrga->addAction(editAct);

    delAct = new QAction("Supprimer", this);
    delAct->setStatusTip("Supprimer l'Orga");
    connect(delAct, SIGNAL(triggered()), this, SLOT(delOrga()));
    ui->listWidgetOrga->addAction(delAct);

    ui->listWidgetOrga->setContextMenuPolicy(Qt::ActionsContextMenu);
}

orgaSelectWidget::~orgaSelectWidget()
{
    delete ui;
}

void orgaSelectWidget::Refresh()
{
    list_orga orgas = model_->getOrgasByName(ui->champRechercheOrga->text());

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

void orgaSelectWidget::on_listWidgetOrga_doubleClicked(QModelIndex index)
{



}

void orgaSelectWidget::delOrga(){


}


void orgaSelectWidget::editOrga(){

    if (!ui->listWidgetOrga->selectedItems().isEmpty()){
    QListWidgetItem * item = ui->listWidgetOrga->selectedItems()[0];

    if(item->data(PointerRole).canConvert<Orga_ptr>())
    {
        Orga_ptr orga = item->data(PointerRole).value<Orga_ptr>();
        qDebug() << orga->m_categorie;
        emit orgaSelected(orga);
    }

}

}
