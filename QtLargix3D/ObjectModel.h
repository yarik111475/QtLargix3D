#pragma once
#include "qpoint3d.h"
#include "qrotation3D.h"
#include <QColor>
#include <QSize>
#include <QObject>
#include <QObject>


namespace Largix
{
	class PropertyModel;
	class PropertyView;

	class ObjectModel : public QObject
	{
		Q_OBJECT

	public:
		ObjectModel(QObject* parent = nullptr);
		~ObjectModel();

		void setSize(const QSize& size);
		QSize getSize()const;

		void setColor(const QColor& color);
		QColor getColor()const;

		void setPoint(const QPoint3D& point);
		QPoint3D getPoint() const;

		void setRotation(const QRotation3D& rotation);
		QRotation3D getRotation()const;

		void setTransparency(double transparency);
		double getTransparency()const;

		void setVisible(bool visible);
		bool getVisible()const;

		virtual PropertyModel* getPropertyModel(PropertyView* pPropertyView) = 0;

	private:
		QSize          _size;
		QColor         _color;
		QPoint3D       _point;
		QRotation3D    _rotation;
		double         _transparency;
		bool           _visible;

	protected slots:
		virtual void slotPropertyChanged()=0;

	signals:
		void signalSizeChanged(const QSize& size);
	signals:
		void signalColorChanged(const QColor& color);
	signals:
		void signalPointChanged(const QPoint3D& point);
	signals:
		void signalRotationChanged(const QRotation3D& rotation);
	signals:
		void signalTransparencyChanged(double transparency);
	signals:
		void signalVisibleChanged(bool visible);
	};
}

