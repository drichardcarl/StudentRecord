#include "sr.h"
#include <QApplication>

#define DB "StudentRecord.db"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SR w;
    // check if database is present
    if (w.init(DB))
        return -1;

    w.show();
    return a.exec();
}
