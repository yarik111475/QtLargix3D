#pragma once

#include "PropertyModel.h"

namespace Largix
{
	class ProgramPropertyModel : public PropertyModel
	{
		Q_OBJECT

	public:
		ProgramPropertyModel(const QString& title, QObject* parent=nullptr);
		~ProgramPropertyModel();
		virtual QtProperty* getGroupProperty() override;
		virtual PropertyType getType() const override;
	};
}
