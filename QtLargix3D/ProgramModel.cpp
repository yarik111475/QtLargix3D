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
	QObject::connect(pModel, &PropertyModel::signalPropertyChanged,
		this, &ProgramModel::slotPropertyChanged);
	return pModel;
}

void Largix::ProgramModel::slotPropertyChanged()
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
