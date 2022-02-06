#pragma once
#include "qpoint3d.h"
#include "qrotation3D.h"
#include <QColor>
#include <QSize>
#include <QObject>

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
		virtual vtkProp* getActor() = 0;
	protected:
		ObjectModel* _pObjectModel;
		vtkProp* _pActor;
	private:

	private slots:
		void slotSizeChanged(const QSize& size);
	private slots:
		void slotColorChanged(const QColor& color);
	private slots:
		void slotPointChanged(const QPoint3D& point);
	private slots:
		void slotRotationChanged(const QRotation3D& rotation);
	private slots:
		void slotTransparencyChanged(double transparency);
	private slots:
		void slotVisibleChanged(double visible);

	};
}