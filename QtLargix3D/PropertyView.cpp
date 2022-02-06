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

void Largix::PropertyView::addProperty(PropertyModel* pPropertyModel)
{
	PropertyType type = pPropertyModel->getType();
	if (_propertyHash.contains(type)) {
		return;
	}
	_propertyHash.insert(type, pPropertyModel);
	_pBrowser->addProperty(pPropertyModel->getGroupProperty());
}

void Largix::PropertyView::removeProperty(PropertyType type)
{
	if (_propertyHash.contains(type)) {
		_propertyHash.remove(type);

		_pBrowser->clear();	
		for (const auto& item : _propertyHash.values()) {
			_pBrowser->addProperty(item->getGroupProperty());
		}
	}
}

QtAbstractPropertyBrowser* Largix::PropertyView::getBrowser() const
{
	return _pBrowser;
}

Largix::PropertyView::~PropertyView()
{
	if (!_propertyHash.isEmpty()) {
		qDeleteAll(_propertyHash.values());
	}
}
