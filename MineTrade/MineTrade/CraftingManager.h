#pragma once
#include "Item.h"
#include <vector>

class CraftingManager
{
public:
	static std::vector<Item> getCraftingRequirements(Item item);
};