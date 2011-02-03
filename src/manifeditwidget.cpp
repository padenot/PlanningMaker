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


    }



}
