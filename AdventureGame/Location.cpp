#pragma once

#include "Party.h"
#include "Location.h"

using namespace std;

Location::Location(string iname) {
	name = iname;
}

string Location::getName() {
	return name;
}

void Location::genMonsters(vector<Monster>* monsterListPointer) {
	party.setParty(party.monsterSubList(monsterListPointer));
}

void Location::showMonsters() {
	cout << "\nThe " << getName() << " Has the following monsters:";
	party.monsterPartyInfo();
}

void Location::enter() {
	cout << "\n---You have entered The " << name << "---\n\n";
}