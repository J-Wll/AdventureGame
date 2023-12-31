#include <iostream>
#include "AttackCycle.h"
#include "Location.h"
#include "Player.h"
#include "UtilityVariables.h"

// takes a location, iterates over the monsters at the location for combat
// after combat, takes the item from that location

int deathCheck(Monster* checking, vector<Monster>* partyPtr, int target, bool player = false) {
	if (checking->getHp() <= 0) {
		string extraText = player ? "Your " : "Enemy ";
		string colour = player ? redColour : greenColour;
		cout << "\n" << colour << extraText << checking->getName() << " has died\n" << defaultColour;
		partyPtr->erase(partyPtr->begin() + target);
	}
	if (partyPtr->size() == 0) {
		if (player) {
			cout << "Defeated";
			return 1;
		}
		else {
			cout << "Victorious";
			return 2;
		}
	}
	return 0;
}

bool attackCycle(Player* player, Location* currentLocation) {
	while (true) {
		Monster* mon;
		Monster* target;
		int monNum;
		int targetNum;
		int playerStatus;
		int locationStatus;
		bool attackHappened;
		vector<Monster>* playerPartyPtr = player->party.getParty();
		vector<Monster>* locationPartyPtr = currentLocation->party.getParty();

		// Player attack
		if (player->party.availableMonsters()) {
			while (true) {
				//Inputs for attack
				cout << "Which of your monsters should attack?, (Enter a whole number): ";
				monNum = player->getTarget(playerPartyPtr->size()) - 1;
				cout << "Choose an enemy to target, (Enter a whole number): ";
				targetNum = player->getTarget(locationPartyPtr->size()) - 1;

				//Getting the monster and what it is targeting
				mon = &playerPartyPtr->at(monNum);
				target = &locationPartyPtr->at(targetNum);

				//Attack and message
				attackHappened = mon->attack(target, true);
				if (attackHappened) {
					break;
				}
			}

		

		//Check for death, remove from party and print message on death
		playerStatus = deathCheck(mon, playerPartyPtr, monNum, true);
		locationStatus = deathCheck(target, locationPartyPtr, targetNum);

		if (playerStatus == 1) {
			return true;
		}
		if (locationStatus == 2) {
			return false;
		}
		}
		// If no monsters to attack
		else {
			cout << "\n---You have no monsters that can attack! Turn skipped---\n\n";
		}

		//Location attack
		if (currentLocation->party.availableMonsters()) {

		
		while (true) {
			monNum = rand() % locationPartyPtr->size();
			targetNum = rand() % playerPartyPtr->size();

			mon = &locationPartyPtr->at(monNum);
			target = &playerPartyPtr->at(targetNum);
			attackHappened = mon->attack(target);
			if (attackHappened) {
				break;
			}
		}

		playerStatus = deathCheck(target, playerPartyPtr, targetNum, true);
		locationStatus = deathCheck(mon, locationPartyPtr, monNum);

		if (playerStatus == 1) {
			return true;
		}
		if (locationStatus == 2) {
			return false;
		}
		}
		else {
			cout << "\n---There are no enemy monsters that can attack! Turn skipped---\n";
		}

		player->party.partyDecreaseCooldown();
		currentLocation->party.partyDecreaseCooldown();


		//Display updated parties
		player->showPlayersParty();
		currentLocation->showMonsters();
	}

	currentLocation->party.monsterPartyInfo();
}

