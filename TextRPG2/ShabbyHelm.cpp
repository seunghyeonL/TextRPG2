#include "ShabbyHelm.h"

ShabbyHelm::ShabbyHelm()
	: IEquipmentItem(Helm, 0, 5),Name("ShabbyHelm") 
{
}

string ShabbyHelm::GetName()
{
	return Name;
}

