#include "Trader.h"
#include "Stick.h"
#include "Iron.h"
#include "Fish.h"
#include "Batter.h"
#include "Rock.h"
#include <memory>

std::map<Item, int, ItemCompare> Trader::itemsForSale = std::map<Item, int, ItemCompare>();
std::vector<std::shared_ptr<Item>> Trader::availableItems = std::vector<std::shared_ptr<Item>>();

Trader::Trader()
{
	populateInventoryWithDefaultItems();
}

void Trader::populateInventoryWithDefaultItems()
{
	std::shared_ptr<Item> stick(new Stick(1));
	std::shared_ptr<Item> iron(new Iron(5));
	std::shared_ptr<Item> fish(new Fish(10));
	std::shared_ptr<Item> batter(new Batter(20));
	std::shared_ptr<Item> rock(new Rock(1));

	itemsForSale[*stick] = stick->getBasePrice();
	itemsForSale[*iron] = iron->getBasePrice();
	itemsForSale[*fish] = fish->getBasePrice();
	itemsForSale[*batter] = batter->getBasePrice();
	itemsForSale[*rock] = rock->getBasePrice();

	availableItems.push_back(stick);
	availableItems.push_back(iron);
	availableItems.push_back(fish);
	availableItems.push_back(batter);
	availableItems.push_back(rock);
}

int Trader::getItemPrice(Item item)
{
	return itemsForSale[item];
}

std::shared_ptr<Item> Trader::getItemPointerFromName(std::string itemName)
{
	for(std::shared_ptr<Item> item : availableItems)
	{
		if (item->getName() == itemName)
		{
			return item;
		}
	}

	std::unique_ptr<Item> emptyItem(new Item());

	return emptyItem;
}

Item Trader::getItemFromName(std::string itemName)
{
	return *(getItemPointerFromName(itemName));
}
