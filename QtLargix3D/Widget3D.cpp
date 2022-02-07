#include <QtWidgets>
#include "Widget3D.h"
#include "ObjectView.h"

#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkAxesActor.h"
#include "vtkPolarAxesActor.h"
#include "vtkCamera.h"
#include "vtkRenderWindow.h"
#include "vtkRenderer.h"
#include "vtkNamedColors.h"
#include "vtkSmartPointer.h"
#include "vtkGenericOpenGLRenderWindow.h"
#include "QVTKOpenGLNativeWidget.h"

Largix::Widget3D::Widget3D(QWidget *parent) : QWidget(parent)
{
	vtkNew<vtkNamedColors> colors;
	_renderer = vtkSmartPointer<vtkRenderer>::New();
	_renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());
	_renderer->ResetCamera();

	_renderWindow = vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
	_renderWindow->AddRenderer(_renderer);

	_widget = new QVTKOpenGLNativeWidget(this);
	_widget->setRenderWindow(_renderWindow);
	//vtkCamera* pCamera = _renderer->GetActiveCamera();
	
	addAxes();

	QVBoxLayout* pVBoxLayout = new QVBoxLayout;
	pVBoxLayout->addWidget(_widget);
	setLayout(pVBoxLayout);
}

Largix::Widget3D::~Widget3D()
{
}

void Largix::Widget3D::addView(ObjectView* pView)
{
	ViewType type = pView->getType();
	if (_viewHash.contains(type)) {
		return;
	}
	QObject::connect(pView, &ObjectView::signalRender,
		this, &Widget3D::slotRender);
	_viewHash.insert(type, pView);
	_renderer->AddActor(pView->getActor());
	_renderer->ResetCamera();
	_renderWindow->Render();
}

void Largix::Widget3D::removeView(ViewType type)
{
	if (_viewHash.contains(type)) {
		_renderer->RemoveActor(_viewHash.value(type)->getActor());
		_renderWindow->Render();
		_viewHash.remove(type);
	}
}

Largix::ObjectView* Largix::Widget3D::getViewByType(ViewType type)
{
	if (_viewHash.contains(type)) {
		return _viewHash.value(type);
	}
	return nullptr;
}

void Largix::Widget3D::addAxes()
{
	vtkSmartPointer<vtkAxesActor> pAxes = vtkSmartPointer<vtkAxesActor>::New();
	pAxes->SetXAxisLabelText("");
	pAxes->SetYAxisLabelText("");
	pAxes->SetZAxisLabelText("");
	_renderer->AddActor(pAxes);
}

void Largix::Widget3D::slotRender() 
{
	_renderWindow->Render();
}
