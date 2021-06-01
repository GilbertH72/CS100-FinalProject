#ifndef __MAGE_H__
#define __MAGE_H__

#include "Player.h"


class Mage : public Player {

public:
   Mage(std::string, playerType);
   virtual int attack(Enemy* currentEnemy);
   virtual void levelUp();

};


#endif
