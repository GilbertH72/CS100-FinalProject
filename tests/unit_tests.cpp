#include "gtest/gtest.h"
#include "Heal_Items_test.h"
#include "Enemy_test.h"
#include "Weapon_test.h"
#include "Armor_test.h"
#include "AttackStratTest.h"

int main(int argc, char** argv)
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}
