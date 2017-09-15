#include "alert.hpp"

void alert(int type, QString title, QString msg){
    switch (type) {
    // information
    case 0:
        QMessageBox::information(0, title, msg);
        break;
    // warning
    case 1:
        QMessageBox::warning(0, title, msg);
        break;
    case 2:
        QMessageBox::critical(0, title, msg);
        break;
    }
}
