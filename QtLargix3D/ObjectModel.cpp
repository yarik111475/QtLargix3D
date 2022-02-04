#include "ObjectModel.h"

using namespace Largix;

Largix::ObjectModel::ObjectModel(QObject *parent)
	: QObject(parent)
{
}

Largix::ObjectModel::~ObjectModel()
{
}

void Largix::ObjectModel::setSize(const QSize& size)
{
	_size = size;
	emit signalSizeChanged(_size);
}

QSize Largix::ObjectModel::getSize() const
{
	return _size;
}

void Largix::ObjectModel::setColor(const QColor& color)
{
	_color = color;
	emit signalColorChanged(_color);
}

QColor Largix::ObjectModel::getColor() const
{
	return _color;
}

void Largix::ObjectModel::setPoint(const QPoint3D& point)
{
	_point = point;
	emit signalPointChanged(_point);
}

QPoint3D Largix::ObjectModel::getPoint() const
{
	return _point;
}

void Largix::ObjectModel::setRotation(const QRotation3D& rotation)
{
	_rotation = rotation;
	emit signalRotationChanged(_rotation);
}

QRotation3D Largix::ObjectModel::getRotation() const
{
	return _rotation;
}

void Largix::ObjectModel::setTransparency(double transparency)
{
	_transparency = transparency;
	emit signalTransparencyChanged(_transparency);
}

double Largix::ObjectModel::getTransparency() const
{
	return _transparency;
}

void Largix::ObjectModel::setVisible(bool visible)
{
	_visible = visible;
	emit signalVisibleChanged(_visible);
}

bool Largix::ObjectModel::getVisible() const
{
	return _visible;
}
