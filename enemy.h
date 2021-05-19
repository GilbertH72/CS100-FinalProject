#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    private:
        std::string name;
        int health;
        int attack;
        int defense;
	int giveExp;
    public:
        Enemy(std::string n, int hp, int atk, int def, int spd, int exp) : name(n), health(hp), defense(def), speed(spd), giveExp(exp) { }

        std::string getName() { return name; }

        int getHealth() { return health; }

        int getAttack() { return attack; }

        int getDefense() { return defense; }

	int getExp() { return giveExp; }

        void loseHP(CharacterClass* player) { // needs character class
            health = health - ((player->dmg * player->dmg)/(player->dmg + defense)); // damage formula for regular attack against enemy;
        }
};

#endif