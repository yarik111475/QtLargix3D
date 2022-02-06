#pragma once
#include "ObjectModel.h"


namespace Largix
{
	class PrintBaseModel : public ObjectModel
	{
	public:
		PrintBaseModel(QObject* parent = nullptr);

		virtual PropertyModel* getPropertyModel(PropertyView* pPropertyView) override;

	protected slots:
		virtual void slotPropertyChanged()override;
	};
}

