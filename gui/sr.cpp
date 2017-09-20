#include "sr.h"
#include "ui_sr.h"

SR::SR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SR),
    dbmngr(nullptr),
    model(nullptr)
{
    ui->setupUi(this);
}

SR::~SR()
{
    delete ui;
}

int SR::init(const QString& db){
    dbmngr = new DbManager;
    if (dbmngr->open(db))
        return -1;

    _load();
    return 0;
}

// * load the data from the database to the table
// * selects all rows from table 'students'
//   and then display the data using the table widget
void SR::_load(){
    ui->SRDisplay->setColumnWidth(0,120);
    ui->SRDisplay->setColumnWidth(1,160);
    ui->SRDisplay->setColumnWidth(2,120);
    // database is already opened
    QSqlQuery query;
    query.exec("SELECT * FROM students");
    int i = 0;
    while(query.next()){
        ui->SRDisplay->setRowCount(i+1);
        for (int j=1; j<6; ++j){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setTextAlignment(Qt::AlignCenter);
            item->setText(query.value(j).toString());
            ui->SRDisplay->setItem(i, j-1, item);
        }
        ++i;
    }
}

void SR::on_AddBtn_clicked()
{
    UIAddStudent win(dbmngr);
    win.exec();
    _load();
    ui->SRDisplay->scrollToBottom(); // select last row
    ui->SRDisplay->setFocus();
}

void SR::on_EditBtn_clicked()
{
    if (ui->SRDisplay->selectedItems().isEmpty()){
        alert(1,
              "Empty selection",
              "Please select a record to edit.");
        return;
    }
    int r = ui->SRDisplay->selectedItems().at(0)->row();
    UIEditStudent win(dbmngr);
    win.init(ui->SRDisplay->selectedItems());
    win.exec();
    _load();
    ui->SRDisplay->selectRow(r);
    ui->SRDisplay->setFocus();
}
