#ifndef __WEAPON_TEST_H__
#define __WEAPON_TEST_H__

#include "../header/Equips.h"
#include "../header/Weapon.h"
#include "../header/Hammer.h"
#include "../header/Sword.h"
#include "../header/Tome.h"
#include "gtest/gtest.h"

TEST(WeaponTest, defaultWeapon)
{
   Weapon* weapon_1 = new Weapon();
   EXPECT_EQ(weapon_1->getLevel(), 1);
   EXPECT_EQ(weapon_1->getValue(), 5);
   EXPECT_EQ(weapon_1->getCharacterRole(), 0);
   EXPECT_TRUE(!weapon_1->setToArmor());

   delete weapon_1;
}

TEST(WeaponTest, customizedWeapon)
{
   Weapon* weapon_1 = new Weapon(10, 3 ,0);
   EXPECT_EQ(weapon_1->getLevel(), 10);
   EXPECT_EQ(weapon_1->getValue(), 16);
   EXPECT_EQ(weapon_1->getCharacterRole(), 0);
   EXPECT_TRUE(!weapon_1->setToArmor());

   delete weapon_1;
}

TEST(WeaponTest, defaultSword)
{
   Sword* weapon_1 = new Sword();
   EXPECT_EQ(weapon_1->getLevel(), 1);
   EXPECT_EQ(weapon_1->getValue(), 5);
   EXPECT_EQ(weapon_1->getCharacterRole(), 0);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "");

   delete weapon_1;
}

TEST(WeaponTest, customizedSword)
{
   Sword* weapon_1 = new Sword(15, 4, "Great Sword");
   EXPECT_EQ(weapon_1->getLevel(), 15);
   EXPECT_EQ(weapon_1->getValue(), 23);
   EXPECT_EQ(weapon_1->getCharacterRole(), 0);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "Great Sword");

   delete weapon_1;
}

TEST(WeaponTest, defaultTome)
{
   Tome* weapon_1 = new Tome();
   EXPECT_EQ(weapon_1->getLevel(), 1);
   EXPECT_EQ(weapon_1->getValue(), 5);
   EXPECT_EQ(weapon_1->getCharacterRole(), 1);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "");

   delete weapon_1;
}

TEST(WeaponTest, customTome)
{
   Tome* weapon_1 = new Tome(10, 3, "Novice Tome");
   EXPECT_EQ(weapon_1->getLevel(), 10);
   EXPECT_EQ(weapon_1->getValue(), 16);
   EXPECT_EQ(weapon_1->getCharacterRole(), 1);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "Novice Tome");

   delete weapon_1;
}

TEST(WeaponTest, defaultHammer)
{
   Hammer* weapon_1 = new Hammer();
   EXPECT_EQ(weapon_1->getLevel(), 1);
   EXPECT_EQ(weapon_1->getValue(), 5);
   EXPECT_EQ(weapon_1->getCharacterRole(), 2);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "");

   delete weapon_1;
}

TEST(WeaponTest, customHammer)
{
   Hammer* weapon_1 = new Hammer(30, 7, "Legendary Hammer");
   EXPECT_EQ(weapon_1->getLevel(), 30);
   EXPECT_EQ(weapon_1->getValue(), 44);
   EXPECT_EQ(weapon_1->getCharacterRole(), 2);
   EXPECT_TRUE(!weapon_1->setToArmor());
   EXPECT_EQ(weapon_1->getName(), "Legendary Hammer");

   delete weapon_1;
}

#endif
