#include "ObjectView.h"
#include "ObjectModel.h"

Largix::ObjectView::ObjectView(QObject* parent) : QObject(parent), _pObjectModel{ nullptr }, _pActor{ nullptr }
{
}

Largix::ObjectView::~ObjectView()
{
	if (_pObjectModel) {
		delete _pObjectModel;
	}
	if (_pActor) {
		delete _pActor;
	}
}

void Largix::ObjectView::setObjectModel(ObjectModel* pObjectModel)
{
	_pObjectModel = pObjectModel;
	//connect here to all model signals
	//to update view properties
}