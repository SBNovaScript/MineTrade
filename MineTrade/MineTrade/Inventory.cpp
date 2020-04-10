#include "Inventory.h"
#include "Trader.h"
#include "CraftingManager.h"

Inventory::Inventory()
{
	munnyItem = std::unique_ptr<Munny>(new Munny(1));
}

void Inventory::addItem(Item item)
{
	items[item.getName()]++;
}

void Inventory::removeItem(Item item)
{
	items[item.getName()]--;
}

std::map<std::string, int> Inventory::getAllItems()
{
	return items;
}

int Inventory::getItemAmount(Item item)
{
	return items[item.getName()];
}

int Inventory::getAmountOfMoneyOwned()
{
	return items[munnyItem->getName()];
}

bool Inventory::buyItem(Item item)
{
	int traderPrice = Trader::getItemPrice(item);

	// If we have enough money to buy the item

	if (items[munnyItem->getName()] >= traderPrice)
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
	if (items[item.getName()] > 0)
	{
		removeItem(item);
		addMunny(traderPrice);
		return true;
	}

	return false;
}

void Inventory::addMunny(int amount)
{

	items[munnyItem->getName()] += amount;

}

void Inventory::removeMunny(int amount)
{

	items[munnyItem->getName()] -= amount;

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

