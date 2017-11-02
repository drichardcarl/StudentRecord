#include "sr.h"
#include "ui_sr.h"

SR::SR(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SR),
    dbmngr(nullptr)
{
    ui->setupUi(this);
    startTimer(500);
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
        for (int j=1; j<7; ++j){
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
    UIAddEditStudent win(dbmngr);
    if (win.exec()){ // cancel button was not pressed
        _load();
        ui->SRDisplay->selectRow(ui->SRDisplay->rowCount()-1); // select last row
        ui->SRDisplay->setFocus();
        return;
    }
    // if cancel, clear selection
    ui->SRDisplay->clearSelection();
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
    UIAddEditStudent win(dbmngr);
    win.editMode(ui->SRDisplay->selectedItems());
    if (win.exec()){ // cancel button was not pressed
        _load();
        ui->SRDisplay->selectRow(r); // select last selected row
        ui->SRDisplay->setFocus();
        return;
    }
    // if cancel, clear selection//*
    ui->SRDisplay->clearSelection();
}

void SR::on_DeleteBtn_clicked()
{
    if (ui->SRDisplay->selectedItems().isEmpty()){
        alert(1,
              "Empty selection",
              "Please select a record to delete.");
        return;
    }

    if (alert(3,
          "Confirm Action",
          "Are you sure you want to delete the selected record?")
            == QMessageBox::Yes){
        // delete student with the ID No.
        dbmngr->deleteStudent(ui->SRDisplay->selectedItems().at(3)->text());
        alert(0,
              "Result",
              "Delete successful.");
        _load();
    }
    // clear selection
    ui->SRDisplay->clearSelection();
}

// * establishes the lower and upper bounds for searching
// * e.g. if SEARCH BAR contains "2014-" then
//   the lower bound for searching ID No. is "2014-0000"
//   and the upper bound is "2014-9999"
void SR::on_SearchBar_textChanged(const QString &arg1)
{
    // if search bar is empty load the data
    if (ui->SearchBar->text().isEmpty()){
        _load();
        return;
    }
    // it's time for search and display!!
    // search columns with values containing the string to search for
    // e.g if user want to search for students having 'carl' as first name
    //     the query would be SELECT * FROM students WHERE firstName LIKE "%carl%".
    //     Note that the search is CASE-INSENSITIVE.
    QString searchInput = ui->SearchBar->text();
    searchInput = "%" + searchInput + "%";
    QSqlQuery q;
    q.prepare("SELECT * "
              "FROM students "
              "WHERE lastName LIKE ? OR firstName LIKE ? OR middleName LIKE ? OR idNo LIKE ? OR course LIKE ? OR gender LIKE ?");
    q.addBindValue(searchInput);
    q.addBindValue(searchInput);
    q.addBindValue(searchInput);
    q.addBindValue(searchInput);
    q.addBindValue(searchInput);
    q.addBindValue(searchInput);
    q.exec();
    // update the display
    int i = 0;
    ui->SRDisplay->setRowCount(i);
    while(q.next()){
        ui->SRDisplay->setRowCount(i+1);
        for (int j=1; j<7; ++j){
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setTextAlignment(Qt::AlignCenter);
            item->setText(q.value(j).toString());
            ui->SRDisplay->setItem(i, j-1, item);
        }
        ++i;
    }

}
