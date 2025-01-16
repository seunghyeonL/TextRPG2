#include "LeatherShoes.h"

LeatherShoes::LeatherShoes()
    : Name("Leather Shoes") // 아이템 이름 초기화
{
}

string LeatherShoes::GetName()
{
    return Name;
}

void LeatherShoes::Equip(Character* character)
{
    cout << "Equipping " << Name << " to " << character->GetName() << endl;
    // 캐릭터의 능력치를 추가하거나 수정하는 로직 추가 가능
}
