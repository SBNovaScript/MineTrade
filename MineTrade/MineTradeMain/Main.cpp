#include "../MineTrade/Trader.h"
#include "../MineTrade/Inventory.h"
#include <iostream>

int main()
{
	Trader trader = Trader();

	// Get an item name and price from the trader
	std::cout << Trader::getItemFromName("rock").getName() << std::endl;
	std::cout << Trader::getItemFromName("rock").getBasePrice() << std::endl;
}