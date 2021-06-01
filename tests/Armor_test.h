#ifndef __ARMOR_TEST_H__
#define __ARMOR_TEST_H__

#include "../header/Armor.h"
#include "../header/ChestPlate.h"
#include "../header/Cloak.h"
#include "../header/Vest.h"
#include "../header/WarriorLeggings.h"
#include "../header/MageSkirt.h"
#include "../header/BlackSmithJeans.h"
#include "gtest/gtest.h"

TEST(ArmorTest, defaultArmor)
{
   Armor* armor_1 = new Armor();
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);

   delete armor_1;
}

TEST(ArmorTest, customizedArmor)
{
   Armor* armor_1 = new Armor(10, 3, 0, 1);
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 10);
   EXPECT_EQ(armor_1->getValue(), 16);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);

   delete armor_1;
}

TEST(ArmorTest, defaultChestPlate)
{
   ChestPlate* armor_1 = new ChestPlate();
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customizedChestplate)
{
   ChestPlate* armor_1 = new ChestPlate(10, 3, "Novice Chestplate");
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 10);
   EXPECT_EQ(armor_1->getValue(), 16);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);
   EXPECT_EQ(armor_1->getName(), "Novice Chestplate");

   delete armor_1;
}

TEST(ArmorTest, defaultCloak)
{
   Cloak* armor_1 = new Cloak();
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 1);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customizedCloak)
{
   Cloak* armor_1 = new Cloak(15, 4, "Great Cloak");
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 15);
   EXPECT_EQ(armor_1->getValue(), 23);
   EXPECT_EQ(armor_1->getCharacterRole(), 1);
   EXPECT_EQ(armor_1->getName(), "Great Cloak");

   delete armor_1;
}

TEST(ArmorTest, defaultVest)
{
   Vest* armor_1 = new Vest();
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 2);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customizedVest)
{
   Vest* armor_1 = new Vest(20, 5, "Artisan Vest");
   EXPECT_TRUE(!armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 20);
   EXPECT_EQ(armor_1->getValue(), 30);
   EXPECT_EQ(armor_1->getCharacterRole(), 2);
   EXPECT_EQ(armor_1->getName(), "Artisan Vest");

   delete armor_1;
}

TEST(ArmorTest, defaultWarriorLeggings)
{
   WarriorLeggings* armor_1 = new WarriorLeggings();
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customArmoredLeggings)
{
   WarriorLeggings* armor_1 = new WarriorLeggings(1, 1, "Basic Warrior Leggings");
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 3);
   EXPECT_EQ(armor_1->getCharacterRole(), 0);
   EXPECT_EQ(armor_1->getName(), "Basic Warrior Leggings");

   delete armor_1;
}

TEST(ArmorTest, defaultMageSkirt)
{
   MageSkirt* armor_1 = new MageSkirt();
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 1);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customMageSkirt)
{
   MageSkirt* armor_1 = new MageSkirt(25, 6, "Epic Mage Skirt");
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 25);
   EXPECT_EQ(armor_1->getValue(), 37);
   EXPECT_EQ(armor_1->getCharacterRole(), 1);
   EXPECT_EQ(armor_1->getName(), "Epic Mage Skirt");

   delete armor_1;
}

TEST(ArmorTest, defaultBlackSmithJeans)
{
   BlackSmithJeans* armor_1 = new BlackSmithJeans();
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 1);
   EXPECT_EQ(armor_1->getValue(), 5);
   EXPECT_EQ(armor_1->getCharacterRole(), 2);
   EXPECT_EQ(armor_1->getName(), "");

   delete armor_1;
}

TEST(ArmorTest, customBlackSmithJeans)
{
   BlackSmithJeans* armor_1 = new BlackSmithJeans(25, 6, "Epic Black Smith Jeans");
   EXPECT_TRUE(armor_1->TorsoOrLegEquip());
   EXPECT_EQ(armor_1->getLevel(), 25);
   EXPECT_EQ(armor_1->getValue(), 37);
   EXPECT_EQ(armor_1->getCharacterRole(), 2);
   EXPECT_EQ(armor_1->getName(), "Epic Black Smith Jeans");

   delete armor_1;
}

#endif
