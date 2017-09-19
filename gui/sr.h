#ifndef SR_H
#define SR_H

#include <QWidget>
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

private:
    Ui::SR *ui;
    DbManager* dbmngr;

    void _load();
};

#endif // SR_H
