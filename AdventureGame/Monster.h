#pragma once

#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

// monster class used for player and enemies, has type, attack, def, speed
// moves based on type?
// player picks their party at the start?
// party size of 3?
// class for attacks with sub classes for each attack?

class Monster
	{
	private:
		// name, type and stats of monster, stats have a maximum of 100 (before equipment)
		string name;
		string type;
		int maxHp;
		int hp;
		int atk;
		int def;
		string equipped = "None";
		int itemCount = 0;
		int cooldown = 0;

	public:
		Monster(string iname, string itype, int iMaxHp=50, int iatk=50, int idef=50);
		void info(string opt);
		void setName(string in);
		string getName();
		void setType(string in);
		string getType();
		void setEquipment(Item* item);
		bool attack(Monster* attacking);
		void resetHealth();
		int getAttack();
		int getHp();
		void decreaseCooldown();
		int takeDamage(int attackValue);

		// comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
		bool operator==(const Monster& compare);
	};

