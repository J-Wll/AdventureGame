//#include <ios>
#include <limits>

#include "Party.h"
#include "Player.h"
#include "UtilityVariables.h"

using namespace std;

void Player::showPlayersParty() {
	cout << greenColour << "\nYour party:" << defaultColour;
	party.monsterPartyInfo();
}

int Player::getTarget(int max) {
	int min = 1;
	int inp;
	cin >> inp;
	if (inp > max || inp < min) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << redColour << "Invalid input, enter again:\n" << defaultColour;
		return getTarget(max);
	}
	return inp;
};


void Player::chooseMonsters(vector<Monster>* monsterListPointer) {
	vector<Monster> finalParty;
	Party tempMonsters;
	cout << "You will be presented with 3 choices, each with 3 options for your party, choose with 1/2/3\n";
	
	for (int i = 0; i < 3; i++) {
		tempMonsters.setParty(party.monsterSubList(monsterListPointer));
		tempMonsters.monsterPartyInfo();
		cout << "Select a monster: ";
		int selected = getTarget(tempMonsters.getParty()->size()) - 1;
		finalParty.push_back(tempMonsters.getParty()->at(selected));
	}

	party.setParty(finalParty);
};

