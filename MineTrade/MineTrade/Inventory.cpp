#include "Inventory.h"
#include "Trader.h"
#include "CraftingManager.h"

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

void Inventory::mineRocks()
{
	addItem(Trader::getItemFromName("rock"));
}

void Inventory::equip(Item item)
{
	removeItem(item);
	equipment.push_back(item);
}

void Inventory::unequip(Item item)
{
	addItem(item);
	equipment.clear();
}

std::vector<Item> Inventory::getAllEquipment()
{
	return equipment;
}

void Inventory::craft(Item item)
{
	std::vector<Item> recipe = CraftingManager::getCraftingRequirements(item);
	for (Item recipeItem : recipe)
	{
		removeItem(recipeItem);
	}

	addItem(item);
}

