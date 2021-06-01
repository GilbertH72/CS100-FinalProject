#ifndef __ARMOR_H__
#define __ARMOR_H__

#include "Equips.h"

class Armor : public Equips
{
protected:
   // 0 for Torso and 1 for Leg Armor
   bool certainPiece = 0;

public:
   Armor(): Equips()
   {
      this->certainPiece = 0;
   }
   Armor(int level, int typeStatus, int charRole, bool TorsoOrLeg): Equips(level, typeStatus, charRole)
   {
      this->certainPiece = TorsoOrLeg;
   }

   virtual bool TorsoOrLegEquip()
   {
      return this->certainPiece;
   }
};

#endif
