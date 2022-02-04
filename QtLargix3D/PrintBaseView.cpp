#include "PrintBaseView.h"

#include "vtkNew.h"
#include "vtkActor.h"


Largix::PrintBaseView::PrintBaseView(QObject* parent):ObjectView(parent)
{
}

vtkProp* Largix::PrintBaseView::getActor()
{
	_pActor = vtkNew<vtkActor>();
	return _pActor;
}
