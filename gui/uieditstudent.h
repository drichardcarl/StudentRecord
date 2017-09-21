#ifndef UIEDITSTUDENT_H
#define UIEDITSTUDENT_H

#include <QDialog>
#include <QList>
#include <QTableWidgetItem>
#include "dbmanager.hpp"
#include "alert.hpp"

// just a GUI to help the user edit a student's record in the database
namespace Ui {
class UIEditStudent;
}

class UIEditStudent : public QDialog
{
    Q_OBJECT

public:
    explicit UIEditStudent(DbManager* dbmngr, QDialog *parent = 0);
    ~UIEditStudent();
    void init(QList<QTableWidgetItem*> data);

private slots:
    // when user clicks the CANCEL ( X ) button
    void on_ESUCancelBtn_clicked();
    // when user clicks the SAVE ( $ ) button
    void on_ESUSaveBtn_clicked();

private:
    Ui::UIEditStudent *ui;
    DbManager* dbmngr;
};

#endif // UIEDITSTUDENT_H
