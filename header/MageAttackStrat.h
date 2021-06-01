#ifndef __MAGE_ATTACK_STAT_H__
#define __MAGE_ATTACK_STAT_H__

#include "Player.h"
#include "AttackStrategy.h"

class MageAttackStrat : public AttackStrategy {

public:
   MageAttackStrat() : AttackStrategy() { };

   int attackEnemy(Player* currCharacter, Enemy* currEnemy)
   {
      return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * ((currCharacter->getcurrentHP() / 2) + 2) * currCharacter->getAttack()) / currEnemy->getEnemyDefense()) / 50) + 2);
   }
};

#endif
