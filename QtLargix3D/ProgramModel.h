#pragma once
#include "ObjectModel.h"


namespace Largix
{
	class ProgramModel :public ObjectModel
	{
	public:
		ProgramModel(QObject* parent = nullptr);

		virtual PropertyModel* getPropertyModel(PropertyView* pPropertyView) override;

	protected slots:
		virtual void slotPropertyChanged() override;
	};
}

