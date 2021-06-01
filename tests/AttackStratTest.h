#ifndef __ATTACKSTRAT_TEST_H__
#define __ATTACKSTRAT_TEST_H__

#include "../header/BlackSmithAttackStrat.h"
#include "../header/WarriorAttackStrat.h"
#include "../header/MageAttackStrat.h"
#include "../header/BlackSmith.h"
#include "../header/Mage.h"
#include "../header/Warrior.h"
#include "../header/Dragon.h"
#include "../header/Orc.h"
#include "../header/Goblin.h"
#include "../header/Slime.h"
#include "../header/Spider.h"
#include "../src/BlackSmith.cpp"
#include "../src/Mage.cpp"
#include "../src/Warrior.cpp"
#include "gtest/gtest.h"

TEST(AttackStratTest, BlackSmithAttackStratLeve1VSDragon)
{
   Dragon* dragon_1 = new Dragon(1);
   BlackSmith* bSmith_1 = new BlackSmith("Marx", BLACKSMITH);
   EXPECT_EQ(bSmith_1->attack(dragon_1), 4);
}

TEST(AttackStratTest, MageAttackStratLeve1VSOrc)
{
   Orc* orc_1 = new Orc(1);
   Mage* mage1 = new Mage("Rohan", MAGE);
   EXPECT_EQ(mage1->attack(orc_1), 2);
}

TEST(AttackStratTest, WarriorAttackStratLv1VSGoblin)
{
   Goblin* goblin_1 = new Goblin(1);
   Warrior* warrior_1 = new Warrior("Kratos", WARRIOR);
   EXPECT_EQ(warrior_1->attack(goblin_1), 2);
}

TEST(AttackStratTest, BlackSmithAttackStratLeve5VSDragon)
{
   Dragon* dragon_1 = new Dragon(5);
   BlackSmith* bSmith_1 = new BlackSmith("Marx", BLACKSMITH);
   bSmith_1->setcurrentXP(550);
   EXPECT_EQ(bSmith_1->attack(dragon_1), 41);
}

TEST(AttackStratTest, MageAttackStratLeve5VSSlime)
{
   Slime* slime_1 = new Slime(5);
   Mage* mage1 = new Mage("Rohan", MAGE);
   mage1->setcurrentXP(550);
   EXPECT_EQ(mage1->attack(slime_1), 13);
}

TEST(AttackStratTest, WarriorAttackStratLv5VSSpider) {
   Spider* spider_1 = new Spider(5);
   Warrior* warrior_1 = new Warrior("Scott", WARRIOR);
   warrior_1->setcurrentXP(550);
   EXPECT_EQ(warrior_1->attack(spider_1), 3);
}

#endif
