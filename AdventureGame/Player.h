#pragma once

#include "PartyAndItemsUtility.h"
#include "Location.h"

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItemsUtility {
private:
	// using the constructor of PartyAndItemsUtility
	using PartyAndItemsUtility::PartyAndItemsUtility;

public:
	void chooseMonsters(vector<Monster>* monsterListPointer);
	void showPlayersParty();
	int getTarget(int max = 3);
};
