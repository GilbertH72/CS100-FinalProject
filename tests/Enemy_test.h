#ifndef __ENEMY_TEST_H__
#define __ENEMY_TEST_H__

#include "../header/Enemy.h"
#include "../header/Slime.h"
#include "../header/Spider.h"
#include "../header/Goblin.h"
#include "../header/Orc.h"
#include "../header/Dragon.h"
#include "gtest/gtest.h"

TEST(EnemyTest, SlimeLevel1)
{
   Slime* slime_1 = new Slime(1);
   EXPECT_EQ(slime_1->getEnemyHP(), 2);
   EXPECT_EQ(slime_1->getEnemyAttack(), 2);
   EXPECT_EQ(slime_1->getEnemyDefense(), 2);
   EXPECT_NEAR(slime_1->getEnemyLevel(), 1, 5);
   EXPECT_TRUE(slime_1->getEnemyEXP() > 1);
   EXPECT_EQ(slime_1->getName(), "Slime");
   EXPECT_NEAR(slime_1->attackChar(5), 2, 10);

   delete slime_1;
}

TEST(EnemyTest, SlimeLevel5)
{
   Slime* slime_1 = new Slime(5);
   EXPECT_NEAR(slime_1->getEnemyHP(), 15, 10);
   EXPECT_NEAR(slime_1->getEnemyAttack(), 15, 10);
   EXPECT_NEAR(slime_1->getEnemyDefense(), 15, 10);
   EXPECT_NEAR(slime_1->getEnemyLevel(), 10, 10);
   EXPECT_TRUE(slime_1->getEnemyEXP() > 1);
   EXPECT_EQ(slime_1->getName(), "Slime");
   EXPECT_NEAR(slime_1->attackChar(5), 15, 10);

   delete slime_1;
}

TEST(EnemyTest, SpiderLevel1)
{
   Spider* spider_1 = new Spider(1);
   EXPECT_EQ(spider_1->getEnemyHP(), 2);
   EXPECT_EQ(spider_1->getEnemyAttack(), 2);
   EXPECT_EQ(spider_1->getEnemyDefense(), 3);
   EXPECT_NEAR(spider_1->getEnemyLevel(), 1, 5);
   EXPECT_TRUE(spider_1->getEnemyEXP() > 1);
   EXPECT_EQ(spider_1->getName(), "Spider");
   EXPECT_NEAR(spider_1->attackChar(5), 2, 10);

   delete spider_1;
}

TEST(EnemyTest, SpiderLevel5)
{
   Spider* spider_1 = new Spider(5);
   EXPECT_NEAR(spider_1->getEnemyHP(), 15, 10);
   EXPECT_NEAR(spider_1->getEnemyAttack(), 15, 10);
   EXPECT_NEAR(spider_1->getEnemyDefense(), 15, 10);
   EXPECT_NEAR(spider_1->getEnemyLevel(), 10, 10);
   EXPECT_TRUE(spider_1->getEnemyEXP() > 1);
   EXPECT_EQ(spider_1->getName(), "Spider");
   EXPECT_NEAR(spider_1->attackChar(5), 15, 10);

   delete spider_1;
}

TEST(EnemyTest, GoblinLevel1)
{
   Goblin* goblin_1 = new Goblin(1);
   EXPECT_EQ(goblin_1->getEnemyHP(), 2);
   EXPECT_EQ(goblin_1->getEnemyAttack(), 3);
   EXPECT_EQ(goblin_1->getEnemyDefense(), 2);
   EXPECT_NEAR(goblin_1->getEnemyLevel(), 1, 5);
   EXPECT_TRUE(goblin_1->getEnemyEXP() > 1);
   EXPECT_EQ(goblin_1->getName(), "Goblin");
   EXPECT_NEAR(goblin_1->attackChar(5), 2, 10);

   delete goblin_1;
}

TEST(EnemyTest, GoblinLevel5)
{
   Goblin* goblin_1 = new Goblin(5);
   EXPECT_NEAR(goblin_1->getEnemyHP(), 15, 10);
   EXPECT_NEAR(goblin_1->getEnemyAttack(), 15, 10);
   EXPECT_NEAR(goblin_1->getEnemyDefense(), 15, 10);
   EXPECT_NEAR(goblin_1->getEnemyLevel(), 10, 10);
   EXPECT_TRUE(goblin_1->getEnemyEXP() > 1);
   EXPECT_EQ(goblin_1->getName(), "Goblin");
   EXPECT_NEAR(goblin_1->attackChar(5), 15, 10);

   delete goblin_1;
}

TEST(EnemyTest, OrcLevel1)
{
   Orc* orc_1 = new Orc(1);
   EXPECT_EQ(orc_1->getEnemyHP(), 3);
   EXPECT_EQ(orc_1->getEnemyAttack(), 3);
   EXPECT_EQ(orc_1->getEnemyDefense(), 3);
   EXPECT_NEAR(orc_1->getEnemyLevel(), 1, 6);
   EXPECT_TRUE(orc_1->getEnemyEXP() > 1);
   EXPECT_EQ(orc_1->getName(), "Orc");
   EXPECT_NEAR(orc_1->attackChar(5), 4, 10);

   delete orc_1;
}

TEST(EnemyTest, OrcLevel5)
{
   Orc* orc_1 = new Orc(5);
   EXPECT_NEAR(orc_1->getEnemyHP(), 20, 15);
   EXPECT_NEAR(orc_1->getEnemyAttack(), 20, 15);
   EXPECT_NEAR(orc_1->getEnemyDefense(), 20, 15);
   EXPECT_NEAR(orc_1->getEnemyLevel(), 15, 15);
   EXPECT_TRUE(orc_1->getEnemyEXP() > 1);
   EXPECT_EQ(orc_1->getName(), "Orc");
   EXPECT_NEAR(orc_1->attackChar(5), 15, 15);

   delete orc_1;
}

TEST(EnemyTest, DragonLevel1)
{
   Dragon* dragon_1 = new Dragon(1);
   EXPECT_EQ(dragon_1->getEnemyHP(), 5);
   EXPECT_EQ(dragon_1->getEnemyAttack(), 4);
   EXPECT_EQ(dragon_1->getEnemyDefense(), 4);
   EXPECT_NEAR(dragon_1->getEnemyLevel(), 1, 10);
   EXPECT_TRUE(dragon_1->getEnemyEXP() > 1);
   EXPECT_EQ(dragon_1->getName(), "Dragon");
   EXPECT_NEAR(dragon_1->attackChar(5), 5, 10);

   delete dragon_1;
}

TEST(EnemyTest, DragonLevel5)
{
   Dragon* dragon_1 = new Dragon(5);
   EXPECT_NEAR(dragon_1->getEnemyHP(), 25, 15);
   EXPECT_NEAR(dragon_1->getEnemyAttack(), 25, 15);
   EXPECT_NEAR(dragon_1->getEnemyDefense(), 25, 15);
   EXPECT_NEAR(dragon_1->getEnemyLevel(), 20, 15);
   EXPECT_TRUE(dragon_1->getEnemyEXP() > 1);
   EXPECT_EQ(dragon_1->getName(), "Dragon");
   EXPECT_NEAR(dragon_1->attackChar(5), 20, 20);

   delete dragon_1;
}

#endif
