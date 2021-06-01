#ifndef __BLACKSMITH_ATTACK_STAT_H__
#define __BLACKSMITH_ATTACK_STAT_H__

#include "Player.h"
#include "AttackStrategy.h"

class BlackSmithAttackStrat : public AttackStrategy {

public:
   BlackSmithAttackStrat() : AttackStrategy() { };

   int attackEnemy(Player* currCharacter, Enemy* currEnemy)
   {
      return abs((((((2 * currCharacter->getLevel() / 5) + 2) * (35 + (currCharacter->getLevel())) * currCharacter->getAttack()) / currEnemy->getEnemyDefense()) / 50) + 1);
   }
};

#endif
