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
   Equips();
   Equips(int level, int typeStatus, int charRole);

   // Getters
   int getLevel();
   int getValue();
   int getCharacterRole();

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
