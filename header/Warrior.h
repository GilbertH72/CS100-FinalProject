#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "Player.h"

class Warrior : public Player 
{
    public:
        Warrior();
        ~Warrior();

        void gainExp();
};

#endif
