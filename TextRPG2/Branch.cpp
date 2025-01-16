#include "Branch.h"

Branch::Branch()
	: IEquipmentItem(Weapon, 5, 0), Name("Branch")
{

}

string Branch::GetName()
{
	return Name;
}

