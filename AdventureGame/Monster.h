#pragma once

#include <vector>
#include <iostream>

#include "Item.h"

class Monster
	{
	private:
		// Name, type and stats of monster, stats have a maximum of 100 (before equipment)
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
		void setName(std::string in);
		std::string getName();
		void setType(std::string in);
		std::string getType();
		void setEquipment(Item item);
		bool attack(Monster* attacking, bool playerAttack = false);
		void resetHealth();
		int getAttack();
		int getHp();
		void decreaseCooldown();
		int getCooldown();
		int takeDamage(int attackValue);

		// Comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
		bool operator==(const Monster& compare);
	};

