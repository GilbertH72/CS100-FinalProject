#ifndef __CHESTPLATE_H__
#define __CHESTPLATE_H__

#include "Armor.h"

class ChestPlate : public Armor
{
private:
   std::string name;

public:
   ChestPlate() : Armor()
   {
      this->name = "";
      this->charRole = 0;
   }
   ChestPlate(int level, int typeStatus, std::string n) : Armor(level, typeStatus, 0, 0)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
