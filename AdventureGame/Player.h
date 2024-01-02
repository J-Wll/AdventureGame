#pragma once

#include "Party.h"

// Methods for the player and the players party
class Player {
public:
	Party party;
	void chooseMonsters(std::vector<Monster>* monsterListPointer);
	void showPlayersParty();
	int getTarget(int max = 3);
};
