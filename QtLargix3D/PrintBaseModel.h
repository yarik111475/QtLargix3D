#pragma once
#include "ObjectModel.h"


namespace Largix
{
	class PrintBaseModel : public ObjectModel
	{
	public:
		PrintBaseModel(QObject* parent = nullptr);

		virtual PropertyModel* getPropertyModel(PropertyView* pPropertyView) override;

	protected slots:
		void slotSizeChanged(const QSize& size) override;
	protected slots:
		void slotColorChanged(const QColor& color) override;
	protected slots:
		void slotPointChanged(const QPoint3D& point) override;
	protected slots:
		void slotRotationChanged(const QRotation3D& rotation) override;
	protected slots:
		void slotTransparencyChanged(double transparency) override;
	protected slots:
		void slotVisibleChanged(bool visible) override;
	};
}

