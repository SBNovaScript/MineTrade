#include "Trader.h"
#include "Stick.h"
#include "Iron.h"
#include "Fish.h"
#include "Batter.h"

Trader::Trader()
{
	populateInventoryWithDefaultItems();
}

void Trader::populateInventoryWithDefaultItems()
{
	Stick stick(1);
	Iron iron(5);
	Fish fish(10);
	Batter batter(20);

	itemsForSale[stick] = stick.getBasePrice();
	itemsForSale[iron] = iron.getBasePrice();
	itemsForSale[fish] = fish.getBasePrice();
	itemsForSale[batter] = batter.getBasePrice();
}

int Trader::getItemPrice(Item item)
{
	return itemsForSale[item];
}

Item Trader::getItemFromName(std::string itemName)
{
	for(Item item : availableItems)
	{
		if (item.getName() == itemName)
		{
			return item;
		}
	}

	Item emptyItem;

	return emptyItem;
}
