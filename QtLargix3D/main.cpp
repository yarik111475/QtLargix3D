#include "MainWindow.h"
#include <QtWidgets/QApplication>

using namespace Largix;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

