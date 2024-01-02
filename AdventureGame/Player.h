#pragma once

#include "Party.h"

class Player {
public:
	Party party;
	void chooseMonsters(std::vector<Monster>* monsterListPointer);
	void showPlayersParty();
	int getTarget(int max = 3);
};
