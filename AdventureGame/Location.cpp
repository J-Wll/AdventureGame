
#include "PartyAndItemsUtility.h"
#include "Location.h"

void genMonsters(vector<Monster> monsterList) {
	Location::monsterParty = Location::monsterSubList(monsterList);
}