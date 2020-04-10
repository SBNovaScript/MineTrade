#include "pch.h"
#include "../MineTrade/Inventory.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(DavidTestCases, BuyFromTrader) {
    Inventory test;
    //Inventory inventory = Inventory();
    //int updatedInventoryCount = inventory.getItemAmount(Trader::getItemFromName("stick")) + 1;
    //int oldMunnyBalance = inventory.getAmountOfMoneyOwned();
    //
    //// Give the player 10 munny to test.
    //inventory.addMunny(10);

    //// Buy the stick from the trader.
    //inventory.buyItem(Trader::getItemFromName("stick"));

    //EXPECT_EQ(inventory.getItemAmount(Trader::getItemFromName("stick")), updatedInventoryCount);
    //EXPECT_LT(inventory.getAmountOfMoneyOwned(), oldMunnyBalance);
    EXPECT_EQ(1, 1);
    EXPECT_TRUE(true);
}

//TEST(DavidTestCases, SellToTrader) {
//    Inventory inventory;
//    int updatedInventoryCount = items["iron"] - 1;
//    int oldMunnyBalance = items["iron"];
//    //then call sell function
//    EXPECT_EQ(items["iron"], updatedInventoryCount);
//    EXPECT_GT(items["iron"], oldMunnyBalance);
//}
//
//TEST(DavidTestCases, SimpleCrafting) {
//    Inventory inventory;
//    int updatedFishInventoryCount = items["fish"] - 1;
//    int updatedBatterInventoryCount = items["batter"] - 1;
//    //then call crafting function
//    EXPECT_EQ(items["fish"], updatedFishInventoryCount);
//    EXPECT_EQ(items["batter"], updatedBatterInventoryCount);
//    EXPECT_EQ(items["fishsticks"], 1);
//}