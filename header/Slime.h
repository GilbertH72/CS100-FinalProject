#ifndef __SLIME_H__
#define __SLIME_H__

#include "Enemy.h"

class Slime : public Enemy {
public:
   Slime() {}

   Slime(int charLevel)
   {
      srand(time(NULL));
      this->name = "Slime";
      this->health = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->attack = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->defense = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->level = abs(charLevel - 2 + rand() % 6) + 1;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   virtual int attackChar(int charDefense)
   {
      return (((((2 * this->level / 6) + 2) * (32 + (this->level * 6 / 10)) * this->attack) / charDefense) / 55) + 3;
   }
};

#endif
