#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"
#include "Warrior.h"
#include "Mage.h"
#include "BlackSmith.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Slime.h"
#include "Spider.h"
#include "Orc.h"
#include "Elixir.h"
#include "File_Reader.h"
#include "EquipFactory.h"
#include "CreateMageItemFactory.h"
#include "CreateBlackSmithItemFactory.h"
#include "CreateWarriorItemFactory.h"
#include <string>
#include <stdlib.h>
#include <ctime>

enum areaType { DESERT, CAVERN, TUNDRA, WOODLAND };

class Game {
private:
	int numberofDays;
	areaType overWorld;
	std::string username = "";
	bool restedUp = false;
	static Game* gameInstance;
	Player* currentCharacter;

	Game()
	{
		numberofDays = 1;
		overWorld = DESERT;
	}

public:
	static Game* getInstance()
	{
		if (gameInstance == nullptr) { gameInstance = new Game(); }
		return gameInstance;
	}

	areaType getCurrentLocation() { return overWorld; }

	void startGame()
	{
		createPlayer();
		while (currentCharacter->getcurrentHP() > 0)
		{
			std::cout << std::string(15, '\n');
			playerOption(printMenu());
		}
	}

	void explore()
	{
		std::cout << std::string(15, '\n');
		std::cout << "\033[1;34m" << username << ", your current location is: ";
		printArea();
		std::cout << "\033[0m";
		int choice = exploreMenu();
		if (choice == 1) { overWorld = DESERT; }
		else if (choice == 2) { overWorld = CAVERN; }
		else if (choice == 3) { overWorld = TUNDRA; }
		else { overWorld = WOODLAND; }

		std::cout << "\033[1;34m" << username << ", your new location is:";
		printArea();
		std::cout << "\033[0m";
	}

