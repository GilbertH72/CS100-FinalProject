#ifndef WARRIOR_H
#define WARRIOR_H

#include "character.h"

class Warrior : public Character 
{
    public:
        Warrior();
        ~Warrior();

        void gainExp();
};

#endif
