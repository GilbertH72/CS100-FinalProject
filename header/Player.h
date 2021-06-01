#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <vector>
#include "Enemy.h"
#include "AttackStrategy.h"
#include "Equips.h"
#include "Heal_Items.h"

enum playerType { WARRIOR, MAGE, BLACKSMITH };

class Player {
protected:
   AttackStrategy* attackStrat;
   std::string name;
   int maxHP;
   int currentHP;
   int atck;
   int defense;
   int level;
   int currentEXP;
   int maxEXP;
   playerType role;
   std::vector<Heal_Items*> usables;
   std::vector<Equips*> inventory;
   Equips* torsoEQ;
   Equips* legEQ;
   Equips* weaponEQ;

public:
   Player()
   {
      this->attackStrat = nullptr;
      this->torsoEQ = nullptr;
      this->legEQ = nullptr;
      this->weaponEQ = nullptr;
      this->name = "";
      this->maxHP = 10;
      this->currentHP = 10;
      this->atck = 5;
      this->defense = 5;
      this->level = 5;
      this->currentEXP = 0;
      this->maxEXP = 100;
   };

   ~Player()
   {
      for (auto u : usables)
      {
         delete u;
      }

      for (auto i : inventory)
      {
         delete i;
      }
   }

   void setattackStrategy(AttackStrategy* attackStrategy)
   {
      this->attackStrat = attackStrategy;
   }

   void setDefense(int def) { this->defense += def; }

   void setAttack(int attack) { this->atck += attack; }

   virtual int attack(Enemy* currentEnemy) = 0;

   virtual void levelUp() = 0;

   int getMaxHP() const { return this->maxHP; }

   int getcurrentHP() const { return this->currentHP; }

   int getAttack() const { return this->atck; }

   int getDefense() const { return this->defense; }

   int getLevel() const { return this->level; }

   int getcurrentEXP() const { return this->currentEXP; }

   int getMaxEXP() const { return this->maxEXP; }

   playerType getcharType() const { return this->role; }

   void setcurrentHP(int additionalHP)
   {
      if (additionalHP + this->currentHP < this->getMaxHP())
      {
         this->currentHP += additionalHP;
      }
      else
      {
         this->currentHP = maxHP;
      }
   }

   void setcurrentHPAttack(int additionalHP) { this->currentHP -= additionalHP; }

   void setcurrentXP(int XP)
   {
      this->currentEXP += XP;
      if (this->currentEXP >= this->maxEXP)
      {
         this->levelUp();
      }
   }

   void addHealItems(Heal_Items* consum) { this->usables.push_back(consum); }

   void removeHealItemsAt(int index)
   {
      if (index < this->equipsSize())
      {
         this->usables.erase(usables.begin() + index);
      }
   }

   int healItemsSize() { return this->usables.size(); }

   Heal_Items* healItemsAt(int index)
   {
      if (this->healItemsSize())
      {
         return this->usables.at(index);
      }
      return nullptr;
   }

   void addEquips(Equips* eq) { this->inventory.push_back(eq); }

   void removeEquipsAt(int index)
   {
      if (index < this->equipsSize())
      {
         inventory.erase(inventory.begin() + index);
      }
   }

   int equipsSize() { return this->inventory.size(); }

   Equips* equipmentAt(int index)
   {
      if (index < this->equipsSize())
      {
         return inventory.at(index);
      }
      return nullptr;
   }

   void setTorsoEQ(Equips* torso) { this->torsoEQ = torso; }

   void setLeggingsEQ(Equips* leg) { this->legEQ = leg;}

   void setWeaponEQ(Equips* weap) { this->weaponEQ = weap; }

   Equips* getTorso() { return this->torsoEQ; }

   Equips* getLeggingsEQ() { return this->legEQ; }

   Equips* getWeaponEQ() { return this->weaponEQ; }

};

#endif
