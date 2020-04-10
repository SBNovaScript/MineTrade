#pragma once
#include "Item.h"
#include <unordered_map>

class Inventory
{
public:
	Inventory();
	void addItem(Item item);
	void removeItem(Item item);
	std::unordered_map<Item, int> getAllItems();
	int getItemAmount(Item item);
	void addMunny(int amount);
	void removeMunny(int amount);
	bool buyItem(Item item);
	bool sellItem(Item item);

private:

	// A dictionary between the item name and the amount the user has.
	std::unordered_map<Item, int> items;

	// The item that represents Munny.
	Item munnyItem;
};