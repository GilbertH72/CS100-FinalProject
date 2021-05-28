#include "player.hpp"

void Player::setPlayerName() {
    std::cout << "What is your name?" << std::endl;
    std::cin >> name;
    std::cout << "Your name is " << name << "." << std::endl;
}

void Player::displayStats() {
    std::cout << "Level: " << level << std::endl;
    std::cout << "Health: " << health << "/" << maxHealth << std::endl;
    std::cout << "Attack: " << attack << std::endl;
    std::cout << "Defense: " << defense << std::endl;
    std::cout << "Mana " << mana << std::endl;
}

void Player::storeHealthItem() {
    healthItemNumber++;
}

void Player::useHealthItem(Health_Item item) {
    if ((item.getValue() + health) <= maxHealth) {
        health += item.getValue();
    }
    else {
        health = maxHealth;
    }
}

void Player::storeEquipment(Equips equip) {
    equipment.push_back(equip);
}

void Player::checkInventory() { 
    std::cout << "Inventory:" << std::endl;
    for (int i = 0; i < equipment.size(); i++) {
        std::cout << equipment[i] << std::endl;
    }
    std::cout << healthItemNumber << "potions" << std::endl;
}

void Player::getAttack() { return attack; }

void Player::loseHP(Enemy enemy) {
    health -= ((enemy.getAttack() * enemy.getAttack())/(enemy.getAttack() + defense);
}
