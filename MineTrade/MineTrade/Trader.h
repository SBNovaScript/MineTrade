#pragma once
#include "Item.h"
#include <unordered_map>
#include <vector>

class Trader
{
public:
	Trader();
	void populateInventoryWithDefaultItems();
	static int getItemPrice(Item item);
	Item getItemFromName(std::string itemName);

private:

	// A map between an item and it's cost.
	std::unordered_map<Item, int> itemsForSale;
	std::vector<Item> availableItems;
};