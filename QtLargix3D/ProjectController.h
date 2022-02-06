#pragma once
#include <QObject>
#include "Enumerations.h"


namespace Largix
{
	class ObjectModel;
	class ObjectView;
	class PropertyView;
	class Widget3D;

	class ProjectController:public QObject
	{
		Q_OBJECT
	public:
		ProjectController(QObject* parent=nullptr);

		Widget3D* getWidget3D() const;
		PropertyView* getPropertyView() const;
	private:
		ObjectModel* createObjectModel(ObjectType type, QObject* parent=nullptr);
		ObjectView* createObjectView(ViewType type, QObject* parent=nullptr);

		PropertyView* _pPropertyView;
		Widget3D* _pWidget3D;
	};
}