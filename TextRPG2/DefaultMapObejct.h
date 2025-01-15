#pragma once
#include "IMapObject.h"

class DefaultMapObject: public IMapObject
{
protected:
	PosStruct Pos;

public:
	virtual ~DefaultMapObject() = default;
	
};

