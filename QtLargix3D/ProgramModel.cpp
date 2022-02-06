#include "ProgramModel.h"
#include "ProgramPropertyModel.h"
#include "PropertyView.h"

Largix::ProgramModel::ProgramModel(QObject* parent):ObjectModel(parent)
{
}

Largix::PropertyModel* Largix::ProgramModel::getPropertyModel(PropertyView* pPropertyView)
{
	ProgramPropertyModel* pModel = new ProgramPropertyModel("ProgramModel", this);
	pModel->setBrowser(pPropertyView->getBrowser());
	
	return pModel;
}

void Largix::ProgramModel::slotSizeChanged(const QSize& size)
{
}
void Largix::ProgramModel::slotColorChanged(const QColor& color)
{
}

void Largix::ProgramModel::slotPointChanged(const QPoint3D& point)
{
}

void Largix::ProgramModel::slotRotationChanged(const QRotation3D& rotation)
{
}

void Largix::ProgramModel::slotTransparencyChanged(double transparency)
{
}

void Largix::ProgramModel::slotVisibleChanged(bool visible)
{
}
