#include "uieditcourses.h"
#include "ui_uieditcourses.h"

UIEditCourses::UIEditCourses(DbManager* dbmngr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIEditCourses),
    dbmngr(dbmngr)
{
    ui->setupUi(this);
    loadCourses();
}

UIEditCourses::~UIEditCourses()
{
    delete ui;
}

void UIEditCourses::on_pbtnAdd_clicked()
{
    if (!ui->leCourse->text().isEmpty()){
        dbmngr->addCourse(ui->leCourse->text());
        loadCourses();
    }
}

void UIEditCourses::loadCourses(){
//    qDebug() << dbmngr->getAllCourses();
    ui->lstCourses->clear();
    ui->lstCourses->addItems(dbmngr->getAllCourses());
    ui->leCourse->clear();
}

void UIEditCourses::on_lstCourses_currentTextChanged(const QString &currentText)
{
    lastSelectedItem = currentText;
}

void UIEditCourses::on_pbtnRemove_clicked()
{
    if (!lastSelectedItem.isEmpty()){
        dbmngr->deleteCourse(lastSelectedItem);
        lastSelectedItem = "";
        loadCourses();
    }

}
