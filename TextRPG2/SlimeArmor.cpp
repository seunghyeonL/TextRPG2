#include "SlimeArmor.h"

SlimeArmor::SlimeArmor()
	: IEquipmentItem(Armor, 0, 10), Name("SlimeArmor")
{

}

string SlimeArmor::GetName()
{
	return Name;
}

