#include "Subject.h"

void Subject::AddObserver(Observer* observer)
{
	observers.push_back(observer);
}

void Subject::RemoveObserver(Observer* observer)
{
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::NotifyInventoryObservers(const string& action, const string& itemName)
{
	for (Observer* observer : observers)
		observer->OnInvetoryChanged(action, itemName);
}
