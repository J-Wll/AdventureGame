#pragma once
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <algorithm>
#include <string>

#include "Party.h";
#include "Monster.h";
using namespace std;

vector<Monster> monsterParty = {};

void Party::setParty(vector<Monster> iParty) {
	monsterParty = iParty;
}

vector<Monster>* Party::getParty() {
	vector<Monster>* monsterPartyPtr = &monsterParty;
	return monsterPartyPtr;
}

// calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
void Party::monsterPartyInfo() {
	int lSize = monsterParty.size();
	for (int i = 0; i < lSize; i++) {
		monsterParty[i].info((to_string(i + 1) + ". "));
	}
	cout << "\n---\n";
}

// returns a list of 3 unique monsters from the large monster list
vector<Monster> Party::monsterSubList(vector<Monster>* monsterListPointer) {
	vector<Monster> monsterList = *monsterListPointer;
	vector<Monster> returnList = {};
	vector<int> toBeRemoved = {};
	int listSize = monsterList.size() - 1;
	int SUBLISTSIZE = 3;

	// picks a random monster, checks if it is already in the list, if not it adds to the list
	for (int i = 0; i < SUBLISTSIZE; ++i) {
		// rand is seeded in main to prevent error
		int randomInt = rand() % listSize;
		Monster randomMon = monsterList[randomInt];

		// if the return list is not empty, use the find function to determine if the monster is already in the list, if it is, start the loop again
		if (!returnList.empty()) {
			if (find(returnList.begin(), returnList.end(), randomMon) != returnList.end()) {
				i--;
				continue;
			}
		}
		returnList.push_back(randomMon);
		toBeRemoved.push_back(randomInt);
	}

	// sorts to be removed from highest to lowest (otherwise index could be out of bounds)
	// removes the indexed value from using the monsterlistpointer, disabling the ability for future lists to have duplicates
	sort(toBeRemoved.begin(), toBeRemoved.end(), greater<int>());
	for (int num : toBeRemoved) {
		monsterListPointer->erase(monsterListPointer->begin() + num);
	}
	return returnList;
}
