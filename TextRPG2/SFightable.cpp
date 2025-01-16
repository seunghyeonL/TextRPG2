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
