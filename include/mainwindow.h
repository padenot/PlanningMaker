#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class MainWindow;
#include "ui_orgaCentral.h"
#include "planningmodel.h"
#include "orgaeditwidget.h"
#include "orgaselectwidget.h"
#include "manifeditwidget.h"


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    static const QString ErrorStyle;
    static const QString ErrorMessage;
    static const QString ErrorDepartAnnee;
    static const QString ErrorStyleText;
    static const QString NoError;

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


    orgaEditWidget *oew;
    orgaSelectWidget *osw;


    static const int PointerRole = 1001;


    void clearOrgaForm();
        bool validateOrgaForm();
        void resetColorOrgaForm();






    PlanningModel model_;

    void closeEvent(QCloseEvent *event);
private slots:

    void readSettings();
    void showOrgaEditPanel();






};

#endif // MAINWINDOW_H
