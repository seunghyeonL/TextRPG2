#include "ClothArmor.h"

ClothArmor::ClothArmor()
	: IEquipmentItem(Armor, 0, 5), Name("ClothArmor")
{

}

string ClothArmor::GetName()
{
	return Name;
}

