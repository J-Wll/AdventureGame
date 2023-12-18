#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>

#include "Monster.h";
using namespace std;

// list of monsters at that location, like 3 per?, dynamic array with monsters being removed/added?
// also a list of items/equipment (objects) 
// monsters and or equip could be randomly generated/selected from a bigger list

// base class for locations and players, both of those classes store a party of monsters and items, this saves a lot of repetition
class PartyAndItemsUtility {
private:
	string name;
public:
	vector<Monster> monsterParty = {};
	PartyAndItemsUtility(string iname);
	string getName();
	vector<Monster>* getMonsters();
	// calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
	void monsterPartyInfo();
	vector<Monster> monsterSubList(vector<Monster>* monsterListPointer);
};
