#include "MainWindow.h"
#include <QtWidgets>

#include "PropertyView.h"
#include "ProjectController.h"


Largix::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ProjectController* pController = new ProjectController(this);
    PropertyView* propertyView=pController->getPropertyView();
    setCentralWidget(propertyView);
}

