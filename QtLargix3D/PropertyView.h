#pragma once

#include <QHash>
#include <QWidget>
#include "Enumerations.h"

class QtAbstractPropertyBrowser;

namespace Largix
{
	class PropertyModel;

	class PropertyView : public QWidget
	{
		Q_OBJECT

	public:
		PropertyView(QWidget* parent=nullptr);
		void addProperty(PropertyType type, PropertyModel* pPropertyModel);
		void removeProperty(PropertyType type);
		QtAbstractPropertyBrowser* getBrowser() const;
		~PropertyView();
	private:
		QtAbstractPropertyBrowser* _pBrowser;
		QHash<PropertyType, PropertyModel*> _properties;
	};
}
