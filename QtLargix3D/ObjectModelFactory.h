#pragma once

namespace Largix
{
	class ObjectModel;

	class ObjectModelFactory
	{
	public:
		virtual ObjectModel* createModel() = 0;
	};
}

