#include "qwidget.h"
#include "./ui_qwidget.h"

Qwidget::Qwidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Qwidget)
{
    ui->setupUi(this);
}

Qwidget::~Qwidget()
{
    delete ui;
}

