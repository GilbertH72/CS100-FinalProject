#ifndef __GOBLIN_H__
#define __GOBLIN_H__

#include "Enemy.h"

class Goblin : public Enemy {
public:
   Goblin() {}

   Goblin(int charLevel)
   {
      srand(time(NULL));
      this->name = "Goblin";
      this->health = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->attack = 3 * charLevel + rand() % (4 * charLevel / 3);
      this->defense = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->level = abs(charLevel - 3 + rand() % 6) + 1;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   virtual int attackChar(int charDefense)
   {
      return (((((2 * this->level / 6) + 2) * (32 + (this->level * 8 / 10)) * this->attack) / charDefense) / 55) + 3;
   }
};

#endif
