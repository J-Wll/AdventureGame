#pragma once
#include "PartyAndItemsUtility.h"

// always 3 monsters 1 item, limited lifespan?
class Location : public PartyAndItemsUtility {
private:
	// using the constructor of PartyAndItemsUtility
	using PartyAndItemsUtility::PartyAndItemsUtility;
	//vector<Monster> locationMonsters = {};
public:
	void genMonsters(vector<Monster> monsterList);
	void showMonsters();
};