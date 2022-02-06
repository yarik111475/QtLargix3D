#include "PartView.h"

#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkProperty.h"
#include "vtkSmartPointer.h"

//for test
#include "vtkSphereSource.h"
#include "vtkPolyDataMapper.h"
#include "vtkCylinderSource.h"
#include "vtkTransform.h"

Largix::PartView::PartView(QObject* parent):ObjectView(parent)
{
	_pActor = vtkSmartPointer<vtkActor>::New();

	//for test
	vtkNew<vtkCylinderSource> sphereSource;
	vtkNew<vtkPolyDataMapper> sphereMapper;
	sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
	_pActor->SetMapper(sphereMapper);
	//_pActor->SetPosition(0, 0, 0);
	_pActor->SetOrigin(0, 0, 0);
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
	emit signalRender();
}

void Largix::PartView::slotColorChanged(const QColor& color)
{
	_pActor->GetProperty()->SetColor(color.redF(), color.greenF(), color.blueF());
	emit signalRender();
}

void Largix::PartView::slotPointChanged(const QPoint3D& point)
{
	vtkTransform* pTransform = vtkTransform::New();
	pTransform->Translate(point.x(), point.y(), point.z());
	_pActor->SetUserTransform(pTransform);
	emit signalRender();
}

void Largix::PartView::slotRotationChanged(const QRotation3D& rotation)
{
	vtkTransform* pTransform = vtkTransform::New();
	pTransform->RotateX(rotation.x());
	pTransform->RotateY(rotation.y());
	pTransform->RotateZ(rotation.z());
	_pActor->SetUserTransform(pTransform);
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

void Largix::PartView::slotRepresentationChanged(RepresentationMode representation)
{
	switch (representation) {
	case RepresentationMode::SURFACE:
		_pActor->GetProperty()->EdgeVisibilityOff();
		_pActor->GetProperty()->SetRepresentationToSurface();
		break;
	case RepresentationMode::WIREFRAME:
		_pActor->GetProperty()->EdgeVisibilityOff();
		_pActor->GetProperty()->SetRepresentationToWireframe();
		break;
	case RepresentationMode::COMPLEX:
		_pActor->GetProperty()->EdgeVisibilityOn();
		_pActor->GetProperty()->SetEdgeColor(0, 0, 0);
		_pActor->GetProperty()->SetRepresentationToSurface();
		break;
	}
	emit signalRender();
}
