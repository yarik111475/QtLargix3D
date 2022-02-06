#include "MainWindow.h"
#include <QtWidgets>
#include <QSurfaceFormat>
#include "QVTKOpenGLNativeWidget.h"

using namespace Largix;

int main(int argc, char *argv[])
{
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

