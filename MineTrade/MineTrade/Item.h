#pragma once
#include <string>

class Item
{
public:
	Item(std::string name);
	std::string getName() { return name;  }

private:
	std::string name;
};