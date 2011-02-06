#ifndef catEditWidget_H
#define catEditWidget_H

#include <QWidget>
class catEditWidget;
#include "mainwindow.h"

namespace Ui {
    class catEditWidget;
}

class catEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit catEditWidget(QWidget *parent = 0);
    ~catEditWidget();
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

    Categorie_ptr enModification;



    Ui::catEditWidget *ui;

private slots:
    void on_listWidget_doubleClicked(QModelIndex index);
    void on_btns_clicked(QAbstractButton* button);

    void onCancel();
    void onOk();
    void refresh();
    void edit();
    void del();

    void load(Categorie_ptr item);

signals :
        void selected(Categorie_ptr);



};

#endif // catEditWidget_H


