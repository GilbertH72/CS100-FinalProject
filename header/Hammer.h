#ifndef __HAMMER_H__
#define __HAMMER_H__

#include "Weapon.h"

class Hammer : public Weapon {
private:
   std::string name;

public:
   Hammer() : Weapon()
   {
      this->name = "";
      this->charRole = 2;
   }
   Hammer(int level, int typeStatus, std::string n) : Weapon(level, typeStatus, 2)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
