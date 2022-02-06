#pragma once
#include "ObjectModel.h"
#include "Enumerations.h"


namespace Largix
{
	class PartModel : public ObjectModel
	{
	public:
		PartModel(QObject* parent=nullptr);

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
	protected slots:
		void slotRepresentationChanged(RepresentationMode representation) override;
	};
}

