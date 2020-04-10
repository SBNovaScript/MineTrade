#include "Item.h"

Item::Item(std::string name) :
	name(name), basePrice(0)
{
}

Item::Item(std::string name, int basePrice) :
	name(name), basePrice(basePrice)
{
}

Item::Item()
{
	basePrice = -1;
}
