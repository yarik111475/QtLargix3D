#pragma once
#include "ObjectView.h"


namespace Largix
{
	class PartView :public ObjectView
	{
	public:
		PartView(QObject* parent=nullptr);
		virtual vtkProp* getActor() override;
	};
}

