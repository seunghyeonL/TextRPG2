#include "HeavySword.h"

HeavySword::HeavySword()
	: IEquipmentItem(Weapon, 15, 0), Name("HeavySword")
{

}

string HeavySword::GetName()
{
	return Name;
}

