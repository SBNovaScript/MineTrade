#include "CraftingManager.h"
#include "Trader.h"

std::vector<Item> CraftingManager::getCraftingRequirements(Item item)
{
	if (item.getName() == "fishsticks")
	{
		std::vector<Item> requirementsList;
		requirementsList.push_back(Trader::getItemFromName("fish"));
		requirementsList.push_back(Trader::getItemFromName("batter"));
		return requirementsList;
	}

	return std::vector<Item>();
	
}
