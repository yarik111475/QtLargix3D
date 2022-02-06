#pragma once
#include "ObjectModel.h"


namespace Largix
{
	class PartModel : public ObjectModel
	{
	public:
		PartModel(QObject* parent=nullptr);

		virtual PropertyModel* getPropertyModel(PropertyView* pPropertyView) override;

	protected slots:
		virtual void slotPropertyChanged() override;
	};
}

