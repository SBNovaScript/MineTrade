#pragma once
#include <string>

class Item
{
public:
	Item();
	Item(std::string name);
	Item(std::string name, int basePrice);

	std::string getName() { return name; }
	int getBasePrice() { return basePrice; }

	// Overloads
	bool operator < (const Item& obj)
	{
		return this->basePrice < obj.basePrice;
	}

	int basePrice;

protected:
	std::string name;
	
};