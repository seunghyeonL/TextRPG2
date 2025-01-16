#include <string>

using namespace std;

class Observer
{
public:
	virtual ~Observer() = default;

	virtual void OnInvetoryChanged(const string& action, const string itemName) = 0;
};