#ifndef __PLAYER_TEST_H__
#define __PLAYER_TEST_H__

#include "../header/BlackSmith.h"
#include "../header/Mage.h"
#include "../header/Warrior.h"
#include "gtest/gtest.h"

TEST(PlayerTest, DefaultWarriorPlayer)
{
   Player* player_1 = new Warrior("Kratos", WARRIOR);
   EXPECT_EQ(player_1->getMaxHP(), 10);
   EXPECT_EQ(player_1->getcurrentHP(), 10);
   EXPECT_EQ(player_1->getAttack(), 5);
   EXPECT_EQ(player_1->getDefense(), 5);
   EXPECT_EQ(player_1->getLevel(), 1);
   EXPECT_EQ(player_1->getcurrentEXP(), 0);
   EXPECT_EQ(player_1->getMaxEXP(), 100);
   EXPECT_TRUE(player_1->getcharType() == WARRIOR);
   EXPECT_TRUE(player_1->getTorso() == nullptr);
   EXPECT_TRUE(player_1->getLeggingsEQ() == nullptr);
   EXPECT_TRUE(player_1->getWeaponEQ() == nullptr);

   delete player_1;
}

TEST(PlayerTest, WarriorPlayerLevel2)
{
   Player* player_1 = new Warrior("Achilles", WARRIOR);
   player_1->setcurrentXP(100);
   player_1->levelUp();
   EXPECT_EQ(player_1->getMaxHP(), 13);
   EXPECT_EQ(player_1->getcurrentHP(), 13);
   EXPECT_EQ(player_1->getAttack(), 10);
   EXPECT_EQ(player_1->getDefense(), 7);
   EXPECT_EQ(player_1->getLevel(), 2);
   EXPECT_EQ(player_1->getMaxEXP(), 125);

   delete player_1;
}

TEST(PlayerTest, DefaultBlackSmithPlayer)
{
   Player* player_1 = new BlackSmith("Marx", BLACKSMITH);
   EXPECT_EQ(player_1->getMaxHP(), 10);
   EXPECT_EQ(player_1->getcurrentHP(), 10);
   EXPECT_EQ(player_1->getAttack(), 5);
   EXPECT_EQ(player_1->getDefense(), 5);
   EXPECT_EQ(player_1->getLevel(), 1);
   EXPECT_EQ(player_1->getcurrentEXP(), 0);
   EXPECT_EQ(player_1->getMaxEXP(), 100);
   EXPECT_TRUE(player_1->getcharType() == BLACKSMITH);
   EXPECT_TRUE(player_1->getTorso() == nullptr);
   EXPECT_TRUE(player_1->getLeggingsEQ() == nullptr);
   EXPECT_TRUE(player_1->getWeaponEQ() == nullptr);

   delete player_1;
}

TEST(PlayerTest, BlackSmithPlayerLevel2)
{
   Player* player_1 = new BlackSmith("Happisto", BLACKSMITH);
   player_1->setcurrentXP(100);
   player_1->levelUp();
   EXPECT_EQ(player_1->getMaxHP(), 13);
   EXPECT_EQ(player_1->getcurrentHP(), 13);
   EXPECT_EQ(player_1->getAttack(), 7);
   EXPECT_EQ(player_1->getDefense(), 10);
   EXPECT_EQ(player_1->getLevel(), 2);
   EXPECT_EQ(player_1->getMaxEXP(), 125);

   delete player_1;
}

TEST(PlayerTest, defaultMagePlayer)
{
   Player* player_1 = new Mage("Rohan", MAGE);
   EXPECT_EQ(player_1->getMaxHP(), 10);
   EXPECT_EQ(player_1->getcurrentHP(), 10);
   EXPECT_EQ(player_1->getAttack(), 5);
   EXPECT_EQ(player_1->getDefense(), 5);
   EXPECT_EQ(player_1->getLevel(), 1);
   EXPECT_EQ(player_1->getcurrentEXP(), 0);
   EXPECT_EQ(player_1->getMaxEXP(), 100);
   EXPECT_TRUE(player_1->getcharType() == MAGE);
   EXPECT_TRUE(player_1->getTorso() == nullptr);
   EXPECT_TRUE(player_1->getLeggingsEQ() == nullptr);
   EXPECT_TRUE(player_1->getWeaponEQ() == nullptr);

   delete player_1;
}

TEST(PlayerTest, MagePlayerLevel2)
{
   Player* player_1 = new Mage("Azhi", MAGE);
   player_1->setcurrentXP(100);
   player_1->levelUp();
   EXPECT_EQ(player_1->getMaxHP(), 15);
   EXPECT_EQ(player_1->getcurrentHP(), 15);
   EXPECT_EQ(player_1->getAttack(), 8);
   EXPECT_EQ(player_1->getDefense(), 7);
   EXPECT_EQ(player_1->getLevel(), 2);
   EXPECT_EQ(player_1->getMaxEXP(), 125);
   
   delete player_1;
}

TEST(PlayerTest, CustomPlayer)
{
   Player* player_1 = new Mage("Merlin", MAGE);
   player_1->setcurrentXP(100);
   player_1->levelUp();
   player_1->setcurrentXP(125);
   player_1->levelUp();
   player_1->setcurrentXP(150);
   player_1->levelUp();
   player_1->setcurrentXP(175);
   player_1->levelUp();
   player_1->setDefense(100);
   player_1->setAttack(100);
   EXPECT_EQ(player_1->getMaxHP(), 22);
   EXPECT_EQ(player_1->getcurrentHP(), 22);
   EXPECT_EQ(player_1->getAttack(), 125);
   EXPECT_EQ(player_1->getDefense(), 113);
   EXPECT_EQ(player_1->getLevel(), 5);
   EXPECT_EQ(player_1->getMaxEXP(), 200);
   EXPECT_EQ(player_1->getcurrentEXP(), 0);

   delete player_1;
}

#endif
