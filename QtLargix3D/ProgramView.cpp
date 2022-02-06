#include "ProgramView.h"

#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkSmartPointer.h"

Largix::ProgramView::ProgramView(QObject* parent):ObjectView(parent)
{
	_pActor = vtkNew<vtkActor>();
}

vtkSmartPointer<vtkProp> Largix::ProgramView::getActor()
{
	return _pActor;
}

ViewType Largix::ProgramView::getType() const
{
	return ViewType::PROGRAM;
}

void Largix::ProgramView::slotSizeChanged(const QSize& size)
{

}

void Largix::ProgramView::slotColorChanged(const QColor& color)
{

}

void Largix::ProgramView::slotPointChanged(const QPoint3D& point)
{
	_pActor->SetPosition(point.x(), point.y(), point.z());
}

void Largix::ProgramView::slotRotationChanged(const QRotation3D& rotation)
{

}

void Largix::ProgramView::slotTransparencyChanged(double transparency)
{

}

void Largix::ProgramView::slotVisibleChanged(double visible)
{

}
