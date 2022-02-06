#include "MainWindow.h"
#include <QtWidgets>

#include "Widget3D.h"
#include "PropertyView.h"
#include "ProjectController.h"


Largix::MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ProjectController* pController = new ProjectController(this);

    Widget3D* pWidget3D = pController->getWidget3D();
    PropertyView* pPropertyView=pController->getPropertyView();

    QDockWidget* pDock = createDockWidget();
    pDock->setWidget(pPropertyView);

    addDockWidget(Qt::LeftDockWidgetArea, pDock);
    setCentralWidget(pWidget3D);
    resize(800, 600);
}

QDockWidget* Largix::MainWindow::createDockWidget()
{
    QDockWidget* pDock = new QDockWidget(this);
    pDock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    pDock->setFeatures(QDockWidget::DockWidgetMovable);
    return pDock;
}
