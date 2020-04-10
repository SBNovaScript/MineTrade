#include "Inventory.h"
#include "Trader.h"
#include "Munny.h"

Inventory::Inventory()
{
	Munny munny(1);
	munnyItem = munny;
}

void Inventory::addItem(Item item)
{
	items[item.getName()]++;
}

void Inventory::removeItem(Item item)
{
	items[item.getName()]--;
}

std::unordered_map<Item, int> Inventory::getAllItems()
{
	return items;
}

int Inventory::getItemAmount(Item item)
{
	return items[item];
}

bool Inventory::buyItem(Item item)
{
	int traderPrice = Trader::getItemPrice(item.getName());

	// If we have enough money to buy the item

	if (items[munnyItem] >= traderPrice)
	{
		removeMunny(traderPrice);
		addItem(item);
		return true;
	}

	return false;
}

bool Inventory::sellItem(Item item)
{
	int traderPrice = Trader::getItemPrice(item.getName());

	// If we have the item
	if (items[item.getName()] > 0)
	{
		removeItem(item.getName());
		addMunny(traderPrice);
		return true;
	}

	return false;
}

void Inventory::addMunny(int amount)
{

	items[munnyItem] += amount;

}

void Inventory::removeMunny(int amount)
{

	items[munnyItem] -= amount;

}
