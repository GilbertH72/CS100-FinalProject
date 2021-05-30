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
        Enemy() { }

        std::string getName() { return name; }

        int getHealth() { return health; }

        int getAttack() { return attack; }

        int getDefense() { return defense; }

	int getLevel() { return level; }

	int getExp() { return giveExp; }

        void loseHP(Player player) { // needs character class
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

class Slime : public Enemy {
    public:
        Slime() {
            name = "Slime";
            health = 10;
            attack = 5;
            defense = 5;
        }
};

class Bat : public Enemy {
    public:
        Bat() {
            name = "Bat";
            health = 15;
            attack = 5;
            defense = 5;
        }
};

class Goblin : public Enemy {
    public:
        Goblin() {
            name = "Goblin";
            health = 20;
            attack = 5;
            defense = 5;
        }
}

class Spider : public Enemy {
    public:
        Spider() {
            name = "Spider";
            health = 20;
            attack = 10;
            defense = 5;
        }
};

class Zombie : public Enemy {
    public:
        Zombie() {
            name = "Zombie";
            health = 30;
            attack = 10;
            defense = 20;
        }
};

class Skeleton : public Enemy {
    public:
        Skeleton() {
            name = "Skeleton";
            health = 30;
            attack = 20;
            defense = 10;
        }
};

class Troll : public Enemy {
    public:
        Troll() {
            name = "Troll";
            health = 50;
            attack = 25;
            defense = 25;
        }
};

class Orc : public Enemy {
    public:
        Orc() {
            name = "Orc";
            health = 100;
            attack = 30;
            defense = 30;
        }
};

class Dragon : public Enemy {
    public:
        Dragon() {
            name = "Dragon";
            health = 150;
            attack = 50;
            defense = 50;
        }
};

#endif
