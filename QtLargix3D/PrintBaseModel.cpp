#include "PrintBaseModel.h"
#include "PrintBasePropertyModel.h"
#include "PropertyView.h"

Largix::PrintBaseModel::PrintBaseModel(QObject* parent):ObjectModel(parent)
{
}

Largix::PropertyModel* Largix::PrintBaseModel::getPropertyModel(PropertyView* pPropertyView)
{
	PrintBasePropertyModel* pModel = new PrintBasePropertyModel("PrintBaseModel", this);
	pModel->setBrowser(pPropertyView->getBrowser());
	
	return pModel;
}

void Largix::PrintBaseModel::slotSizeChanged(const QSize& size)
{
}
void Largix::PrintBaseModel::slotColorChanged(const QColor& color)
{
}

void Largix::PrintBaseModel::slotPointChanged(const QPoint3D& point)
{
}

void Largix::PrintBaseModel::slotRotationChanged(const QRotation3D& rotation)
{
}

void Largix::PrintBaseModel::slotTransparencyChanged(double transparency)
{
}

void Largix::PrintBaseModel::slotVisibleChanged(bool visible)
{
}