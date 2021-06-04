#ifndef __CREATE_MAGE_ITEM__
#define __CREATE_MAGE_ITEM__

#include "EquipFactory.h"
#include "Cloak.h"
#include "MageSkirt.h"
#include "Tome.h"

class CreateMageItemFactory : public EquipFactory {
public:
   virtual Cloak* makeTorsoArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Cloak";
      return new Cloak(lvl, randomVal, name);
   }

   virtual MageSkirt* makeLegArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Mage Skirt";
      return new MageSkirt(lvl, randomVal, name);
   }

   virtual Tome* makeWeapon(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Tome";
      return new Tome(lvl, randomVal, name);
   }

};

#endif
