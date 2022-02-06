#pragma once
#include <QHash>
#include <QSize>
#include <QColor>
#include <QObject>
#include "qpoint3d.h"
#include "qrotation3D.h"
#include "Enumerations.h"

class QtProperty;
class QtSizePropertyManager;
class QtColorPropertyManager;
class QtPoint3DPropertyManager;
class QtRotation3DPropertyManager;
class QtDoublePropertyManager;
class QtBoolPropertyManager;
class QtEnumPropertyManager;
class QtAbstractPropertyBrowser;

namespace Largix
{
	class ObjectModel;

	class PropertyModel : public QObject
	{
		Q_OBJECT

	public:
		PropertyModel(const QString& title, QObject* parent = nullptr);
		~PropertyModel();
		void setBrowser(QtAbstractPropertyBrowser* pBrowser);
		virtual QtProperty* getGroupProperty() = 0;
		virtual PropertyType getType() const = 0;

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

	protected:
		QString     _title;

		QtProperty* _pSizeProperty;
		QtProperty* _pColorProperty;
		QtProperty* _pPointProperty;
		QtProperty* _pRotationProperty;
		QtProperty* _pTransparencyProperty;
		QtProperty* _pVisibleProperty;
		QtProperty* _pRepresentationProperty;

	private:
		QtSizePropertyManager*       _pSizeManager;
		QtColorPropertyManager*      _pColorManager;
		QtPoint3DPropertyManager*    _pPointManager;
		QtRotation3DPropertyManager* _pRotationManager;
		QtDoublePropertyManager*     _pTransparencyManager;
		QtBoolPropertyManager*       _pVisibleManager;
		QtEnumPropertyManager*       _pRepresentationManager;

		QHash<int, RepresentationMode> _representationModes;

	private slots:
		void slotSizeChanged(QtProperty* property, const QSize& val);
	private slots:
		void slotColorChanged(QtProperty* property, const QColor& val);
	private slots:
		void slotPointChanged(QtProperty* property, const QPoint3D& val);
	private slots:
		void slotRotationChanged(QtProperty* property, const QRotation3D& val);
	private slots:
		void slotTransparencyChanged(QtProperty* property, double val);
	private slots:
		void slotVisibleChanged(QtProperty* property, bool val);
	private slots:
		void slotRepresentationChanged(QtProperty* property, int val);

	signals:
		void signalPropertyChanged();
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
	signals:
		void signalRepresentationChanged(RepresentationMode representation);
	};
}

