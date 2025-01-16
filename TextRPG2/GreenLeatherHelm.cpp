#include "GreenLeatherHelm.h"

GreenLeatherHelm::GreenLeatherHelm()
	: IEquipmentItem(Helm, 0, 5), Name("GreenLeatherHelm")
{
}

string GreenLeatherHelm::GetName()
{
	return Name;
}
