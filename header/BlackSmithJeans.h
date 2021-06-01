#ifndef __BLACKSMITHJEANS_H__
#define __BLACKSMITHJEANS_H__

#include "Armor.h"

class BlackSmithJeans : public Armor
{
private:
   std::string name;

public:
   BlackSmithJeans() : Armor()
   {
      this->name = "";
      this->certainPiece = 1;
      this->charRole = 2;
   }
   BlackSmithJeans(int level, int typeStatus, std::string n) : Armor(level, typeStatus, 2, 1)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
