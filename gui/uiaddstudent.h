#ifndef UIADDSTUDENT_H
#define UIADDSTUDENT_H

#include <QDialog>
#include <QList>
#include <QTableWidgetItem>
#include "dbmanager.hpp"
#include "alert.hpp"
#include "uieditcourses.h"

// just a GUI to help the user add a student into the database
namespace Ui {
class UIAddStudent;
}

class UIAddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit UIAddStudent(DbManager* dbmngr, QDialog *parent = 0);
    void editMode(QList<QTableWidgetItem*> data);
    ~UIAddStudent();

private slots:
    // when user clicks CANCEL ( X ) button
    void on_ASUCancelBtn_clicked();
    // when user clicks ADD ( + ) button
    void on_ASUAddBtn_clicked();

    void on_cbxCourse_currentTextChanged(const QString &arg1);
    void loadCourses();

private:
    Ui::UIAddStudent *ui;
    DbManager* dbmngr;
    bool isOnEditMode = false;
};

#endif // UIADDSTUDENT_H
