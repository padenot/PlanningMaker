#ifndef MANIFEDITWIDGET_H
#define MANIFEDITWIDGET_H

#include <QWidget>
 #include <QListWidgetItem>
namespace Ui {
    class manifEditWidget;
}
#include "mainwindow.h"




class manifEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit manifEditWidget(QWidget *parent = 0);
    PlanningModel * model_;

~manifEditWidget();




private:

    static const int PointerRole = 1001;

    Ui::manifEditWidget *ui;




private slots:


    void Refresh();
void load(Equipe_ptr);
void load(Categorie_ptr);
void load(Lieu_ptr);

void onOkEq();
void onOkCat();
void onOkLi();

void onCancel();



};

#endif // MANIFEDITWIDGET_H
