#include "../header/Warrior.h"
#include "../header/WarriorAttackStrat.h"

Warrior::Warrior(std::string, playerType role)
{
   this->attackStrat = new WarriorAttackStrat();
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

Warrior::~Warrior()
{
   delete attackStrat;
   delete torsoEQ;
   delete legEQ;
   delete weaponEQ;
}

int Warrior::attack(Enemy* currentEnemy)
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

void Warrior::levelUp()
{
   while (currentEXP >= maxEXP)
   {
      std::cout << "You Leveled up! Congrats!" << std::endl;
      this->maxHP += 3;
      this->currentHP += 3;
      this->atck += 5;
      this->defense += 3;
      this->level += 1;
      this->currentEXP -= this->maxEXP;
      this->maxEXP += 25;
   }
}
