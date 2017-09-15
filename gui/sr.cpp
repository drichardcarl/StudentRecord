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

int SR::init(const QString& db){
    DbManager dbmngr;
    if (dbmngr.open(db))
        return -1;

    dbmngr.addPerson("DUMDUM",
                     "CARL RICHARD",
                     "MALAYAG",
                     "2014-0367",
                     "BSEC");
    return 0;
}

