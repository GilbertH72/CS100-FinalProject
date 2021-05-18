#ifndef __HEAL_ITEMS_TEST_H__
#define __HEAL_ITEMS_TEST_H__

#include "../header/Heal_Items.h"
#include "../header/Elixir.h"
#include "gtest/gtest.h"

TEST(Heal_Items_Test, defaultHealItems)
{
   Heal_Items* item_1 = new Heal_Items();
   EXPECT_EQ(item_1->getLevel(), 1);
   EXPECT_EQ(item_1->getValue(), 5);
}

TEST(Heal_Items_Test, customizedHealItem)
{
   Heal_Items* item_1 = new Heal_Items(10, 5, "Epic Elixir");
   EXPECT_EQ(item_1->getLevel(), 10);
   EXPECT_EQ(item_1->getValue(), 20);
   EXPECT_EQ(item_1->getName(), "Epic Elixir");

}

TEST(Heal_Items_Test, defaultElixir) {
   Elixir* elixir_1 = new Elixir();
   EXPECT_EQ(elixir_1->getLevel(), 1);
   EXPECT_EQ(elixir_1->getValue(), 5);
}

TEST(Heal_Items_Test, CustomizedElixir1) {
   Elixir* elixir_1 = new Elixir(15, 2, "Commoner's Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 15);
   EXPECT_EQ(elixir_1->getValue(), 19);
   EXPECT_EQ(elixir_1->getName(), "Commoner's Elixir");
}

TEST(Heal_Items_Test, CustomizedElixir2) {
   Elixir* elixir_1 = new Elixir(25, 4, "Great Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 25);
   EXPECT_EQ(elixir_1->getValue(), 33);
   EXPECT_EQ(elixir_1->getName(), "Great Elixir");
}

#endif
