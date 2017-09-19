#ifndef UIADDSTUDENT_H
#define UIADDSTUDENT_H

#include <QDialog>
#include "dbmanager.hpp"
#include "alert.hpp"

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
    void on_ASUCancelBtn_clicked();

    void on_ASUAddBtn_clicked();

private:
    Ui::UIAddStudent *ui;
    DbManager* dbmngr;
};

#endif // UIADDSTUDENT_H
