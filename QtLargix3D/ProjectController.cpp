#include "ProjectController.h"
#include "ObjectModel.h"
#include "ObjectView.h"

#include "PartModel.h"
#include "ProgramModel.h"
#include "PrintBaseModel.h"

#include "PartView.h"
#include "ProgramView.h"
#include "PrintBaseView.h"

#include <QObject>

Largix::ProjectController::ProjectController()
{
}

Largix::ObjectModel* Largix::ProjectController::createObjectModel(ObjectType type, QObject* parent)
{
	ObjectModel* pModel{ nullptr };
	switch (type)
	{
	case ObjectType::PART:
		pModel = new PartModel(parent);
		break;
	case ObjectType::PROGRAM:
		pModel = new ProgramModel(parent);
		break;
	case ObjectType::PRINTBASE:
		pModel = new PrintBaseModel(parent);
		break;
	}
	return pModel;
}

Largix::ObjectView* Largix::ProjectController::createObjectView(ViewType type, QObject* parent)
{
	ObjectView* pView{ nullptr };
	switch (type)
	{
	case ViewType::PART:
		pView = new PartView(parent);
		break;
	case ViewType::PROGRAM:
		pView = new ProgramView(parent);
		break;
	case ViewType::PRINTBASE:
		pView = new PrintBaseView(parent);
		break;
	}
	return pView;
}