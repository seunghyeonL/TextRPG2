#pragma once
#include "Observer.h"

class UIObserver : public Observer
{
public:
	virtual void OnInvetoryChanged(const string& action, const string itemName) override;
};
