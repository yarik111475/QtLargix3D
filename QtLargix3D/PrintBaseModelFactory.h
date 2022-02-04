#pragma once
#include "ObjectModelFactory.h"


namespace Largix
{
	class PrintBaseModelFactory :public ObjectModelFactory
	{
	public:
		virtual ObjectModel* createModel() override;
	};
}

