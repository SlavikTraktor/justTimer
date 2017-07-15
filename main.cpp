#include "stimer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    STimer w;
    w.show();

    return a.exec();
}
