#include "PartModel.h"
#include "PartPropertyModel.h"
#include "PropertyView.h"

Largix::PartModel::PartModel(QObject* parent) :ObjectModel(parent)
{
}

Largix::PropertyModel* Largix::PartModel::getPropertyModel(PropertyView* pPropertyView)
{
	PartPropertyModel* pModel = new PartPropertyModel("PartModel", this);
	pModel->setBrowser(pPropertyView->getBrowser());
	
	QObject::connect(pModel, &PartPropertyModel::signalSizeChanged,
		this, &PartModel::slotSizeChanged);
	QObject::connect(pModel, &PartPropertyModel::signalColorChanged,
		this, &PartModel::slotColorChanged);
	QObject::connect(pModel, &PartPropertyModel::signalPointChanged,
		this, &PartModel::slotPointChanged);
	QObject::connect(pModel, &PartPropertyModel::signalRotationChanged,
		this, &PartModel::slotRotationChanged);
	QObject::connect(pModel, &PartPropertyModel::signalTransparencyChanged,
		this, &PartModel::slotTransparencyChanged);
	QObject::connect(pModel, &PartPropertyModel::signalVisibleChanged,
		this, &PartModel::slotVisibleChanged);
	return pModel;
}

void Largix::PartModel::slotSizeChanged(const QSize& size)
{
	setSize(size);
}

void Largix::PartModel::slotColorChanged(const QColor& color)
{
	setColor(color);
}

void Largix::PartModel::slotPointChanged(const QPoint3D& point)
{
	setPoint(point);
}

void Largix::PartModel::slotRotationChanged(const QRotation3D& rotation)
{
	setRotation(rotation);
}

void Largix::PartModel::slotTransparencyChanged(double transparency)
{
	setTransparency(transparency);
}

void Largix::PartModel::slotVisibleChanged(bool visible)
{
	setVisible(visible);
}