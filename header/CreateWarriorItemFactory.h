#ifndef __CREATE_WARRIOR_ITEM__
#define __CREATE_WARRIOR_ITEM__

#include "EquipFactory.h"
#include "ChestPlate.h"
#include "WarriorLeggings.h"
#include "Sword.h"

class CreateWarriorItemFactory : public EquipFactory {
public:
   virtual ChestPlate* makeTorsoArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Chestplate";
      return new ChestPlate(lvl, randomVal, name);
   }

   virtual WarriorLeggings* makeLegArmor(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Warrior Leggings";
      return new WarriorLeggings(lvl, randomVal, name);
   }

   virtual Sword* makeWeapon(Player* p)
   {
      FileReader reader("TypeStatus.txt");
      srand(time(NULL));
      int randomVal = (rand() % reader.typeStatus.size()) + 1;
      std::string rarity = reader.typeStatus.at(randomVal - 1);
      int lvl = abs(p->getLevel() - 6 + rand() % 11) + 1;
      std::string name = "Lvl: " + std::to_string(lvl) + " " + rarity + " Sword";
      return new Sword(lvl, randomVal, name);
   }

};

#endif
