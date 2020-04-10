#pragma once
#include "Munny.h"
#include <map>
#include <memory>

class Inventory
{
public:
	Inventory();
	void addItem(Item item);
	void removeItem(Item item);
	std::map<Item, int, ItemCompare> getAllItems();
	int getItemAmount(Item item);
	int getAmountOfMoneyOwned();
	void addMunny(int amount);
	void removeMunny(int amount);
	bool buyItem(Item item);
	bool sellItem(Item item);
	void mineRocks();
	void equip(Item item);
	void unequip(Item item);
	std::vector<Item> getAllEquipment();

private:

	// A dictionary between the item name and the amount the user has.
	std::map<Item, int, ItemCompare> items;

	// The item that represents Munny.
	std::unique_ptr<Munny> munnyItem;

	//std::vector<Item> equipment;
	std::vector<Item> equipment;
};