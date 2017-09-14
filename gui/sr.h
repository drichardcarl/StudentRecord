#ifndef SR_H
#define SR_H

#include <QWidget>

namespace Ui {
class SR;
}

class SR : public QWidget
{
    Q_OBJECT

public:
    explicit SR(QWidget *parent = 0);
    ~SR();

private:
    Ui::SR *ui;
};

#endif // SR_H
