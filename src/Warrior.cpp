#include "../header/Warrior.h"

Warrior::Warrior() {
            health = Maxhealth = 100;
            attack = 30;
            defense = 20;
            mana = 50;
            level = 1;
            currentExp = 0;
            maxExp = 100;
        }

void Warrior::gainExp(Enemy* enemy) {
    if (enemy->isDead()) {
        currentExp += enemy->getXP();
        if (currentExp >= maxExp) {
            std::cout << "Level Up!" << endl;
            level++;
            maxHealth += 2;
            health = maxHealth;
            attack += 5;
            defense += 2;
            maxMana += 2;
            mana = maxMana;
            currentExp -= maxExp;
            maxExp += 50;
        }
    }
    delete enemy;
}
