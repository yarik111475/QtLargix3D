#pragma once

#include "PropertyModel.h"

namespace Largix
{
	class PartPropertyModel : public PropertyModel
	{
		Q_OBJECT

	public:
		PartPropertyModel(const QString& title, QObject* parent=nullptr);
		~PartPropertyModel();
		virtual QtProperty* getGroupProperty() override;
	};
}
