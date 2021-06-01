#ifndef __WEAPON_H__
#define __WEAPON_H__

#include "Equips.h"

class Weapon : public Equips
{
public:
   Weapon() : Equips() {};
   Weapon(int level, int typeStatus, int charRole) : Equips(level, typeStatus, charRole) {};

   virtual bool setToArmor()
   {
      return false;
   }
};

#endif
