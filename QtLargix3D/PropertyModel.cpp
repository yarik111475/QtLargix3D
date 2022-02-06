#include "PropertyModel.h"
#include "qteditorfactory.h"
#include "qtpropertymanager.h"

Largix::PropertyModel::PropertyModel(const QString& title, QObject* parent) : QObject(parent), _title{ title }
{
}

Largix::PropertyModel::~PropertyModel()
{
}

void Largix::PropertyModel::setBrowser(QtAbstractPropertyBrowser* pBrowser)
{
	//Size property section
	_pSizeManager = new QtSizePropertyManager(pBrowser);
	_pSizeProperty = _pSizeManager->addProperty(QObject::tr("Size"));
	_pSizeManager->setValue(_pSizeProperty, QSize{});

	QtSpinBoxFactory* pSizeFactory = new QtSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pSizeManager->subIntPropertyManager(), pSizeFactory);

	QObject::connect(_pSizeManager, &QtSizePropertyManager::valueChanged,
		this, &PropertyModel::slotSizeChanged);

	//Color property section
	_pColorManager = new QtColorPropertyManager(pBrowser);
	_pColorProperty = _pColorManager->addProperty(QObject::tr("Color"));
	_pColorManager->setValue(_pColorProperty, QColor{});

	QtColorEditorFactory* pColorFactory = new QtColorEditorFactory(pBrowser);
	pBrowser->setFactoryForManager(_pColorManager, pColorFactory);

	QObject::connect(_pColorManager, &QtColorPropertyManager::valueChanged,
		this, &PropertyModel::slotColorChanged);

	//Point property section
	_pPointManager = new QtPoint3DPropertyManager(pBrowser);
	_pPointProperty = _pPointManager->addProperty(QObject::tr("Point"));
	_pPointManager->setValue(_pPointProperty, QPoint3D{});

	QtSpinBoxFactory* pPointFactory = new QtSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pPointManager->subIntPropertyManager(), pPointFactory);

	QObject::connect(_pPointManager, &QtPoint3DPropertyManager::valueChanged,
		this, &PropertyModel::slotPointChanged);

	//Rotation property section
	_pRotationManager = new QtRotation3DPropertyManager(pBrowser);
	_pRotationProperty = _pRotationManager->addProperty(QObject::tr("Rotation"));
	_pRotationManager->setValue(_pRotationProperty, QRotation3D{});

	QtSpinBoxFactory* pRotationFactory = new QtSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pRotationManager->subIntPropertyManager(), pRotationFactory);

	QObject::connect(_pRotationManager, &QtRotation3DPropertyManager::valueChanged,
		this, &PropertyModel::slotRotationChanged);

	//Transparency property section
	_pTransparencyManager = new QtDoublePropertyManager(pBrowser);
	_pTransparencyProperty = _pTransparencyManager->addProperty(QObject::tr("Transparency"));
	_pTransparencyManager->setValue(_pTransparencyProperty, double(0.0));

	QtDoubleSpinBoxFactory* pTransparencyFactory = new QtDoubleSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pTransparencyManager, pTransparencyFactory);

	QObject::connect(_pTransparencyManager, &QtDoublePropertyManager::valueChanged,
		this, &PropertyModel::slotTransparencyChanged);

	//Visible property section
	_pVisibleManager = new QtBoolPropertyManager(pBrowser);
	_pVisibleProperty = _pVisibleManager->addProperty(QObject::tr("Visible"));
	_pVisibleManager->setValue(_pVisibleProperty, false);

	QtCheckBoxFactory* pVisibleFactory = new QtCheckBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pVisibleManager, pVisibleFactory);

	QObject::connect(_pVisibleManager, &QtBoolPropertyManager::valueChanged,
		this, &PropertyModel::slotVisibleChanged);
}

void Largix::PropertyModel::setSize(const QSize& size)
{
	blockSignals(true);
	_pSizeManager->setValue(_pSizeProperty, size);
	blockSignals(false);
}

QSize Largix::PropertyModel::getSize() const
{
	return _pSizeManager->value(_pSizeProperty);
}

void Largix::PropertyModel::setColor(const QColor& color)
{
	blockSignals(true);
	_pColorManager->setValue(_pColorProperty, color);
	blockSignals(false);
}

QColor Largix::PropertyModel::getColor() const
{
	return _pColorManager->value(_pColorProperty);
}

void Largix::PropertyModel::setPoint(const QPoint3D& point)
{
	blockSignals(true);
	_pPointManager->setValue(_pPointProperty, point);
	blockSignals(false);
}

QPoint3D Largix::PropertyModel::getPoint() const
{
	return _pPointManager->value(_pPointProperty);
}

void Largix::PropertyModel::setRotation(const QRotation3D& rotation)
{
	blockSignals(true);
	_pRotationManager->setValue(_pRotationProperty, rotation);
	blockSignals(false);
}

QRotation3D Largix::PropertyModel::getRotation() const
{
	return _pRotationManager->value(_pRotationProperty);
}

void Largix::PropertyModel::setTransparency(double transparency)
{
	blockSignals(true);
	_pTransparencyManager->setValue(_pTransparencyProperty, transparency);
	blockSignals(false);
}

double Largix::PropertyModel::getTransparency() const
{
	return _pTransparencyManager->value(_pTransparencyProperty);
}

void Largix::PropertyModel::setVisible(bool visible)
{
	blockSignals(true);
	_pVisibleManager->setValue(_pVisibleProperty, visible);
	blockSignals(false);
}

bool Largix::PropertyModel::getVisible() const
{
	return _pVisibleManager->value(_pVisibleProperty);
}

void Largix::PropertyModel::slotSizeChanged(QtProperty* property, const QSize& val)
{
	//emit signalSizeChanged(val);
	emit signalPropertyChanged();
}

void Largix::PropertyModel::slotColorChanged(QtProperty* property, const QColor& val)
{
	//emit signalColorChanged(val);
	emit signalPropertyChanged();
}

void Largix::PropertyModel::slotPointChanged(QtProperty* property, const QPoint3D& val)
{
	//emit signalPointChanged(val);
	emit signalPropertyChanged();
}

void Largix::PropertyModel::slotRotationChanged(QtProperty* property, const QRotation3D& val)
{
	//emit signalRotationChanged(val);
	emit signalPropertyChanged();
}

void Largix::PropertyModel::slotTransparencyChanged(QtProperty* property, double val)
{
	//emit signalTransparencyChanged(val);
	emit signalPropertyChanged();
}

void Largix::PropertyModel::slotVisibleChanged(QtProperty* property, bool val)
{
	//emit signalVisibleChanged(val);
	emit signalPropertyChanged();
}