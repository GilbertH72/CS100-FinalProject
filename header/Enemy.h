#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <string>
#include <cstdlib>
#include <ctime>

class Enemy {
protected:
   std::string name;
   int health;
   int attack;
   int defense;
   int level;
   int givenEXP;

public:
   Enemy()
   {
      this->name = "Enemy";
      this->health = 10;
      this->attack = 5;
      this->defense = 5;
      this->level = 1;
      this->givenEXP = 25;
   }

   Enemy(int charLevel)
   {
      this->health = charLevel + 10;
      this->attack = charLevel + 5;
      this->defense = charLevel + 5;
      this->level = charLevel;
      this->givenEXP = this->level * 10 * this->attack / this->defense;
   }

   // Getters for Enemy
   int getEnemyHP() { return this->health; }
   int getEnemyAttack() { return this->attack; }
   int getEnemyDefense() { return this->defense; }
   int getEnemyLevel() { return this->level; }
   int getEnemyEXP() { return this->givenEXP; }
   std::string getName() { return this->name; }

   // Setter for EnemyHP
   void setEnemyHP(int value) { this->health -= value; }

   // Damage formula for enemy attacking character
   virtual int attackChar(int charDefense) = 0;
};

#endif
