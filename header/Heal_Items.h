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
   Heal_Items();
   Heal_Items(int level, int typeStatus, std::string name);
   
   // Getter Functions
   int getLevel();
   int getValue();
   std::string getName();
};
#endif
