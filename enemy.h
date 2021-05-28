#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    private:
        std::string name;
        int health;
        int attack;
        int defense;
	int level;
	int giveExp;
    public:
        Enemy(std::string n, int hp, int atk, int def, int lvl, int exp) : name(n), health(hp), attack(atk), defense(def), level(lvl), giveExp(exp) { }

        std::string getName() { return name; }

        int getHealth() { return health; }

        int getAttack() { return attack; }

        int getDefense() { return defense; }

	int getLevel() { return level; }

	int getExp() { return giveExp; }

        void loseHP(CharacterClass player) { // needs character class
            health = health - ((player.getAttack() * player.getAttack())/(player.getAttack() + defense)); // damage formula for regular attack against enemy;
        }

	bool isDead() {
            if (health == 0) {
                return true;
            }
            else {
                return false;
            }
        }
};

#endif
