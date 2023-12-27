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
	cout << "\n---You proceed to The " << name << "---\n\n";
}

void Location::fail() {
	cout << "\n---You have been defeated by The " << name << "---\n\n";
}

void Location::finish() {
	cout << "\n---You have vanquished the foes of The " << name << "---\n\n";
}