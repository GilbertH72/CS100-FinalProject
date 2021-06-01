#ifndef __TOME_H__
#define __TOME_H__

#include "Weapon.h"

class Tome : public Weapon {
private:
   std::string name;

public:
   Tome() : Weapon()
   {
      this->name = "";
      this->charRole = 1;
   }
   Tome(int level, int typeStatus, std::string n) : Weapon(level, typeStatus, 1)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
