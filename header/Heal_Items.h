#ifndef __HEAL_ITEMS_H__
#define __HEAL_ITEMS_H__

#include <string>

class Heal_Items
{
protected:
   std::string name;
   int level;
   int value;

public:
   Heal_Items()
   {
      this->level = 1;
      this->value = 5;
   }

   Heal_Items(int level, int typeStatus, std::string name)
   {
      // Sample calculation for value (Adjustment may be done later on)
      this->level = level;
      this->value = level + (typeStatus * 2);
      this->name = name;
   }

   // Getters
   int getLevel() { return this->level; }
   int getValue() { return this->value; }
   std::string getName(){ return this->name; }

};

#endif
