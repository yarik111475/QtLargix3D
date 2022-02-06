#pragma once

#include <QWidget>

namespace Largix
{
	class ObjectView;

	class Widget3D : public QWidget
	{
		Q_OBJECT

	public:
		Widget3D(QWidget* parent=nullptr);
		~Widget3D();
	};
}
