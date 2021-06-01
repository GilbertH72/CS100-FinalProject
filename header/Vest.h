#ifndef __VEST_H__
#define __VEST_H__

#include "Armor.h"

class Vest : public Armor
{
private:
   std::string name;

public:
   Vest() : Armor()
   {
      this->name = "";
      this->charRole = 2;
   }
   Vest(int level, int typeStatus, std::string n) : Armor(level, typeStatus, 2, 0)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
