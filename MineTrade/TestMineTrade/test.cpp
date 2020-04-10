//#include "../MineText/Header.h"
#include "../MineTrade/Inventory.h"
#include "pch.h"
#include <unordered_map>
#include <string>

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(DavidTestCases, BuyFromTrader) {
    Inventory inventory;
    std::unordered_map<std::string, int> items = inventory.getAllItems();
    int updatedInventoryCount = items["stick"] + 1;
    int oldMunnyBalance = items["Munny"];
    //then call buy function
    EXPECT_EQ(items["stick"], updatedInventoryCount);
    EXPECT_LT(items["munny"], oldMunnyBalance);
}

TEST(DavidTestCases, SellToTrader) {
    Inventory inventory;
    std::unordered_map<std::string, int> items = inventory.getAllItems();
    int updatedInventoryCount = items["iron"] - 1;
    int oldMunnyBalance = items["iron"];
    //then call sell function
    EXPECT_EQ(items["iron"], updatedInventoryCount);
    EXPECT_GT(items["iron"], oldMunnyBalance);
}

TEST(DavidTestCases, SimpleCrafting) {
    Inventory inventory;
    std::unordered_map<std::string, int> items = inventory.getAllItems();
    int updatedFishInventoryCount = items["fish"] - 1;
    int updatedBatterInventoryCount = items["batter"] - 1;
    //then call crafting function
    EXPECT_EQ(items["fish"], updatedFishInventoryCount);
    EXPECT_EQ(items["batter"], updatedBatterInventoryCount);
    EXPECT_EQ(items["fishsticks"], 1);
}