#include "PartView.h"

#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkSmartPointer.h"

//for test
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"

Largix::PartView::PartView(QObject* parent):ObjectView(parent)
{
	_pActor = vtkSmartPointer<vtkActor>::New();

	//for test
	vtkNew<vtkCylinderSource> sphereSource;
	vtkNew<vtkPolyDataMapper> sphereMapper;
	sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
	_pActor->SetMapper(sphereMapper);
}

vtkSmartPointer<vtkProp> Largix::PartView::getActor()
{
	return _pActor;
}

ViewType Largix::PartView::getType() const
{
	return ViewType::PART;
}

void Largix::PartView::slotSizeChanged(const QSize& size)
{
	auto mapper = _pActor->GetMapper();
	emit signalRender();
}

void Largix::PartView::slotColorChanged(const QColor& color)
{
	_pActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
	emit signalRender();
}

void Largix::PartView::slotPointChanged(const QPoint3D& point)
{
	_pActor->SetPosition(point.x(), point.y(), point.z());
	emit signalRender();
}

void Largix::PartView::slotRotationChanged(const QRotation3D& rotation)
{
	_pActor->RotateX(rotation.x());
	_pActor->RotateY(rotation.y());
	_pActor->RotateZ(rotation.z());
	emit signalRender();
}

void Largix::PartView::slotTransparencyChanged(double transparency)
{
	_pActor->GetProperty()->SetOpacity(transparency);
	emit signalRender();
}

void Largix::PartView::slotVisibleChanged(double visible)
{
	_pActor->SetVisibility(visible);
	emit signalRender();
}
