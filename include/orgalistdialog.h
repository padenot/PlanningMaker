#ifndef ORGALISTDIALOG_H
#define ORGALISTDIALOG_H

#include "../include/precompiled.h"

#include <QxMemLeak.h>

#include <QDialog>

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
};

#endif // ORGALISTDIALOG_H
