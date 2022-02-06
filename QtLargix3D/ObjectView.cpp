#include "ObjectView.h"
#include "ObjectModel.h"
#include "vtkActor.h"

Largix::ObjectView::ObjectView(QObject* parent) 
	: QObject(parent), _pObjectModel{ nullptr }, _pActor{ nullptr }
{
}

Largix::ObjectView::~ObjectView()
{
	if (_pObjectModel) {
		delete _pObjectModel;
	}
	if (_pActor) {
		_pActor->Delete();
	}
}

void Largix::ObjectView::setObjectModel(ObjectModel* pObjectModel)
{
	_pObjectModel = pObjectModel;
	
	QObject::connect(_pObjectModel, &ObjectModel::signalSizeChanged,
		this, &ObjectView::slotSizeChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalColorChanged,
		this, &ObjectView::slotColorChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalSizeChanged,
		this, &ObjectView::slotSizeChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalRotationChanged,
		this, &ObjectView::slotRotationChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalTransparencyChanged,
		this, &ObjectView::slotTransparencyChanged);
	QObject::connect(_pObjectModel, &ObjectModel::signalVisibleChanged,
		this, &ObjectView::slotVisibleChanged);
}

void Largix::ObjectView::slotSizeChanged(const QSize& size)
{
}

void Largix::ObjectView::slotColorChanged(const QColor& color)
{
}

void Largix::ObjectView::slotPointChanged(const QPoint3D& point)
{
}

void Largix::ObjectView::slotRotationChanged(const QRotation3D& rotation)
{
}

void Largix::ObjectView::slotTransparencyChanged(double transparency)
{
}

void Largix::ObjectView::slotVisibleChanged(double visible)
{
}