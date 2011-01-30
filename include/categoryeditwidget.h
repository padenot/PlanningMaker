#ifndef CATEGORYEDITWIDGET_H
#define CATEGORYEDITWIDGET_H

#include <QWidget>

namespace Ui {
    class categoryEditWidget;
}

class categoryEditWidget : public QWidget
{
    Q_OBJECT

public:
    explicit categoryEditWidget(QWidget *parent = 0);
    ~categoryEditWidget();

private:
    Ui::categoryEditWidget *ui;
};

#endif // CATEGORYEDITWIDGET_H
