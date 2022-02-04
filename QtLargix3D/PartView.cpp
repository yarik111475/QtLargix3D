#include "PartView.h"

#include "vtkNew.h"
#include "vtkActor.h"

Largix::PartView::PartView(QObject* parent):ObjectView(parent)
{
}

vtkProp* Largix::PartView::getActor()
{
	_pActor = vtkNew<vtkActor>();
	return _pActor;
}
