#include "AttackBoost.h"
#include "Character.h"

AttackBoost::AttackBoost():Name("AttackBoostItem"), AttackIncrease(20)
{
}

string AttackBoost::GetName()
{
    return Name;
}

bool AttackBoost::Use(Character* character)
{
    if (IsAlreadyUseOne)
    {
        cout << "이미 한 번 먹었습니다. 더 이상 먹을 수 없습니다.\n";
        return false;
    }
    else
    {
        character->SetAttack(character->GetAttack() + AttackIncrease);
        cout << "공격력이 " << AttackIncrease << "만큼 증가했습니다." << endl;
        IsAlreadyUseOne = true;
        return true;
    }
}
