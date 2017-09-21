#include "alert.hpp"

int alert(int type, QString title, QString msg){
    switch (type) {
    // information
    case 0:
        return QMessageBox::information(0, title, msg);
        break;
    // warning
    case 1:
        return QMessageBox::warning(0, title, msg);
        break;
    // critical
    case 2:
        return QMessageBox::critical(0, title, msg);
        break;
    // critical with custom buttons
    case 3:
        return QMessageBox::critical(0, title, msg, QMessageBox::Yes, QMessageBox::No);
        break;
    }
}
