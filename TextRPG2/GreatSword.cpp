#include "GreatSword.h"

GreatSword::GreatSword()
	: IEquipmentItem(Weapon, 30, 0), Name("GreatSword")
{

}

string GreatSword::GetName()
{
	return Name;
}

