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
	QObject::connect(pModel, &PropertyModel::signalPropertyChanged,
		this, &PrintBaseModel::slotPropertyChanged);
	return pModel;
}

void Largix::PrintBaseModel::slotPropertyChanged()
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