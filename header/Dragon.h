#ifndef __DRAGON_H__
#define __DRAGON_H__

#include "Enemy.h"

class Dragon : public Enemy {
public:
   Dragon() {}

   Dragon(int charLevel)
   {
      srand(time(NULL));
      this->name = "Dragon";
      this->health = 5 * charLevel + rand() % (4 * charLevel / 3);
      this->attack = 4 * charLevel + rand() % (4 * charLevel / 3);
      this->defense = 4 * charLevel + rand() % (4 * charLevel / 3);
      this->level = abs(charLevel - 3 + rand() % 6) + 5;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   virtual int attackChar(int charDefense)
   {
      return (((((2 * this->level / 6) + 2) * (32 + (this->level * 9 / 10)) * this->attack) / charDefense) / 55) + 3;
   }
};

#endif
