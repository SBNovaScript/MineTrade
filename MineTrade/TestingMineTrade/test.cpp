#include "pch.h"
#include "../MineTrade/Inventory.h"
#include "../MineTrade/Trader.h"

TEST(StevenTestCases, TraderTest) {
    Trader trader = Trader();
    EXPECT_EQ(Trader::getItemPrice(Trader::getItemFromName("iron")), 5);
}

TEST(TestCases, BuyFromTrader) {
    Trader trader = Trader();
    Inventory inventory = Inventory();

    // Give the player 10 munny to test.
    inventory.addMunny(10);

    int updatedInventoryCount = inventory.getItemAmount(Trader::getItemFromName("stick")) + 1;
    int oldMunnyBalance = inventory.getAmountOfMoneyOwned();

    // Buy the stick from the trader.
    inventory.buyItem(Trader::getItemFromName("stick"));

    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("stick")), updatedInventoryCount);
    EXPECT_LT(inventory.getAmountOfMoneyOwned(), oldMunnyBalance);
}

TEST(DavidTestCases, SellToTrader) {
    Trader trader = Trader();
    Inventory inventory = Inventory();

    // Give the player 10 munny to test.
    inventory.addMunny(10);

    inventory.addItem(Trader::getItemFromName("iron"));

    int updatedInventoryCount = inventory.getItemAmount(Trader::getItemFromName("iron")) - 1;
    int oldMunnyBalance = inventory.getAmountOfMoneyOwned();

    // Buy the stick from the trader.
    inventory.sellItem(Trader::getItemFromName("iron"));

    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("iron")), updatedInventoryCount);
    EXPECT_GT(inventory.getAmountOfMoneyOwned(), oldMunnyBalance);
}

// Not implemented yet
TEST(DavidTestCases, SimpleCrafting) {
    Trader trader = Trader();
    Inventory inventory = Inventory();
    int updatedFishInventoryCount = inventory.getItemAmount(Trader::getItemFromName("fish")) - 1;
    int updatedBatterInventoryCount = inventory.getItemAmount(Trader::getItemFromName("batter")) - 1;;
    
    inventory.craft(Trader::getItemFromName("fishsticks"));

    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("fish")), updatedFishInventoryCount);
    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("batter")), updatedBatterInventoryCount);
    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("fishsticks")), 1);
}

TEST(StevenTestCases, Mining) {
    Trader trader = Trader();
    Inventory inventory = Inventory();
    int updatedInventoryCount = inventory.getItemAmount(Trader::getItemFromName("rock")) + 1;

    inventory.mineRocks();

    EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("rock")), updatedInventoryCount);
}

TEST(StevenTestCases, SellMinedRock) {
    Trader trader = Trader();
    Inventory inventory = Inventory();
    int updatedInventoryCount = inventory.getItemAmount(Trader::getItemFromName("rock")) - 1;

    int oldMunnyBalance = inventory.getAmountOfMoneyOwned();

    inventory.mineRocks();

    // Buy the stick from the trader.
    inventory.sellItem(Trader::getItemFromName("rock"));

    EXPECT_GT(inventory.getItemAmount(Trader::getItemFromName("rock")), updatedInventoryCount);
    EXPECT_GT(inventory.getAmountOfMoneyOwned(), oldMunnyBalance);
}

/*
The user can equip certain items either as armor pieces or a weapon/shield, 
which will alter prices in the store, and change the amount the user can mine. 
E.g. equipping a golden spoon will increase item sell value in the store, 
but reduce the amount you can mine to 10%.
*/

TEST(StevenTestCases, EquipEquipment) {
    Trader trader = Trader();
    Inventory inventory = Inventory();
    std::vector<Item> oldEquipment = inventory.getAllEquipment();

    inventory.mineRocks();

    inventory.equip(Trader::getItemFromName("rock"));

    std::vector<std::string> oldEquipmentToString;

    for (Item item : oldEquipment)
    {
        oldEquipmentToString.push_back(item.getName());
    }

    std::vector<std::string> newEquipmentToString;

    for (Item item : inventory.getAllEquipment())
    {
        newEquipmentToString.push_back(item.getName());
    }

    EXPECT_NE(newEquipmentToString, oldEquipmentToString);
}

TEST(StevenTestCases, UnequipEquipment) {
    Trader trader = Trader();
    Inventory inventory = Inventory();
    std::vector<Item> oldEquipment = inventory.getAllEquipment();

    inventory.mineRocks();

    inventory.equip(Trader::getItemFromName("rock"));
    inventory.unequip(Trader::getItemFromName("rock"));

    std::vector<std::string> oldEquipmentToString;

    for (Item item : oldEquipment)
    {
        oldEquipmentToString.push_back(item.getName());
    }

    std::vector<std::string> newEquipmentToString;

    for (Item item : inventory.getAllEquipment())
    {
        newEquipmentToString.push_back(item.getName());
    }

    EXPECT_EQ(newEquipmentToString, oldEquipmentToString);
}