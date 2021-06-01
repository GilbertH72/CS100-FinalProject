#ifndef __WARRIOR_ATTACK_STAT_H__
#define __WARRIOR_ATTACK_STAT_H__

#include "Player.h"
#include "AttackStrategy.h"

class WarriorAttackStrat : public AttackStrategy {

public:
   WarriorAttackStrat() : AttackStrategy() { };

   int attackEnemy(Player* currCharacter, Enemy* currEnemy)
   {
      return abs(((((((2 * currCharacter->getLevel()) / 5) + 2) * 35 * currCharacter->getAttack()) * currCharacter->getMaxHP() / currCharacter->getcurrentHP()) / currCharacter->getcurrentHP() / 50) + 2);
   }
};

#endif
