#pragma once

#include <vector>
#include <iostream>

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
		int hp;
		int atk;
		int def;
		// name of equipment(If any), later this will be passed an equipment pointer that effects stats
		string equipped = "None";

	public:
		Monster(string iname, string itype, int ihp=50, int iatk=50, int idef=50);
		void info(string opt);

		void setName(string in);
		string getName();

		void setType(string in);
		string getType();

		void setEquipment();

		// later this will ask for and get the move from a move list dependant on type
		int getAttack();
		int getHp();

		int takeDamage(int attackValue);
		// comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
		bool operator==(const Monster& compare);
	};

