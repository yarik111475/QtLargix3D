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
		virtual void setObjectModel(ObjectModel* pObjectModel);
		virtual vtkProp* getActor() = 0;
	protected:
		ObjectModel* _pObjectModel;
		vtkProp* _pActor;
	private:

	};
}