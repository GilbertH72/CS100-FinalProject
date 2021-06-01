#ifndef __BLACKSMITH_H__
#define __BLACKSMITH_H__

#include "Player.h"


class BlackSmith : public Player {

public:
   BlackSmith(std::string, playerType);
   ~BlackSmith();
   virtual int attack(Enemy* currentEnemy);
   virtual void levelUp();

};


#endif
