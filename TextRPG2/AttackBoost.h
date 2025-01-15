#pragma once
#include <iostream>
#include <string>
#include "IItem.h"

using namespace std;

class Character;

class AttackBoost : public IItem
{
private:
    string Name;
    int AttackIncrease;

public:
    AttackBoost();
    string GetName() override;
    bool Use(Character *character) override;
    //bool IsAlredyUseOne; // 공격력 증가 물약을 두번 연속 먹어도 효과가 증가하지 않는걸 체크하는 변수
};