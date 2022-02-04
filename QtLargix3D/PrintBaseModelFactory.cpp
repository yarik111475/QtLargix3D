#include "PrintBaseModelFactory.h"
#include "PrintBaseModel.h"

Largix::ObjectModel* Largix::PrintBaseModelFactory::createModel()
{
	return new PrintBaseModel;
}
