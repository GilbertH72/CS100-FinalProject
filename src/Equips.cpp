#include "../header/Equips.h"

Equips::Equips()
{
   // For minimum level to equip Weapon/Armor, value for stat increase
   // And role for corrsponding character
   this->level = 1;
   this->value = 5;
   this->charRole = 0;
}

Equips::Equips(int level, int typeStatus, int charRole)
{
   // Sample calculation for value (Adjustment may be done later on)
   this->level = level;
   this->value = level + (typeStatus * 2);
   this->charRole = charRole;
}

int Equips::getLevel()
{
   return this->level;
}

int Equips::getValue()
{
   return this->value;
}

int Equips::getCharacterRole()
{
   return this->charRole;
}
