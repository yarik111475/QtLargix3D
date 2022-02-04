#pragma once
#include "ObjectView.h"


namespace Largix
{
	class PrintBaseView : public ObjectView
	{
	public:
		PrintBaseView(QObject* parent=nullptr);
		virtual vtkProp* getActor() override;
	};
}

