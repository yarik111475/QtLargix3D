#include "PartModel.h"
#include "PartPropertyModel.h"
#include "PropertyView.h"

Largix::PartModel::PartModel(QObject* parent) :ObjectModel(parent)
{
}

Largix::PropertyModel* Largix::PartModel::getPropertyModel(PropertyView* pPropertyView)
{
	PropertyModel* pModel = new PartPropertyModel("PartModel", this);
	pModel->setBrowser(pPropertyView->getBrowser());
	QObject::connect(pModel, &PropertyModel::signalPropertyChanged,
		this, &PartModel::slotPropertyChanged);
	return pModel;
}

void Largix::PartModel::slotPropertyChanged()
{
	PropertyModel* pModel = static_cast<PropertyModel*>(sender());
	if (pModel) {
		setSize(pModel->getSize());
		setColor(pModel->getColor());
		setPoint(pModel->getPoint());
		setRotation(pModel->getRotation());
		setTransparency(pModel->getTransparency());
		setVisible(pModel->getVisible());
	}
}
