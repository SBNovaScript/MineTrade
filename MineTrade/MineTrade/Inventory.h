#pragma once
#include "Item.h"
#include <unordered_map>

class Inventory
{
public:
	Inventory();
	void addItem(Item item);
	std::unordered_map<std::string, int> getAllItems();
	int getItemAmount(std::string itemName);

private:

	// A dictionary between the item name and the amount the user has.
	std::unordered_map<std::string, int> items;
};