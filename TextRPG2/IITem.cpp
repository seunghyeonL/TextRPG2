#include "Character.h"
#include "IItem.h"

IItem::IItem()
	:IsAlreadyUseOne(false)
{
}

void IItem::SetIsAlreadyUseOne()
{
	IsAlreadyUseOne = false;
}
