#ifndef MANIFEDITWIDGET_H
#define MANIFEDITWIDGET_H

#include <QWidget>
 #include <QListWidgetItem>
class manifEditWidget;
#include "mainwindow.h"

namespace Ui {
    class manifEditWidget;
}

class manifEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit manifEditWidget(QWidget *parent = 0);
    PlanningModel * model_;






private:

    static const int PointerRole = 1001;

    Ui::manifEditWidget *ui;

    ~manifEditWidget();


private slots:


    void Refresh();


};

#endif // MANIFEDITWIDGET_H
