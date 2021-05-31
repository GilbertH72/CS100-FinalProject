#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>

#include "enemy.h"


    class Player
    {   
    protected:
        std::string name;
        int Class;
        int health;
        int maxHealth;
        int defense;
        int attack;
        int mana;
        int maxMana;
        int level;
        int currentExp;
        int maxExp;
        int healthItemNumber;
        vector<Equips> equipment;


    public:
        Player();
        ~Player();
        void setPlayerName();
        void displayStats();
        void storeHealthItem();
        void useHealthItem(Health_Item item);
        void storeEquipment(Equips equip);
        void CheckInventory();
        virtual void gainExp() = 0;
        void getAttack(Enemy* e, int rand);
        void loseHP(Enemy* e, int rand);

    };

#endif
