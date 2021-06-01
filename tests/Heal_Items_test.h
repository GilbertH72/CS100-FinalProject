#ifndef __HEAL_ITEMS_TEST_H__
#define __HEAL_ITEMS_TEST_H__

#include "../header/Heal_Items.h"
#include "../src/Heal_Items.cpp"
#include "../header/Elixir.h"
#include "gtest/gtest.h"

TEST(Heal_Items_Test, defaultHealItems)
{
   Heal_Items* item_1 = new Heal_Items();
   EXPECT_EQ(item_1->getLevel(), 1);
   EXPECT_EQ(item_1->getValue(), 5);
   delete item_1;
}

TEST(Heal_Items_Test, customizedHealItem)
{
   Heal_Items* item_1 = new Heal_Items(25, 6, "Epic Heal Item");
   EXPECT_EQ(item_1->getLevel(), 25);
   EXPECT_EQ(item_1->getValue(), 37);
   EXPECT_EQ(item_1->getName(), "Epic Heal Item");
   delete item_1;
}

TEST(Heal_Items_Test, defaultElixir) {
   Elixir* elixir_1 = new Elixir();
   EXPECT_EQ(elixir_1->getLevel(), 1);
   EXPECT_EQ(elixir_1->getValue(), 5);
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir1) {
   Elixir* elixir_1 = new Elixir(1, 1, "Basic Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 1);
   EXPECT_EQ(elixir_1->getValue(), 3);
   EXPECT_EQ(elixir_1->getName(), "Basic Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir2) {
   Elixir* elixir_1 = new Elixir(5, 2, "Rookie Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 5);
   EXPECT_EQ(elixir_1->getValue(), 9);
   EXPECT_EQ(elixir_1->getName(), "Rookie Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir3) {
   Elixir* elixir_1 = new Elixir(10, 3, "Novice Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 10);
   EXPECT_EQ(elixir_1->getValue(), 16);
   EXPECT_EQ(elixir_1->getName(), "Novice Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir4) {
   Elixir* elixir_1 = new Elixir(15, 4, "Great Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 15);
   EXPECT_EQ(elixir_1->getValue(), 23);
   EXPECT_EQ(elixir_1->getName(), "Great Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir5) {
   Elixir* elixir_1 = new Elixir(20, 5, "Artisan Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 20);
   EXPECT_EQ(elixir_1->getValue(), 30);
   EXPECT_EQ(elixir_1->getName(), "Artisan Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir6) {
   Elixir* elixir_1 = new Elixir(25, 6, "Epic Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 25);
   EXPECT_EQ(elixir_1->getValue(), 37);
   EXPECT_EQ(elixir_1->getName(), "Epic Elixir");
   delete elixir_1;
}

TEST(Heal_Items_Test, CustomizedElixir7) {
   Elixir* elixir_1 = new Elixir(30, 7, "Legendary Elixir");
   EXPECT_EQ(elixir_1->getLevel(), 30);
   EXPECT_EQ(elixir_1->getValue(), 44);
   EXPECT_EQ(elixir_1->getName(), "Legendary Elixir");
   delete elixir_1;
}

#endif
