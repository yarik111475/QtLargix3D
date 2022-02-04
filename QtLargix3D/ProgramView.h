#pragma once
#include "ObjectView.h"


namespace Largix
{
	class ProgramView : public ObjectView
	{
	public:
		ProgramView(QObject* parent=nullptr);
		virtual vtkProp* getActor() override;
	};
}

