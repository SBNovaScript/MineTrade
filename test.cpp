#include "pch.h"
#include "../MineText/Header.h"

TEST(DavidTestCases, BuyFromTrader) {
    NomadInventory inventory;
    int updatedInventoryCount = inventory.stick + 1;
    int oldMunnyBalance = inventory.munny;
    //then call buy function
    EXPECT_EQ(inventory.stick, updatedInventoryCount);
    EXPECT_LT(inventory.munny, oldMunnyBalance);
}

TEST(DavidTestCases, SellToTrader) {
    NomadInventory inventory;
    int updatedInventoryCount = inventory.iron - 1;
    int oldMunnyBalance = inventory.munny;
    //then call sell function
    EXPECT_EQ(inventory.iron, updatedInventoryCount);
    EXPECT_GT(inventory.munny, oldMunnyBalance);
}

TEST(DavidTestCases, SimpleCrafting) {
    NomadInventory inventory;
    int updatedFishInventoryCount = inventory.fish - 1;
    int updatedBatterInventoryCount = inventory.batter - 1;
    //then call crafting function
    EXPECT_EQ(inventory.fish, updatedFishInventoryCount);
    EXPECT_EQ(inventory.batter, updatedBatterInventoryCount);
    EXPECT_EQ(inventory.fishsticks, 1);
}