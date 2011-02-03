#ifndef ORGASELECTWIDGET_H
#define ORGASELECTWIDGET_H

#include <QWidget>
class orgaSelectWidget;
#include "mainwindow.h"

namespace Ui {
    class orgaSelectWidget;
}

class orgaSelectWidget : public QWidget
{
    Q_OBJECT

public:
    explicit orgaSelectWidget(QWidget *parent = 0);
    ~orgaSelectWidget();

    PlanningModel * model_;

private:
    Ui::orgaSelectWidget *ui;

    static const int PointerRole = 1001;
    QAction *editAct;
    QAction *delAct;

private slots:
   void on_listWidgetOrga_doubleClicked(QModelIndex index);
   void Refresh();
   void editOrga();
   void delOrga();

signals :
        void orgaSelected(Orga_ptr);

};



#endif // ORGASELECTWIDGET_H


