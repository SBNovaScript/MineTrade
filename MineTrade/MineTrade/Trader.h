#pragma once
#include "Item.h"
#include <map>
#include <vector>
#include <memory>

class Trader
{
public:
	Trader();
	void populateInventoryWithDefaultItems();
	static int getItemPrice(Item item);
	static std::shared_ptr<Item> getItemPointerFromName(std::string itemName);
	static Item getItemFromName(std::string itemName);

private:

	// A map between an item and it's cost.
	static std::map<Item, int, ItemCompare> itemsForSale;

	// A vector of all available object pointers.
	static std::vector<std::shared_ptr<Item>> availableItems;
};