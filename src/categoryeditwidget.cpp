#include "categoryeditwidget.h"
#include "ui_categoryeditwidget.h"

categoryEditWidget::categoryEditWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::categoryEditWidget)
{
    ui->setupUi(this);
}

categoryEditWidget::~categoryEditWidget()
{
    delete ui;
}
