#include "LeatherShoes.h"

LeatherShoes::LeatherShoes()
    : IEquipmentItem(Helm, 0, 5), Name("LeatherShoes")
{
}

string LeatherShoes::GetName()
{
    return Name;
}

