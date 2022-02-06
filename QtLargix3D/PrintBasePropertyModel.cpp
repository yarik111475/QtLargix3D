#include "PrintBasePropertyModel.h"
#include "qtpropertymanager.h"
#include "qtpropertybrowser.h"

Largix::PrintBasePropertyModel::PrintBasePropertyModel(const QString& title, QObject *parent)
	: PropertyModel(title, parent)
{
}

Largix::PrintBasePropertyModel::~PrintBasePropertyModel()
{
}

QtProperty* Largix::PrintBasePropertyModel::getGroupProperty()
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
