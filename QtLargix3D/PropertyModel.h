#pragma once
#include <QObject>

namespace Largix
{
	class PropertyModel : public QObject
	{
		Q_OBJECT

	public:
		PropertyModel(QObject* parent = nullptr);
		~PropertyModel();
	};
}

