#pragma once
#include "ObjectView.h"
#include "vtkSmartPointer.h"

class vtkActor;


namespace Largix
{
	class PrintBaseView : public ObjectView
	{
	public:
		PrintBaseView(QObject* parent=nullptr);
		virtual vtkSmartPointer<vtkProp> getActor() override;
		virtual ViewType getType() const override;

	protected slots:
		virtual void slotSizeChanged(const QSize& size) override;
	protected slots:
		virtual void slotColorChanged(const QColor& color) override;
	protected slots:
		virtual void slotPointChanged(const QPoint3D& point) override;
	protected slots:
		virtual void slotRotationChanged(const QRotation3D& rotation) override;
	protected slots:
		virtual void slotTransparencyChanged(double transparency) override;
	protected slots:
		virtual void slotVisibleChanged(double visible) override;

	private:
		vtkSmartPointer<vtkActor> _pActor;
	};
}

