#include "../header/Mage.h"
#include "../header/MageAttackStrat.h"

Mage::Mage(std::string, playerType role)
{
   this->attackStrat = new MageAttackStrat();
   this->torsoEQ = nullptr;
   this->legEQ = nullptr;
   this->weaponEQ = nullptr;
   this->name = name;
   this->role = role;
   this->maxHP = 10;
   this->currentHP = 10;
   this->atck = 5;
   this->defense = 5;
   this->level = 1;
   this->currentEXP = 0;
   this->maxEXP = 100;
}

Mage::~Mage()
{
   delete attackStrat;
   delete torsoEQ;
   delete legEQ;
   delete weaponEQ;
}


int Mage::attack(Enemy* currentEnemy)
{
   try
   {
      if (this->attackStrat == nullptr) { throw std::invalid_argument("Nullptr detected"); }
      else { return this->attackStrat->attackEnemy(this, currentEnemy); }
   }
   catch (std::invalid_argument error)
   {
      std::cerr << error.what() << std::endl;
      return -1;
   }
}

void Mage::levelUp()
{
   while (currentEXP >= maxEXP)
   {
      std::cout << "You Leveled up! Congrats!" << std::endl;
      this->maxHP += 3;
      this->currentHP += 3;
      this->atck += 3;
      this->defense += 3;
      this->level += 1;
      this->currentEXP -= this->maxEXP;
      this->maxEXP += 25;
   }
}

