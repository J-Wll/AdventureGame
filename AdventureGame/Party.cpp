#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <string>

#include "Party.h"
#include "Monster.h"
 
using namespace std;

vector<Monster> monsterParty = {};

void Party::setParty(vector<Monster> iParty) {
	monsterParty = iParty;
}

vector<Monster>* Party::getParty() {
	vector<Monster>* monsterPartyPtr = &monsterParty;
	return monsterPartyPtr;
}

// Calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
void Party::monsterPartyInfo() {
	for (int i = 0; i < monsterParty.size(); i++) {
		monsterParty[i].info((to_string(i + 1) + ". "));
	}
	cout << "\n---\n";
}

void Party::partyDecreaseCooldown() {
	for (int i = 0; i < monsterParty.size(); i++) {
		monsterParty[i].decreaseCooldown();
	}
}

bool Party::availableMonsters() {
	bool available = false;
	for (Monster mon : monsterParty) {
		if (mon.getCooldown() == 0) {
			available = true;
		}
	}
	return available;
}

// Returns a list of 3 unique monsters from the large monster list
vector<Monster> Party::monsterSubList(vector<Monster>* monsterListPointer) {
	vector<Monster> monsterList = *monsterListPointer;
	vector<Monster> returnList = {};
	vector<int> toBeRemoved = {};
	int listSize = monsterList.size() - 1;
	int SUBLISTSIZE = 3;

	// Picks a random monster, checks if it is already in the list, if not it adds to the list
	for (int i = 0; i < SUBLISTSIZE; ++i) {
		// Rand is seeded in main to prevent error
		int randomInt = rand() % listSize;
		Monster randomMon = monsterList[randomInt];

		// If the return list is not empty, use the find function to determine if the monster is already in the list, if it is, start the loop again
		if (!returnList.empty()) {
			if (find(returnList.begin(), returnList.end(), randomMon) != returnList.end()) {
				i--;
				continue;
			}
		}
		returnList.push_back(randomMon);
		toBeRemoved.push_back(randomInt);
	}

	// Sorts to be removed from highest to lowest (otherwise index could be out of bounds)
	// Removes the indexed value from using the monsterlistpointer, disabling the ability for future lists to have duplicates
	sort(toBeRemoved.begin(), toBeRemoved.end(), greater<int>());
	for (int num : toBeRemoved) {
		monsterListPointer->erase(monsterListPointer->begin() + num);
	}
	return returnList;
}
