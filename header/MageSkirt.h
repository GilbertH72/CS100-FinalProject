#ifndef __MAGESKIRT_H__
#define __MAGESKIRT_H__

#include "Armor.h"

class MageSkirt : public Armor
{
private:
   std::string name;

public:
   MageSkirt(): Armor()
   {
      this->name = "";
      this->certainPiece = 1;
      this->charRole = 1;
   }
   MageSkirt(int level, int typeStatus, std::string n) : Armor(level, typeStatus, 1, 1)
   {
      this->name = n;
   }

   virtual std::string getName()
   {
      return this->name;
   }
};

#endif
