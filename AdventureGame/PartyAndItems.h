#pragma once

// list of monsters at that location, like 3 per?, dynamic array with monsters being removed/added?
// also a list of items/equipment (objects) 
// monsters and or equip could be randomly generated/selected from a bigger list

class PartyAndItems {
private:
	string name;
public:
	string getName() {
		return name;
	}
	PartyAndItems(string iname) {
		name = iname;
	}
};



// always 3 monsters 1 item, limited lifespan?
class Location : public PartyAndItems {
private:
	using PartyAndItems::PartyAndItems;
public:

};

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItems {
private:
	using PartyAndItems::PartyAndItems;
	vector<Monster> playerMonsters = {};
public:
	void chooseMonsters(vector<Monster> monsterlist);
	


};

void Player::chooseMonsters(vector<Monster> monsterList) {
	srand(time(NULL));
	int listSize = monsterList.size();

	for (int i = 0; i < 5; i++) {
		int randomInt = rand() % listSize;
		Monster randomMon = monsterList[randomInt];

		if (!playerMonsters.empty()) {
			if (find(playerMonsters.begin(), playerMonsters.end(), randomMon) != playerMonsters.end()) {
				//cout << "DUPLICATE";
				i--;
				continue;
			}
		}
		playerMonsters.push_back(randomMon);

	}

	cout << "Players party: \n";
	for (Monster mon : playerMonsters) {
		mon.info();
	}
	
};

