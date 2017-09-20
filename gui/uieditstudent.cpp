#include "uieditstudent.h"
#include "ui_uieditstudent.h"

UIEditStudent::UIEditStudent(DbManager* dbmngr,QDialog *parent) :
    QDialog(parent),
    dbmngr(dbmngr),
    ui(new Ui::UIEditStudent)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow);
}

UIEditStudent::~UIEditStudent()
{
    delete ui;
}

void UIEditStudent::on_ESUCancelBtn_clicked()
{
    this->close();
}

void UIEditStudent::on_ESUSaveBtn_clicked()
{
    QString lname = ui->txtLName->text().toUpper(),
            fname = ui->txtFName->text().toUpper(),
            mname = ui->txtMName->text().toUpper(),
            idNo = ui->txtIDNo->text().toUpper(),
            course = ui->txtCourse->text().toUpper();

    // check for empty fields
    if (lname.isEmpty()){
        alert(1,
              "Invalid Input",
              "<LAST NAME> cannot be empty!");
        return;
    }
    if (fname.isEmpty()){
        alert(1,
              "Invalid Input",
              "<FIRST NAME> cannot be empty!");
        return;
    }
    if (course.isEmpty()){
        alert(1,
              "Invalid Input",
              "<COURSE> cannot be empty!");
        return;
    }

    this->dbmngr->updateStudent(lname, fname, mname, idNo, course);
    alert(0, "Status", "Student's record was successfully updated.");
    this->close();
}

void UIEditStudent::init(QList<QTableWidgetItem*> data)
{
    ui->txtLName->setText(data.at(0)->text());
    ui->txtFName->setText(data.at(1)->text());
    ui->txtMName->setText(data.at(2)->text());
    ui->txtIDNo->setText(data.at(3)->text());
    ui->txtCourse->setText(data.at(4)->text());
}
