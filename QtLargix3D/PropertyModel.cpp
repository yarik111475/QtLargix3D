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
	//set rotation angles from -360 to 360
	_pRotationManager->subIntPropertyManager()->setRange(_pRotationProperty->subProperties().at(0), -360, 360);
	_pRotationManager->subIntPropertyManager()->setRange(_pRotationProperty->subProperties().at(1), -360, 360);
	_pRotationManager->subIntPropertyManager()->setRange(_pRotationProperty->subProperties().at(2), -360, 360);

	QtSpinBoxFactory* pRotationFactory = new QtSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pRotationManager->subIntPropertyManager(), pRotationFactory);

	QObject::connect(_pRotationManager, &QtRotation3DPropertyManager::valueChanged,
		this, &PropertyModel::slotRotationChanged);

	//Transparency property section
	_pTransparencyManager = new QtDoublePropertyManager(pBrowser);
	_pTransparencyProperty = _pTransparencyManager->addProperty(QObject::tr("Transparency"));
	_pTransparencyManager->setValue(_pTransparencyProperty, 1.0);
	_pTransparencyManager->setRange(_pTransparencyProperty, 0, 1);
	_pTransparencyManager->setSingleStep(_pTransparencyProperty, 0.1);

	QtDoubleSpinBoxFactory* pTransparencyFactory = new QtDoubleSpinBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pTransparencyManager, pTransparencyFactory);

	QObject::connect(_pTransparencyManager, &QtDoublePropertyManager::valueChanged,
		this, &PropertyModel::slotTransparencyChanged);

	//Representation property section
	_pVisibleManager = new QtBoolPropertyManager(pBrowser);
	_pVisibleProperty = _pVisibleManager->addProperty(QObject::tr("Visible"));
	_pVisibleManager->setValue(_pVisibleProperty, true);

	QtCheckBoxFactory* pVisibleFactory = new QtCheckBoxFactory(pBrowser);
	pBrowser->setFactoryForManager(_pVisibleManager, pVisibleFactory);

	QObject::connect(_pVisibleManager, &QtBoolPropertyManager::valueChanged,
		this, &PropertyModel::slotVisibleChanged);

	//Representation property section	
	_pRepresentationManager = new QtEnumPropertyManager(pBrowser);
	_pRepresentationProperty = _pRepresentationManager->addProperty("Representation");

	_representationModes.insert(0, RepresentationMode::SURFACE);
	_representationModes.insert(1, RepresentationMode::WIREFRAME);
	_representationModes.insert(2, RepresentationMode::COMPLEX);

	QStringList modes;
	modes << "Surface" << "Wireframe" << "Complex";
	_pRepresentationManager->setEnumNames(_pRepresentationProperty, modes);
	_pRepresentationManager->setValue(_pRepresentationProperty, 0);

	QObject::connect(_pRepresentationManager, &QtEnumPropertyManager::valueChanged,
		this, &PropertyModel::slotRepresentationChanged);
	QtEnumEditorFactory* pVisualModeFactory = new QtEnumEditorFactory(pBrowser);
	pBrowser->setFactoryForManager(_pRepresentationManager, pVisualModeFactory);
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
	emit signalSizeChanged(val);
}

void Largix::PropertyModel::slotColorChanged(QtProperty* property, const QColor& val)
{
	emit signalColorChanged(val);
}

void Largix::PropertyModel::slotPointChanged(QtProperty* property, const QPoint3D& val)
{
	emit signalPointChanged(val);
}

void Largix::PropertyModel::slotRotationChanged(QtProperty* property, const QRotation3D& val)
{
	emit signalRotationChanged(val);
}

void Largix::PropertyModel::slotTransparencyChanged(QtProperty* property, double val)
{
	emit signalTransparencyChanged(val);
}

void Largix::PropertyModel::slotVisibleChanged(QtProperty* property, bool val)
{
	emit signalVisibleChanged(val);
}

void Largix::PropertyModel::slotRepresentationChanged(QtProperty* property, int val)
{
	emit signalRepresentationChanged(_representationModes.value(val));
}