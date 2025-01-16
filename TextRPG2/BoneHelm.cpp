#include "BoneHelm.h"

BoneHelm::BoneHelm()
	: IEquipmentItem(Helm, 0, 5), Name("BoneHelm")
{
}

string BoneHelm::GetName()
{
	return Name;
}
