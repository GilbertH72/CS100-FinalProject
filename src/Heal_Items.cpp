#include "../header/Heal_Items.h"

Heal_Items::Heal_Items()
{
   this->level = 1;
   this->value = 5;
}

Heal_Items::Heal_Items(int level, int typeStatus, std::string name)
{
   // Sample calculation for value (Adjustment may be done later on)
   this->level = level;
   this->value = level + (typeStatus * 2);
   this->name = name;
}

int Heal_Items::getLevel()
{
   return this->level;
}

int Heal_Items::getValue()
{
   return this->value;
}

std::string Heal_Items::getName()
{
   return this->name;
}
