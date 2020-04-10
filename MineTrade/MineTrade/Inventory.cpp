#include "Inventory.h"
#include "Trader.h"

Inventory::Inventory()
{
	munnyItem = std::unique_ptr<Munny>(new Munny(1));
}

void Inventory::addItem(Item item)
{
	items[item]++;
}

void Inventory::removeItem(Item item)
{
	items[item]--;
}

std::map<Item, int, ItemCompare> Inventory::getAllItems()
{
	return items;
}

int Inventory::getItemAmount(Item item)
{
	return items[item];
}

int Inventory::getAmountOfMoneyOwned()
{
	return items[*munnyItem];
}

bool Inventory::buyItem(Item item)
{
	int traderPrice = Trader::getItemPrice(item);

	// If we have enough money to buy the item

	if (items[*munnyItem] >= traderPrice)
	{
		removeMunny(traderPrice);
		addItem(item);
		return true;
	}

	return false;
}

bool Inventory::sellItem(Item item)
{
	int traderPrice = Trader::getItemPrice(item);

	// If we have the item
	if (items[item] > 0)
	{
		removeItem(item.getName());
		addMunny(traderPrice);
		return true;
	}

	return false;
}

void Inventory::addMunny(int amount)
{

	items[*munnyItem] += amount;

}

void Inventory::removeMunny(int amount)
{

	items[*munnyItem] -= amount;

}
