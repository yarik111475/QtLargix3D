#include "ObjectView.h"
#include "ObjectModel.h"
#include "vtkActor.h"

Largix::ObjectView::ObjectView(QObject* parent) : QObject(parent), _pObjectModel{ nullptr }
{
}

Largix::ObjectView::~ObjectView()
{
	if (_pObjectModel) {
		delete _pObjectModel;
	}
}

void Largix::ObjectView::setObjectModel(ObjectModel* pObjectModel)
{
	_pObjectModel = pObjectModel;
	
	QObject::connect(_pObjectModel, &ObjectModel::signalSizeChanged,
		this, &ObjectView::slotSizeChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalColorChanged,
		this, &ObjectView::slotColorChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalPointChanged,
		this, &ObjectView::slotPointChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalRotationChanged,
		this, &ObjectView::slotRotationChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalTransparencyChanged,
		this, &ObjectView::slotTransparencyChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalVisibleChanged,
		this, &ObjectView::slotVisibleChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalRepresentationChanged,
		this, &ObjectView::slotRepresentationChanged);
}