#ifndef __SWORD_H__
#define __SWORD_H__

#include "Weapon.h"

class Sword : public Weapon {
private:
   std::string name;

public:
   Sword() : Weapon()
   {
      this->name = "";
      this->charRole = 0;
   }
   Sword(int level, int typeStatus, std::string n) : Weapon(level, typeStatus, 0)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
