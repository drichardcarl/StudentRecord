#include "sr.h"
#include "ui_sr.h"

SR::SR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SR)
{
    ui->setupUi(this);
}

SR::~SR()
{
    delete ui;
}
