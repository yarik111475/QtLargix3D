#pragma once
#include "qpoint3d.h"
#include "qrotation3D.h"
#include <QColor>
#include <QSize>
#include <QObject>
#include "Enumerations.h"
#include "vtkProp.h"
#include "vtkSmartPointer.h"

class vtkProp;

namespace Largix
{	
	class ObjectModel;

	class ObjectView : public QObject
	{
		Q_OBJECT
	public:
		ObjectView(QObject* parent=nullptr);
		virtual ~ObjectView();
		void setObjectModel(ObjectModel* pObjectModel);
		virtual vtkSmartPointer<vtkProp> getActor() = 0;
		virtual ViewType getType() const = 0;

	protected:
		ObjectModel* _pObjectModel;

	protected slots:
		virtual void slotSizeChanged(const QSize& size) = 0;
	protected slots:
		virtual void slotColorChanged(const QColor& color) = 0;
	protected slots:
		virtual void slotPointChanged(const QPoint3D& point) = 0;
	protected slots:
		virtual void slotRotationChanged(const QRotation3D& rotation) = 0;
	protected slots:
		virtual void slotTransparencyChanged(double transparency) = 0;;
	protected slots:
		virtual void slotVisibleChanged(double visible) = 0;

	signals:
		void signalRender();

	};
}