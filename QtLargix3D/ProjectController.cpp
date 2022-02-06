#include "ProjectController.h"
#include "ObjectModel.h"
#include "ObjectView.h"

#include "PartModel.h"
#include "ProgramModel.h"
#include "PrintBaseModel.h"

#include "PartView.h"
#include "ProgramView.h"
#include "PrintBaseView.h"

#include "PropertyModel.h"
#include "PartPropertyModel.h"
#include "ProgramPropertyModel.h"
#include "PrintBasePropertyModel.h"

#include "PropertyView.h"
#include "Widget3D.h"
#include "Enumerations.h"

#include <QObject>

Largix::ProjectController::ProjectController(QObject* parent) :QObject(parent), _pPropertyView{ nullptr }, _pWidget3D{ nullptr }
{
	_pPropertyView = new PropertyView;
	_pWidget3D = new Widget3D;

	ObjectModel* pPartModel = createObjectModel(ObjectType::PART);
	ObjectModel* pProgramModel = createObjectModel(ObjectType::PROGRAM);
	ObjectModel* pPrintBaseModel = createObjectModel(ObjectType::PRINTBASE);

	ObjectView* pPartView = new PartView;
	pPartView->setObjectModel(pPartModel);

	ObjectView* pProgramView = new ProgramView;
	pProgramView->setObjectModel(pProgramModel);

	ObjectView* pPrintBaseView = new PrintBaseView;
	pPrintBaseView->setObjectModel(pPrintBaseModel);


	PropertyModel* pPartProperty=pPartModel->getPropertyModel(_pPropertyView);
	PropertyModel* pProgramProperty = pProgramModel->getPropertyModel(_pPropertyView);
	PropertyModel* pPrintBaseProperty = pPrintBaseModel->getPropertyModel(_pPropertyView);

	_pPropertyView->addProperty(PropertyType::PART, pPartProperty);
	_pPropertyView->addProperty(PropertyType::PROGRAM, pProgramProperty);
	_pPropertyView->addProperty(PropertyType::PRINTBASE, pPrintBaseProperty);
}

Largix::Widget3D* Largix::ProjectController::getWidget3D() const
{
	return _pWidget3D;
}

Largix::PropertyView* Largix::ProjectController::getPropertyView() const
{
	return _pPropertyView;
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