#ifndef __EQUIPFACTORY_H__
#define __EQUIPFACTORY_H__

#include "Equips.h"
#include "Weapon.h"
#include "Armor.h"
#include "Player.h"
#include "Mage.h"
#include "BlackSmith.h"
#include "Warrior.h"
#include "File_Reader.h"
#include <cstdlib>
#include <ctime>

class EquipFactory {
public:
   virtual Armor* makeTorsoArmor(Player* p) = 0;
   virtual Armor* makeLegArmor(Player* p) = 0;
   virtual Weapon* makeWeapon(Player* p) = 0;
};

#endif
