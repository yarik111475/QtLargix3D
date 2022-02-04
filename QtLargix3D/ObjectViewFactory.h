#pragma once

namespace Largix
{
	class ObjectView;

	class ObjectViewFactory
	{
	public:
		virtual ObjectView* createObjectView() = 0;
	};
}

