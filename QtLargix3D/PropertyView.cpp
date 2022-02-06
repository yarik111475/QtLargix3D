#include "PropertyView.h"
#include "PropertyModel.h"
#include "qtpropertybrowser.h"
#include "qttreepropertybrowser.h"
#include <QtWidgets>

Largix::PropertyView::PropertyView(QWidget *parent) : QWidget(parent), _pBrowser(new QtTreePropertyBrowser(parent))
{
	QVBoxLayout* pVBoxLayout = new QVBoxLayout;
	pVBoxLayout->setContentsMargins(5, 5, 5, 5);
	pVBoxLayout->addWidget(_pBrowser);
	setLayout(pVBoxLayout);
}

void Largix::PropertyView::addProperty(PropertyType type, PropertyModel* pPropertyModel)
{
	if (_properties.contains(type)) {
		return;
	}
	_properties.insert(type, pPropertyModel);
	_pBrowser->addProperty(pPropertyModel->getGroupProperty());
}

void Largix::PropertyView::removeProperty(PropertyType type)
{
	if (_properties.contains(type)) {
		PropertyModel* pModel = _properties.value(type);
		_pBrowser->removeProperty(pModel->getGroupProperty());
		_properties.remove(type);
	}
}

QtAbstractPropertyBrowser* Largix::PropertyView::getBrowser() const
{
	return _pBrowser;
}

Largix::PropertyView::~PropertyView()
{
	if (!_properties.isEmpty()) {
		qDeleteAll(_properties.values());
	}
}
