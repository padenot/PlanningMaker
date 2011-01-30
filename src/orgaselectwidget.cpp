#include "orgaselectwidget.h"
#include "ui_orgaselectwidget.h"



orgaSelectWidget::orgaSelectWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orgaSelectWidget)
{
    ui->setupUi(this);

    connect(ui->bouttonRechercheOrga, SIGNAL(clicked()), this, SLOT(Refresh()));
    connect(ui->listWidgetOrga, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(listOrgaDoubleClicked(QModelIndex)));
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

        QListWidgetItem * item = ui->listWidgetOrga->item(index.row());
        if(item->data(PointerRole).canConvert<Orga_ptr>())
        {
            Orga_ptr orga = item->data(PointerRole).value<Orga_ptr>();
            qDebug() << orga->m_categorie;
            emit orgaSelected(orga);
        }

}
