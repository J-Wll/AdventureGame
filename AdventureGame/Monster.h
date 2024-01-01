#pragma once

#include <vector>
#include <iostream>
#include "Item.h"

using namespace std;

class Monster
	{
	private:
		// Name, type and stats of monster, stats have a maximum of 100 (before equipment)
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

