#ifndef __EQUIPS_H__
#define __EQUIPS_H__

#include <string>

class Equips
{
protected:
   int level;
   int value;

   // This will be based on the character selection [0 = Warrior, 1 = Wizard, 2 = BlackSmith]
   int charRole;
   
public:
   Equips()
   {
      // For minimum level to equip Weapon/Armor, value for stat increase
      // And role for corrsponding character
      this->level = 1;
      this->value = 5;
      this->charRole = 0;
   }

   Equips(int level, int typeStatus, int charRole)
   {
      // Sample calculation for value (Adjustment may be done later on)
      this->level = level;
      this->value = level + (typeStatus * 2);
      this->charRole = charRole;
   }

   // Getters
   int getLevel() { return this->level; }
   int getValue(){ return this->value; }
   int getCharacterRole(){ return this->charRole; }

   // Virtual Function to be overriden within respective Classes (Weapon, Armor)
   virtual std::string getName()
   {
      return "";
   }

   virtual bool setToArmor()
   {
      return true;
   }

   virtual bool TorsoOrLegEquip()
   {
      return 0;
   }

};

#endif
