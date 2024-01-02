#pragma once

#include <vector>
#include <iostream>

#include "Item.h"

// Monsters used for combat
class Monster
	{
	private:
		// Name, type and stats of monster
		std::string name;
		std::string type;
		int maxHp;
		int hp;
		int atk;
		int def;
		std::string equipped = "None";
		int itemCount = 0;
		int cooldown = 0;

	public:
		Monster(std::string iname, std::string itype, int iMaxHp=50, int iatk=50, int idef=50);
		void info(std::string opt);
		bool attack(Monster* attacking, bool playerAttack = false);
		void resetHealth();
		void decreaseCooldown();
		int takeDamage(int attackValue);
		void setEquipment(Item item);
		std::string getType();
		std::string getName();
		int getCooldown();
		int getAttack();
		int getHp();

		// Comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
		bool operator==(const Monster& compare);
	};

