#pragma once

#include <iostream>
#include <string>

using namespace std;

class Character;

class IItem
{
protected:
	bool IsAlreadyUseOne;
public:
	IItem();
	~IItem() = default;
	virtual string GetName() = 0;
	virtual bool Use(class Character *character) = 0;
	void SetIsAlreadyUseOne();
};

