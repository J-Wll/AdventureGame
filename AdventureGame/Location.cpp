#pragma once
#include "PartyAndItemsUtility.h"
#include "Location.h"

using namespace std;

void Location::genMonsters(vector<Monster> monsterList) {
	monsterParty = monsterSubList(monsterList);
}
void Location::showMonsters() {
	cout << "\nThe " << getName() << " Has the following monsters:";
	monsterPartyInfo();
}
