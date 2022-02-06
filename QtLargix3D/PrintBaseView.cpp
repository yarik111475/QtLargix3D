#include "PrintBaseView.h"

#include "vtkNew.h"
#include "vtkActor.h"
#include "vtkSmartPointer.h"


Largix::PrintBaseView::PrintBaseView(QObject* parent):ObjectView(parent)
{
	_pActor = vtkSmartPointer<vtkActor>::New();
}

vtkSmartPointer<vtkProp> Largix::PrintBaseView::getActor()
{
	return _pActor;
}

ViewType Largix::PrintBaseView::getType() const
{
	return ViewType::PRINTBASE;
}

void Largix::PrintBaseView::slotSizeChanged(const QSize& size)
{

}

void Largix::PrintBaseView::slotColorChanged(const QColor& color)
{

}

void Largix::PrintBaseView::slotPointChanged(const QPoint3D& point)
{
	_pActor->SetPosition(point.x(), point.y(), point.z());
}

void Largix::PrintBaseView::slotRotationChanged(const QRotation3D& rotation)
{

}

void Largix::PrintBaseView::slotTransparencyChanged(double transparency)
{

}

void Largix::PrintBaseView::slotVisibleChanged(double visible)
{

}

