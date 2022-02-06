#include "ProgramPropertyModel.h"
#include "qtpropertymanager.h"
#include "qtpropertybrowser.h"

Largix::ProgramPropertyModel::ProgramPropertyModel(const QString& title, QObject *parent)
	: PropertyModel(title, parent)
{
}

Largix::ProgramPropertyModel::~ProgramPropertyModel()
{
}

QtProperty* Largix::ProgramPropertyModel::getGroupProperty()
{
	QtGroupPropertyManager* pGroupManager = new QtGroupPropertyManager(this);
	QtProperty* pGroupProperty = pGroupManager->addProperty(_title);
	pGroupProperty->addSubProperty(_pVisibleProperty);
	pGroupProperty->addSubProperty(_pColorProperty);
	pGroupProperty->addSubProperty(_pPointProperty);
	pGroupProperty->addSubProperty(_pSizeProperty);
	pGroupProperty->addSubProperty(_pRotationProperty);
	pGroupProperty->addSubProperty(_pTransparencyProperty);
	return pGroupProperty;
}
