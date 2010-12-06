#ifndef ORGALISTDIALOG_H
#define ORGALISTDIALOG_H

#include "../include/precompiled.h"

#include <QxMemLeak.h>

#include <QDialog>
#include <QtSql>

namespace Ui {
    class OrgaListDialog;
}

class OrgaListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OrgaListDialog(QWidget *parent = 0);
    ~OrgaListDialog();

private:
    Ui::OrgaListDialog *ui;
    QSqlTableModel *qsqm;

private slots:
    void on_pushButton_clicked();
};

#endif // ORGALISTDIALOG_H
