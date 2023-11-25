#pragma once

// list of monsters at that location, like 3 per?, dynamic array with monsters being removed/added?
// also a list of items/equipment (objects) 
// monsters and or equip could be randomly generated/selected from a bigger list


class PartyAndItems {
private:
	string name;
public:
	PartyAndItems(string iname) {
		name = iname;
	}
	string getName() {
		return name;
	}
	void monsterListInfo(vector<Monster> Monlist) {
		for (Monster mon : Monlist) {
			mon.info();
		}
	}
	vector<Monster> monsterSubList(vector<Monster> monsterList);
};

vector<Monster> PartyAndItems::monsterSubList(vector<Monster> monsterList) {
		srand(time(NULL));
		vector<Monster> returnList = {};
		int listSize = monsterList.size();

		// picks a random monster, checks if it is already in the list, if not it adds to the list
		for (int i = 0; i < 3; i++) {
			int randomInt = rand() % listSize;
			Monster randomMon = monsterList[randomInt];

			if (!returnList.empty()) {
				if (find(returnList.begin(), returnList.end(), randomMon) != returnList.end()) {
					//cout << "DUPLICATE";
					i--;
					continue;
				}
			}
			returnList.push_back(randomMon);

		}
		return returnList;
}



// always 3 monsters 1 item, limited lifespan?
class Location : public PartyAndItems {
private:
	using PartyAndItems::PartyAndItems;
	vector<Monster> locationMonsters = {};
public:
	void genMonsters(vector<Monster> monsterList){
		locationMonsters = monsterSubList(monsterList);
	}
	void showMonsters() {
		cout << "The " << getName() << " Has the following monsters:\n";
		monsterListInfo(locationMonsters);
	}
};

// 3 monsters, up to 9 items, lasts the whole game
class Player : public PartyAndItems {
private:
	using PartyAndItems::PartyAndItems;
	vector<Monster> playerMonsters = {};
public:
	void chooseMonsters(vector<Monster> monsterlist);
	void showPlayersParty() {
		cout << "Players party: \n";
		monsterListInfo(playerMonsters);
	}
};

void Player::chooseMonsters(vector<Monster> monsterList) {
	playerMonsters = monsterSubList(monsterList);
};

