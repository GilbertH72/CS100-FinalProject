#ifndef __GAME_TEST_H__
#define __GAME_TEST_H__

#include "../header/Game.h"
#include "gtest/gtest.h"

Game* Game::gameInstance = nullptr;

TEST(GameTest, InstanceGameRunner)
{
   Game* gameRunner1 = gameRunner1->getInstance();
   EXPECT_TRUE(gameRunner1->getInstance() != nullptr);

   delete gameRunner1;
}

TEST(GameTest, AreaTest)
{
   Game* gameRunner1 = gameRunner1->getInstance();
   EXPECT_EQ(gameRunner1->getCurrentLocation(), DESERT);

   delete gameRunner1;
}


#endif
