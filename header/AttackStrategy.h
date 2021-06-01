#ifndef __ATTACKSTRATEGY_H__
#define __ATTACKSTRATEGY_H__

#include "Player.h"
#include "Enemy.h"
#include <iostream>
#include <cstdlib>

class Player;
class AttackStrategy {

public:
   AttackStrategy() {};

   virtual int attackEnemy(Player* currCharacter, Enemy* currEnemy) = 0;
};

#endif
