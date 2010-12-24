#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_orgaCentral.h"
#include "planningmodel.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
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

    PlanningModel model_;
private slots:
    void onCancelOrgas();
    void onOkOrgaForm();
    void orgasRefresh();
    void searchOrgas();
    void listOrgaDoubleClicked(QModelIndex);
    void loadInPanel(Orga_ptr orga);

};

#endif // MAINWINDOW_H
