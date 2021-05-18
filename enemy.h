#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
    private:
        string name;
        int health;
        int attack;
        int defense;
    public:
        Enemy(string n, int hp, int atk, int def, int spd) : name(n), health(hp), defense(def), speed(spd) { }

        string getName() { return name; }

        int getHealth() { return health; }

        int getAttack() { return attack; }

        int getDefense() { return defense; }

        void loseHP(CharacterClass* player) { // needs character class
            health = health - ((player->dmg * player->dmg)/(player->dmg + defense)); // damage formula for regular attack against enemy;
        }

        void loseHPSkill(CharacterClass* player) {
            health = health - player->skilldmg; // damage from player skill (not affected by defense);
        }
}

#endif
