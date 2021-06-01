#ifndef __ORC_H__
#define __ORC_H__

#include "Enemy.h"

class Orc : public Enemy {
public:
   Orc() {}

   Orc(int charLevel)
   {
      srand(time(NULL));
      this->name = "Orc";
      this->health = 3 * charLevel + rand() % (4 * charLevel / 3);
      this->attack = 3 * charLevel + rand() % (4 * charLevel / 3);
      this->defense = 3 * charLevel + rand() % (4 * charLevel / 3);
      this->level = abs(charLevel - 3 + rand() % 6) + 3;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   virtual int attackChar(int charDefense)
   {
      return (((((2 * this->level / 6) + 2) * (32 + (this->level * 8 / 10)) * this->attack) / charDefense) / 55) + 3;
   }
};

#endif
