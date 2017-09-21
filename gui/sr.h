#ifndef SR_H
#define SR_H

#include <QWidget>
#include "uieditstudent.h"
#include "uiaddstudent.h"
#include "dbmanager.hpp"

// SR = StudentRecord
// * just a GUI to help the user visualize the database
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
    // when user clicks the ADD button
    void on_AddBtn_clicked();
    // when user clicks the EDIT button
    void on_EditBtn_clicked();
    // when user clicks the DELETE button
    void on_DeleteBtn_clicked();
    // when text on the SEARCH BAR has changed
    void on_SearchBar_textChanged(const QString &arg1);

private:
    Ui::SR *ui;
    DbManager* dbmngr;

    void _load();
};

#endif // SR_H
