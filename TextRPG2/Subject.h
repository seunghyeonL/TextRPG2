#pragma once
#include <vector>
#include "Observer.h"

using namespace std;

class Subject
{
private:
	vector<Observer*> observers;

public:
	void AddObserver(Observer* observer);
	void RemoveObserver(Observer* observer);
	void NotifyInventoryObservers(const string& action, const string& itemName);
};
