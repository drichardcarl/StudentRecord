#ifndef UIEDITCOURSES_H
#define UIEDITCOURSES_H

#include <QDialog>
#include <QDebug>
#include "dbmanager.hpp"

namespace Ui {
class UIEditCourses;
}

class UIEditCourses : public QDialog
{
    Q_OBJECT

public:
    explicit UIEditCourses(DbManager* dbmngr, QWidget *parent = 0);
    ~UIEditCourses();

private slots:
    void on_pbtnAdd_clicked();
    void loadCourses();

    void on_lstCourses_currentTextChanged(const QString &currentText);

    void on_pbtnRemove_clicked();

private:
    Ui::UIEditCourses *ui;
    DbManager* dbmngr;

    QString lastSelectedItem;
};

#endif // UIEDITCOURSES_H
