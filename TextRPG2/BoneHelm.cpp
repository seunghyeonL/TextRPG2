#include "BoneHelm.h"

BoneHelm::BoneHelm()
	: IEquipmentItem(Helm, 0, 30), Name("BoneHelm")
{
}

string BoneHelm::GetName()
{
	return Name;
}