	int exploreMenu()
	{
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;32m1) DESERT - chest armor     3) TUNDRA - leg armor\033[0m" << std::endl;
		std::cout << "\033[1;32m2) CAVERN - potions           4) WOODLAND - weapons\033[0m" << std::endl;
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;

		std::cout << "\033[1;36mSelect one of the options by entering 1-4 inputs:\033[0m ";
		int input;
		std::cin >> input;

		if (input < 1 || input > 4) {
			std::cout << "\033[1;31mINVALID INPUT! RE-PROMPTING THE MENU!\033[0m";
			this->exploreMenu();
		}
		return input;
	}

	void printArea()
	{
		if (overWorld == 0) { std::cout << "DESERT" << std::endl; }
		else if (overWorld == 1) { std::cout << "CAVERN" << std::endl; }
		else if (overWorld == 2) { std::cout << "TUNDRA" << std::endl; }
		else { std::cout << "WOODLAND" << std::endl; }
	}

	void fight()
	{
		if (overWorld == DESERT)
		{
			Enemy* newEnemy = new Orc(currentCharacter->getLevel());
			startFight(currentCharacter, newEnemy);
		}
		else if (overWorld == CAVERN)
		{
			Enemy* newEnemy = new Dragon(currentCharacter->getLevel());
			startFight(currentCharacter, newEnemy);
		}
		else if (overWorld == TUNDRA)
		{
			Enemy* newEnemy = new Goblin(currentCharacter->getLevel());
			startFight(currentCharacter, newEnemy);
		}
		else
		{
			Enemy* newEnemy = new Slime(currentCharacter->getLevel());
			startFight(currentCharacter, newEnemy);
		}
	}

	void startFight(Player* currentCharacter, Enemy* newEnemy)
	{
		std::cout << std::string(15, '\n');
		std::cout << "\033[1;35mYou have encountered a level " << newEnemy->getEnemyLevel() << " " << newEnemy->getName() << " with " << newEnemy->getEnemyHP() << "HP !\033[0m" << std::endl;
		int mobMaxHP = newEnemy->getEnemyHP();
		while (currentCharacter->getcurrentHP() > 0)
		{
			std::cout << std::string(5, '\n');
			std::cout << "\033[1;33m" << username << "'s HP: " << currentCharacter->getcurrentHP() << "/" << currentCharacter->getMaxHP() << ", " << newEnemy->getName() << "'s HP: " << newEnemy->getEnemyHP() << "/" << mobMaxHP << "\033[0m" << std::endl;
			int option = fightMenu();
			if (option == 1)
			{
				newEnemy->setEnemyHP(currentCharacter->attack(newEnemy));
				std::cout << std::endl << "\033[1;35m" << username << " attacks the " << newEnemy->getName() << ", dealing " << currentCharacter->attack(newEnemy) << " damage!\033[0m" << std::endl;
				if (newEnemy->getEnemyHP() > 0)
				{
					currentCharacter->setcurrentHPAttack(newEnemy->attackChar(currentCharacter->getDefense()));
					std::cout << "\033[1;35m" << newEnemy->getName() << " attacks " << username << ", dealing " << newEnemy->attackChar(currentCharacter->getDefense()) << " damage!\033[0m" << std::endl;
				}
			}
			else if (option == 2)
			{
				if (currentCharacter->healItemsSize() > 0)
				{
					printHeal_Items();
					int option;
					std::cout << "\033[1;36mSelect one of the options by the Elixir number:\033[0m ";
					std::cin >> option;
					currentCharacter->setcurrentHP(currentCharacter->healItemsAt(option - 1)->getValue());
					currentCharacter->removeHealItemsAt(option - 1);
					currentCharacter->setcurrentHPAttack(newEnemy->attackChar(currentCharacter->getDefense()));
					std::cout << "\033[1;35m" << newEnemy->getName() << " attacks " << username << ", dealing " << newEnemy->attackChar(currentCharacter->getDefense()) << " damage!\033[0m" << std::endl;
				}
				else
				{
					std::cout << "\033[1;31mYou DONT have any consumables!";
				}
			}
			else if (option == 3)
			{
				std::cout << "\033[1;30mYou have decided to flee!\033[0m" << std::endl;
				return;
			}

			if (currentCharacter->getcurrentHP() <= 0)
			{
				std::cout << "\033[1;31mYOUR CHARACTER HAS DIED!\033[0m" << std::endl;
			}
			if (newEnemy->getEnemyHP() <= 0) {
				std::cout << "\033[1;33mYou have killed the " << newEnemy->getName() << " and received some loot!\033[0m" << std::endl;
				std::cout << "\033[1;33m" << username << " gained " << newEnemy->getEnemyEXP() << " XP!\033[0m" << std::endl;
				currentCharacter->setcurrentXP(newEnemy->getEnemyEXP());
				currentCharacter->levelUp();
				giveDrops();
				numberofDays++;
				restedUp = false;
				break;
			}
		}
	}

	void giveDrops()
	{
		if (currentCharacter->getcharType() == MAGE)
		{
			EquipFactory* loot = new CreateMageItemFactory();
			this->lootonLoc(loot, this->getCurrentLocation());
		}
		else if (currentCharacter->getcharType() == BLACKSMITH)
		{
			EquipFactory* loot = new CreateBlackSmithItemFactory();
			this->lootonLoc(loot, this->getCurrentLocation());
		}
		else
		{
			EquipFactory* loot = new CreateWarriorItemFactory();
			this->lootonLoc(loot, this->getCurrentLocation());
		}
	}

	void lootonLoc(EquipFactory* lootage, areaType currentArea)
	{
		if (currentArea == DESERT) { currentCharacter->addEquips(lootage->makeTorsoArmor(currentCharacter)); }
		else if (currentArea == CAVERN) { currentCharacter->addEquips(lootage->makeWeapon(currentCharacter)); }
		else if (currentArea == TUNDRA) { currentCharacter->addEquips(lootage->makeLegArmor(currentCharacter)); }
		else
		{
			FileReader reader("Rarity.txt");
			srand(time(NULL));
			int randomVal = (rand() % reader.typeStatus.size()) + 1;
			std::string rarity = reader.typeStatus.at(randomVal - 1);
			int lvl = abs(currentCharacter->getLevel() - 6 + rand() % 11) + 1;
			currentCharacter->addHealItems(new Elixir(lvl, randomVal, rarity));
		}
	}

	int fightMenu()
	{
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;32m1) ATTACK               3) RUN\033[0m" << std::endl;
		std::cout << "\033[1;32m2) USE HEAL ITEM\033[0m" << std::endl;
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;36mSelect one of the options by entering 1-3 inputs: ";
		int input;
		std::cin >> input;

		if (input < 1 || input > 3) {
			std::cout << "\033[1;31mINVALID INPUT! RE-PROMPTING THE MENU!\033[0m\n";
			this->printMenu();
		}
		return input;
	}

	void printStorage()
	{
		std::cout << std::string(15, '\n');
		if (currentCharacter->equipsSize() > 0) { std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl; }
		else { std::cout << "\033[1;31mEMPTY INVENTORY!" << std::endl; }
		for (unsigned int i = 0; i < currentCharacter->equipsSize(); i++)
		{
			std::cout << "\033[1;33mITEM #" << i + 1 << "\033[0m" << std::endl;
			std::cout << "\033[1;33mNAME - " << currentCharacter->equipmentAt(i)->getName() << "\033[0m" << std::endl;
			if (currentCharacter->equipmentAt(i)->setToArmor())
			{
				std::cout << "\033[1;33mARMOR VALUE - " << currentCharacter->equipmentAt(i)->getValue() << "\033[0m" << std::endl;
			}
			else { std::cout << "\033[1;33mWEAPON DMG - " << currentCharacter->equipmentAt(i)->getValue() << "\033[0m" << std::endl; }
			std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		}
	}
	void printHeal_Items()
	{
		std::cout << std::string(15, '\n');
		if (currentCharacter->healItemsSize() > 0) { std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl; }
		else { std::cout << "\033[1;31EMPTY CONSUMABLES!" << std::endl; }
		for (unsigned int i = 0; i < currentCharacter->healItemsSize(); i++)
		{
			std::cout << "\033[1;35mPOTION #" << i + 1 << "\033[0m" << std::endl;
			std::cout << "\033[1;35mNAME - " << currentCharacter->healItemsAt(i)->getName() << " Potion\033[0m" << std::endl;
			std::cout << "\033[1;35mHEAL VALUE - " << currentCharacter->healItemsAt(i)->getValue() << "\033[0m" << std::endl;
			std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		}
	}
	void useStorage()
	{
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;32m1) EQUIPMENT             3) CONSUMABLES\033[0m" << std::endl;
		std::cout << "\033[1;32m2) CHANGE EQUIPMENT      4) CURRENT EQUIPMENT\033[0m" << std::endl;
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;

		std::cout << "\033[1;36mSelect one of the options by entering 1-2 inputs:\033[0m ";
		int input;
		std::cin >> input;

		if (input == 1) { printStorage(); }
		else if (input == 2) { changeEquips(); }
		else if (input == 3) { printHeal_Items(); }
		else if (input == 4) { printCurrentEquips(); }
		else {
			std::cout << "\033[1;31mINVALID INPUT! RE-PROMPTING THE MENU!\033[0m";
			this->useStorage();
		}
	}

	void changeEquips()
	{

	}

	void printCurrentEquips()
	{
		if (currentCharacter->getTorso() != nullptr)
		{
			std::cout << "\033[1;36m" << currentCharacter->getTorso()->getName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33mARMOR - " << currentCharacter->getTorso()->getValue() << "\033[0m" << std::endl;
		}
		else
		{
			std::cout << "\033[1;31mYou DONT have a chestplate equipped!\033[0m" << std::endl;
		}
		if (currentCharacter->getLeggingsEQ() != nullptr)
		{
			std::cout << "\033[1;36m" << currentCharacter->getLeggingsEQ()->getName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33mARMOR - " << currentCharacter->getLeggingsEQ()->getValue() << "\033[0m" << std::endl;
		}
		else
		{
			std::cout << "\033[1;31mYou DO NOT have Leggings equipped!\033[0m" << std::endl;
		}
		if (currentCharacter->getWeaponEQ() != nullptr)
		{
			std::cout << "\033[1;36m" << currentCharacter->getWeaponEQ()->getName() << "\033[0m" << std::endl;
			std::cout << "\033[1;33mDMG - " << currentCharacter->getWeaponEQ()->getValue() << "\033[0m" << std::endl;
		}
		else { std::cout << "\033[1;31mYou DO NOT have a Weapon equipped!\033[0m" << std::endl; }
	}

	void heal()
	{
		if (currentCharacter->getcurrentHP() < currentCharacter->getMaxHP())
		{
			currentCharacter->setcurrentHP((currentCharacter->getMaxHP() * 3) / 10);
			std::cout << "\033[1;34m" << username << ", your current HP is now at: " << currentCharacter->getcurrentHP() << "/" << currentCharacter->getMaxHP() << "\033[0m" << std::endl;
			return;
		}
		std::cout << "\033[1;31m" << username << ", you are already at MAX HP: " << currentCharacter->getcurrentHP() << "/" << currentCharacter->getMaxHP() << "\033[0m" << std::endl;
	}

	void createPlayer()
	{
		std::cout << "\033[1;36mWelcome to Eternia! What should we call you?:\033[0m";
		std::string name;
		getline(std::cin, name);
		username = name;
		std::cout << "\033[1;36m" << name << ", here is a list of the three characters to play as." << "\033[0m" << std::endl;
		std::cout << "\033[1;30m-------------------------------------------------------------------------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;33m1) BLACKSMITH - The Blacksmith derives from poor beginnings. As he grew up, he refined weaponry to provide for his family. After\nmonsters plagued the earth and ravaged his village, he promised to avenge his family. The BlackSmith focuses in defense.\033[0m\n" << std::endl;
		std::cout << "\033[1;33m2) MAGE - The Mage has mystic origins, coming from an unknown dimension. Seeking to hone his skills, he travels\nthe land, refining his wicked sorcery. The mage is a bit all-around.\033[0m\n" << std::endl;
		std::cout << "\033[1;33m3) WARRIOR - The Warrior fell from royalty after being betrayed by their Father. Now left with nowhere to go, the Warrior\nstruggles to survive in the wilderness. The Warrior focuses in attack.\033[0m\n";
		std::cout << "\033[1;30m-------------------------------------------------------------------------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;36mEnter the corresponding number of the character you want to play as: \033[0m";

		int charNum;
		std::cin >> charNum;

		if (charNum < 1 || charNum > 3)
		{
			std::cout << "\033[1;31mRestarting character selection due to invalid input\033[0m" << std::endl;
			std::cin.ignore();
			this->createPlayer();
		}
		else if (charNum == 1)
		{
			std::cout << "\033[1;35mYou've chosen the BLACKSMITH Character!\033[0m" << std::endl;
			currentCharacter = new BlackSmith(name, BLACKSMITH);
		}
		else if (charNum == 2)
		{
			std::cout << "\033[1;35mYou've chosen the MAGE Character!\033[0m" << std::endl;
			currentCharacter = new Mage(name, MAGE);
		}
		else
		{
			std::cout << "\033[1;35mYou've chosen the WARRRIOR Character!\033[0m" << std::endl;
			currentCharacter = new Warrior(name, WARRIOR);
		}
	}

	int printMenu()
	{
		std::cout << "\033[1;36mDays Counter: " << numberofDays << "\033[0m" << std::endl;
		std::cout << "\033[1;33m" << username << "'s LVL: " << currentCharacter->getLevel() << ", HP: " << currentCharacter->getcurrentHP() << "/" << currentCharacter->getMaxHP() << ", XP: " << currentCharacter->getcurrentEXP() << "/" << currentCharacter->getMaxEXP() << "\033[0m" << std::endl;
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;
		std::cout << "\033[1;32m1) FIGHT               3) ACCESS INVENTORY\033[0m" << std::endl;
		std::cout << "\033[1;32m2) EXPLORE             4) REST\033[0m" << std::endl;
		std::cout << "\033[1;30m--------------------------------------------------\033[0m" << std::endl;

		std::cout << "\033[1;36mSelect one of the options by entering 1-4 inputs:\033[0m ";
		int input;
		std::cin >> input;

		if (input < 1 || input > 4)
		{
			std::cout << "\033[1;31mINVALID INPUT! RE-PROMPTING THE MENU!\033[0m" << std::endl;
			this->printMenu();
		}
		return input;
	}

	void playerOption(int option)
	{
		if (option == 1) { fight(); }
		else if (option == 2) { explore(); }
		else if (option == 3) { useStorage(); }
		else
		{
			if (!restedUp)
			{
				heal();
				if (currentCharacter->getLevel() >= 15)
				{
					restedUp = true;
				}
			}
			else
			{
				std::cout << "\033[1;31mYOU HAVE ALREADY RESTED TODAY!\033[0m" << std::endl;
			}
		}
	}

	void printStats()
	{
		if (currentCharacter->getLeggingsEQ() != nullptr || currentCharacter->getTorso() != nullptr)
		{
			std::cout << "\033[1;35mCURRENT DEFENSE - " << currentCharacter->getDefense() << "\033[0m" << std::endl;
		}
		if (currentCharacter->getWeaponEQ() != nullptr)
		{
			std::cout << "\033[1;35mCURRENT ATTACK - " << currentCharacter->getAttack() << "\033[0m" << std::endl;
		}
	}
};

#endif
