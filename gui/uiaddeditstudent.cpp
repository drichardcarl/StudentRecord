#include "uiaddeditstudent.h"
#include "ui_uiaddstudent.h"

UIAddEditStudent::UIAddEditStudent(DbManager* dbmngr,QDialog *parent) :
    QDialog(parent),
    ui(new Ui::UIAddEditStudent),
    dbmngr(dbmngr)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::SubWindow);
    loadCourses();
}

UIAddEditStudent::~UIAddEditStudent()
{
    delete ui;
}

void UIAddEditStudent::on_ASUCancelBtn_clicked()
{
    this->reject();
}

// * the user can't add if all the fields are empty except for <MIDDLE NAME>
// * performs a verification if the sepcidied ID No. is already taken or not
void UIAddEditStudent::on_ASUAddBtn_clicked()
{
    QString lname = ui->txtLName->text(),
            fname = ui->txtFName->text(),
            mname = ui->txtMName->text(),
            idNo = ui->txtIDNo->text(),
            course = ui->cbxCourse->currentText(),
            gender = (ui->rbMale->isChecked()) ? ui->rbMale->text() : ui->rbFemale->text();

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
    if (idNo.isEmpty() || idNo.count() < 9){
        alert(1,
              "Invalid Input",
              "<ID NO.> cannot be empty or incomplete!");
        return;
    }
    if (course.isEmpty()){
        alert(1,
              "Invalid Input",
              "<COURSE> cannot be empty!");
        return;
    }
    if (!isOnEditMode){
        if (this->dbmngr->idNoIsTaken(idNo)){
            alert(1,
                  "Invalid Input",
                  "ID No. must be unique!\nYou may edit the existing record.");
            return;
        }
    }

    if (!(ui->rbMale->isChecked() || ui->rbFemale->isChecked())){
        alert(1,
              "Invalid Input",
              "Please select a gender.");
        return;
    }
    if (!isOnEditMode){
        this->dbmngr->addStudent(lname, fname, mname, idNo, course, gender);
        alert(0, "Status", "Student Added.");
    }
    else {
        this->dbmngr->updateStudent(lname, fname, mname, idNo, course, gender);
        alert(0, "Status", "Student's record was successfully updated.");
    }
    this->accept();
}

void UIAddEditStudent::on_cbxCourse_currentTextChanged(const QString &arg1)
{
    if (arg1 == "[edit]"){
        UIEditCourses win(dbmngr);
        win.exec();
        loadCourses();
    }
}

void UIAddEditStudent::loadCourses(){
    ui->cbxCourse->clear();
    ui->cbxCourse->addItems(dbmngr->getAllCourses());
    ui->cbxCourse->addItem("[edit]");
}

void UIAddEditStudent::editMode(QList<QTableWidgetItem*> data){
    isOnEditMode = true;
    ui->txtIDNo->setEnabled(false);
    ui->ASUAddBtn->setText("$");

    ui->txtLName->setText(data.at(0)->text());
    ui->txtFName->setText(data.at(1)->text());
    ui->txtMName->setText(data.at(2)->text());
    ui->txtIDNo->setText(data.at(3)->text());
    ui->cbxCourse->setCurrentText(data.at(4)->text());

    if (data.at(5)->text() == "Male")
        ui->rbMale->setChecked(true);
    else
        ui->rbFemale->setChecked(true);
}
