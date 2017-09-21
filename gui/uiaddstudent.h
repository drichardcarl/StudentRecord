#ifndef UIADDSTUDENT_H
#define UIADDSTUDENT_H

#include <QDialog>
#include "dbmanager.hpp"
#include "alert.hpp"

// just a GUI to help the user add a student into the database
namespace Ui {
class UIAddStudent;
}

class UIAddStudent : public QDialog
{
    Q_OBJECT

public:
    explicit UIAddStudent(DbManager* dbmngr, QDialog *parent = 0);
    ~UIAddStudent();

private slots:
    // when user clicks CANCEL button
    void on_ASUCancelBtn_clicked();
    // when user clicks ADD button
    void on_ASUAddBtn_clicked();

private:
    Ui::UIAddStudent *ui;
    DbManager* dbmngr;
};

#endif // UIADDSTUDENT_H
