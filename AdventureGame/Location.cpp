#pragma once
#include "PartyAndItemsUtility.h"
#include "Location.h"

using namespace std;

void Location::genMonsters(vector<Monster>* monsterListPointer) {
	monsterParty = monsterSubList(monsterListPointer);
}
void Location::showMonsters() {
	cout << "\nThe " << getName() << " Has the following monsters:";
	monsterPartyInfo();
}
