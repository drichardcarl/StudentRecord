#ifndef SR_H
#define SR_H

#include <QWidget>
#include <QSqlTableModel>
#include "uieditstudent.h"
#include "uiaddstudent.h"
#include "dbmanager.hpp"

namespace Ui {
class SR;
}

class SR : public QWidget
{
    Q_OBJECT

public:
    explicit SR(QWidget *parent = 0);
    int init(const QString& db);
    ~SR();

private slots:
    void on_AddBtn_clicked();

    void on_EditBtn_clicked();

    void on_DeleteBtn_clicked();

    void on_SearchBar_returnPressed();

    void on_SearchBar_textChanged(const QString &arg1);

private:
    Ui::SR *ui;
    DbManager* dbmngr;
    QSqlTableModel* model;

    void _load();
};

#endif // SR_H
