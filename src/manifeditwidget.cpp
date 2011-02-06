#include "manifeditwidget.h"
#include "ui_manifeditwidget.h"

manifEditWidget::manifEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manifEditWidget)
{
    ui->setupUi(this);

}

manifEditWidget::~manifEditWidget()
{
    delete ui;
}

void manifEditWidget::Refresh(){

    list_categorie categories = model_->getCategories();

    _foreach(Categorie_ptr categorie, categories)
    {

        QListWidgetItem* item = new QListWidgetItem(categorie->m_nom);

        QVariant v;
        v.setValue<Categorie_ptr>(categorie);

        item->setData(PointerRole, v);

        ui->catListWidget->addItem(item);

    }

    list_lieu lieux = model_->getLieux();


    _foreach(Lieu_ptr lieu, lieux)
    {

        QListWidgetItem* item = new QListWidgetItem(lieu->m_nom);

        QVariant v;
        v.setValue<Lieu_ptr>(lieu);

        item->setData(PointerRole, v);

        ui->liListWidget->addItem(item);

    }

    list_equipe equipes = model_->getEquipes();


    _foreach(Equipe_ptr equipe, equipes)
    {

        QListWidgetItem* item = new QListWidgetItem(equipe->m_nom);

        QVariant v;
        v.setValue<Equipe_ptr>(equipe);
        item->setData(PointerRole, v);

        ui->liListWidget->addItem(item);

    }





}

void manifEditWidget::load(Categorie_ptr){


}

void manifEditWidget::load(Equipe_ptr){


}

void manifEditWidget::load(Lieu_ptr){


}

void manifEditWidget::onOkCat(){


}

void manifEditWidget::onOkEq(){


}

void manifEditWidget::onOkLi(){


}

void manifEditWidget::onCancel(){


}
