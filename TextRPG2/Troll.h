#pragma once

#include "IMonster.h"

class Troll : public IMonster
{
private:
    Troll();
    virtual ~Troll() = default;

public:
    virtual void Initialize(string name, double health, double attack) override;
    virtual void Update() override;
    // virtual void Interact() override;

public:
    static Troll *Create(string name, double health, double attack);
    static Troll *CreateBoss(string name, double health, double attack);
    virtual void Free() override;
};
