#include "BoneArmor.h"

BoneArmor::BoneArmor()
	: IEquipmentItem(Armor, 0, 30), Name("BoneArmor")
{

}

string BoneArmor::GetName()
{
	return Name;
}

