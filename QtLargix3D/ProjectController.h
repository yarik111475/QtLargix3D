#pragma once
#include "Enumerations.h"

class QObject;

namespace Largix
{
	class ObjectModel;
	class ObjectView;

	class ProjectController
	{
	public:
		ProjectController();
	private:
		ObjectModel* createObjectModel(ObjectType type, QObject* parent=nullptr);
		ObjectView* createObjectView(ViewType type, QObject* parent=nullptr);
	};
}


