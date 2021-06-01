#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Player.h"


class Warrior : public Player {

public:
   Warrior(std::string, playerType);
   ~Warrior();
   virtual int attack(Enemy* currentEnemy);
   virtual void levelUp();

};


#endif
