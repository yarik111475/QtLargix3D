#pragma once

#include <QHash>
#include <QWidget>
#include "Enumerations.h"

#include "vtkSmartPointer.h"


class vtkRenderer;
class vtkOpenGLRenderWindow;
class QVTKOpenGLNativeWidget;

namespace Largix
{
	class ObjectView;

	class Widget3D : public QWidget
	{
		Q_OBJECT

	public:
		Widget3D(QWidget* parent=nullptr);
		~Widget3D();

		void addView(ObjectView* pView);
		void removeView(ViewType type);
		ObjectView* getViewByType(ViewType type);

	private:
		QHash<ViewType, ObjectView*> _viewHash;
		void addAxes();

		QVTKOpenGLNativeWidget* _widget;
		vtkSmartPointer<vtkRenderer> _renderer;
		vtkSmartPointer<vtkOpenGLRenderWindow> _renderWindow;

	private slots:
		void slotRender();
	};
}
