#ifndef __WARRIORLEGGINGS_H__
#define __WARRIORLEGGINGS_H__

#include "Armor.h"

class WarriorLeggings : public Armor
{
private:
   std::string name;

public:
   WarriorLeggings() : Armor()
   {
      this->name = "";
      this->certainPiece = 1;
      this->charRole = 0;
   }
   WarriorLeggings(int level, int typeStatus, std::string n) : Armor(level, typeStatus, 0, 1)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
