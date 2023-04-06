#include <QApplication>
#include "counter.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Counter w;
    w.show();
    return a.exec();
}
