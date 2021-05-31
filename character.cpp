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
    healthItemNumber--;
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

int Player::getAttack(Enemy* e, int rand) {
    int atk = attack + rand; 
    return ((atk * atk) / (atk + e.getDefense())); 
}

void Player::loseHP(Enemy* e, int rand) {
    int atk = e->getAttack() + rand;
    health -= ((atk * atk)/(atk + defense);
}
