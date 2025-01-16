#include "GreenLeatherHelm.h"

GreenLeatherHelm::GreenLeatherHelm()
	: IEquipmentItem(Helm, 0, 10), Name("GreenLeatherHelm")
{
}

string GreenLeatherHelm::GetName()
{
	return Name;
}
