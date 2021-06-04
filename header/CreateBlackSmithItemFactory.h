#ifndef __CREATE_BLACKSMITH_ITEM__
#define __CREATE_BLACKSMITH_ITEM__

#include "EquipFactory.h"
#include "Vest.h"
#include "BlackSmithJeans.h"
#include "Hammer.h"

class CreateBlackSmithItemFactory : public EquipFactory {
public:
   virtual Vest* makeTorsoArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Vest";
      return new Vest(lvl, randomVal, name);
   }

   virtual BlackSmithJeans* makeLegArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Black Smith Jeans";
      return new BlackSmithJeans(lvl, randomVal, name);
   }

   virtual Hammer* makeWeapon(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Hammer";
      return new Hammer(lvl, randomVal, name);
   }

};

#endif
