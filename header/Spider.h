#ifndef __SPIDER_H__
#define __SPIDER_H__

#include "Enemy.h"

class Spider : public Enemy {
public:
   Spider() {}

   Spider(int charLevel)
   {
      srand(time(NULL));
      this->name = "Spider";
      this->health = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->attack = 2 * charLevel + rand() % (4 * charLevel / 3);
      this->defense = 3 * charLevel + rand() % (4 * charLevel / 3);
      this->level = abs(charLevel - 3 + rand() % 6) + 1;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   virtual int attackChar(int charDefense)
   {
      return (((((2 * this->level / 6) + 2) * (32 + (this->level * 7 / 10)) * this->attack) / charDefense) / 55) + 3;
   }
};

#endif
