#ifndef lieuEditWidget_H
#define lieuEditWidget_H

#include <QWidget>
class lieuEditWidget;
#include "mainwindow.h"

namespace Ui {
    class lieuEditWidget;
}

class lieuEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit lieuEditWidget(QWidget *parent = 0);
    ~lieuEditWidget();
PlanningModel * model_;

private:



    enum State__
    {
        Insertion,
        Modification
    } State_;

static const int PointerRole = 1001;


    void clearForm();
        bool validateForm();
        void resetColorForm();

    static const QString ErrorStyle;
    static const QString ErrorMessage;
    static const QString ErrorDepartAnnee;
    static const QString ErrorStyleText;
    static const QString NoError;

    QAction *editAct;
    QAction *delAct;

    Lieu_ptr enModification;



    Ui::lieuEditWidget *ui;

private slots:
    void on_listWidget_doubleClicked(QModelIndex index);
    void on_btns_clicked(QAbstractButton* button);

    void onCancel();
    void onOk();
    void refresh();
    void edit();
    void del();

    void load(Lieu_ptr item);

signals :
        void selected(Lieu_ptr);



};

#endif // lieuEditWidget_H


