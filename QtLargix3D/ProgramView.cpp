#include "ProgramView.h"

#include "vtkNew.h"
#include "vtkActor.h"

Largix::ProgramView::ProgramView(QObject* parent):ObjectView(parent)
{
}

vtkProp* Largix::ProgramView::getActor()
{
	_pActor = vtkNew<vtkActor>();
	return _pActor;
}
