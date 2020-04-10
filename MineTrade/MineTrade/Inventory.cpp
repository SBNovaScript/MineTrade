#include "Inventory.h"

Inventory::Inventory()
{
}

void Inventory::addItem(Item item)
{
	items[item.getName()]++;
}

std::unordered_map<std::string, int> Inventory::getAllItems()
{
	return items;
}

int Inventory::getItemAmount(std::string itemName)
{
	return items[itemName];
}
