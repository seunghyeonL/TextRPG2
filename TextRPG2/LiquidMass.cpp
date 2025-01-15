#include "LiquidMass.h"

LiquidMass::LiquidMass()
	: Name("LiquidMass") 
{
	Gold = 50;
}

string LiquidMass::GetName()
{
	return Name;
}
