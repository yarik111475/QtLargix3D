#include "PartPropertyModel.h"
#include "qtpropertymanager.h"
#include "qtpropertybrowser.h"

Largix::PartPropertyModel::PartPropertyModel(const QString& title,QObject *parent)
	: PropertyModel(title, parent)
{
}

Largix::PartPropertyModel::~PartPropertyModel()
{
}

QtProperty* Largix::PartPropertyModel::getGroupProperty()
{
	QtGroupPropertyManager* pGroupManager = new QtGroupPropertyManager(this);
	QtProperty* pGroupProperty = pGroupManager->addProperty(_title);
	pGroupProperty->addSubProperty(_pVisibleProperty);
	pGroupProperty->addSubProperty(_pColorProperty);
	pGroupProperty->addSubProperty(_pPointProperty);
	pGroupProperty->addSubProperty(_pSizeProperty);
	pGroupProperty->addSubProperty(_pRotationProperty);
	pGroupProperty->addSubProperty(_pTransparencyProperty);
	pGroupProperty->addSubProperty(_pRepresentationProperty);
	return pGroupProperty;
}

PropertyType Largix::PartPropertyModel::getType() const
{
	return PropertyType::PART;
}
