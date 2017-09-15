#include "sr.h"
#include "ui_sr.h"

SR::SR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SR)
{
    ui->setupUi(this);
    initTable();
}

SR::~SR()
{
    delete ui;
}

SR::initTable()
{
    ui->SRDisplay->setColumnWidth(1,200);

    ui->SRDisplay->setRowCount(1);
    QTableWidgetItem* item = new QTableWidgetItem;
    item->setTextAlignment(Qt::AlignCenter);
    item->setText("DUMDUM");
    ui->SRDisplay->setItem(0,0,item);
}
