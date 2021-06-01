#ifndef __CLOAK_H__
#define __CLOAK_H__

#include "Armor.h"

class Cloak : public Armor
{
private:
   std::string name;

public:
   Cloak() : Armor()
   {
      this->name = "";
      this->charRole = 1;
   }
   Cloak(int level, int typeStatus, std::string n): Armor(level, typeStatus, 1, 0)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
