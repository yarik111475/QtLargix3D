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
		virtual void slotSizeChanged(const QSize& size) {}
	protected slots:
		virtual void slotColorChanged(const QColor& color) {}
	protected slots:
		virtual void slotPointChanged(const QPoint3D& point) {}
	protected slots:
		virtual void slotRotationChanged(const QRotation3D& rotation) {}
	protected slots:
		virtual void slotTransparencyChanged(double transparency) {}
	protected slots:
		virtual void slotVisibleChanged(double visible) {}
	protected slots:
		virtual void slotRepresentationChanged(RepresentationMode representation) {}

	signals:
		void signalRender();

	};
}