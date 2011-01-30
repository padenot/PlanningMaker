#ifndef ORGAEDITWIDGET_H
#define ORGAEDITWIDGET_H

#include <QWidget>
class orgaEditWidget;
#include "mainwindow.h"

namespace Ui {
    class orgaEditWidget;
}

class orgaEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit orgaEditWidget(QWidget *parent = 0);
    ~orgaEditWidget();
PlanningModel * model_;

private:

    enum Tabs
    {
        Orgas,
        Taches,
        Materiel
    };

    enum State__
    {
        Insertion,
        Modification
    } State_;

static const int PointerRole = 1001;


    void clearOrgaForm();
        bool validateOrgaForm();
        void resetColorOrgaForm();

    static const QString ErrorStyle;
    static const QString ErrorMessage;
    static const QString ErrorDepartAnnee;
    static const QString ErrorStyleText;
    static const QString NoError;

    Orga_ptr enModification;



    Ui::orgaEditWidget *ui;

private slots:
    void onCancelOrgas();
    void onOkOrgaForm();


    void loadInPanel(Orga_ptr orga);



};

#endif // ORGAEDITWIDGET_H
