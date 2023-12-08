#pragma once

#include <vector>
#include <iostream>


using namespace std;

//#ifndef LOCATION_H
//#define LOCATION_H
//#endif

// pre-declaration to allow attack to receive location
// doesn't work because overrides it, even if same memory address
//class PartyAndItemsUtility;
//class Location;

//#include "Location.h";

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
		Monster(string iname, string itype, int ihp, int iatk, int idef);
		void info(string opt);

		void setName(string in) { name = in; };
		string getName() { return name; };

		void setType(string in) { type = in; };
		string getType() { return type; };

		void setEquipment() {}

		//void attack(Location* currentLocation) {
		//	currentLocation->monsterPartyInfo();
		//}

		//void attack();

		// later this will ask for and get the move from a move list dependant on type
		int getAttack() {
			int randomDmg = rand() % atk/5;
			return atk+randomDmg;
		}

		//void attack(Location* currentLocation) {
		//	cout << currentLocation <<"\n";
		//	//currentLocation->monsterPartyInfo();

		//	//currentLocation->getName();
		//	//for (Monster mon : currentLocation->monsterParty) {
		//	//	mon.takeDamage(atk);
		//	//}
		//};

		int takeDamage(int attackValue) {
			int damageTaken = (attackValue * def / 100);
			hp -= damageTaken;
			if (hp < 0) {
				cout << "\n" << name << " has died\n";
			}
			return damageTaken;
		}
		// comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
		bool operator==(const Monster& compare) {
			return (name == compare.name);
		}
	};

	Monster::Monster(string iname, string itype, int ihp = 50, int iatk = 50, int idef = 50) {
		name = iname;
		type = itype;
		hp = ihp;
		atk = iatk;
		def = idef;
	}

	void Monster::info(string opt = "") {
		cout << "\n---\n" << opt << "Monsters name: " << name << "\nType: " << type << "\nStats: HP: " << hp << " ATK: " << atk << " DEF: " << def << "\n" << "Equipped: " << equipped;
	}