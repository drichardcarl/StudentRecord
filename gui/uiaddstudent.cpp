#include "uiaddstudent.h"
#include "ui_uiaddstudent.h"

UIAddStudent::UIAddStudent(DbManager* dbmngr,QDialog *parent) :
    QDialog(parent),
    dbmngr(dbmngr),
    ui(new Ui::UIAddStudent)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow);
}

UIAddStudent::~UIAddStudent()
{
    delete ui;
}

void UIAddStudent::on_ASUCancelBtn_clicked()
{
    this->close();
}

void UIAddStudent::on_ASUAddBtn_clicked()
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
    if (idNo.isEmpty()){
        alert(1,
              "Invalid Input",
              "<ID NO.> cannot be empty!");
        return;
    }
    if (course.isEmpty()){
        alert(1,
              "Invalid Input",
              "<COURSE> cannot be empty!");
        return;
    }

    this->dbmngr->addPerson(lname, fname, mname, idNo, course);
    alert(0, "Status", "Student Added.");
    this->close();
}
