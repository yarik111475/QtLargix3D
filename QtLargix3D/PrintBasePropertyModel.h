#pragma once

#include "PropertyModel.h"

namespace Largix
{
	class PrintBasePropertyModel : public PropertyModel
	{
		Q_OBJECT

	public:
		PrintBasePropertyModel(const QString& title, QObject* parent = nullptr);
		~PrintBasePropertyModel();
		virtual QtProperty* getGroupProperty() override;
		virtual PropertyType getType() const override;
	};
}
