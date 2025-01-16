#include "SFightable.h"
#include "DangerObserver.h"
#include "DeathObserver.h"
#include "FullObserver.h"

SFightable::SFightable()
{
	Observers.push_back(new DangerObserver());
	Observers.push_back(new DeathObserver());
	Observers.push_back(new FullObserver());
}

SFightable::SFightable(int health, int attack) 
	: mHealth{ health }, mAttack(attack)
{
	Observers.push_back(new DangerObserver());
	Observers.push_back(new DeathObserver());
	Observers.push_back(new FullObserver());
}

