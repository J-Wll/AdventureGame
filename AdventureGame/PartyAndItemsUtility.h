#pragma once

// list of monsters at that location, like 3 per?, dynamic array with monsters being removed/added?
// also a list of items/equipment (objects) 
// monsters and or equip could be randomly generated/selected from a bigger list

// base class for locations and players, both of those classes store a party of monsters and items, this saves a lot of repetition
class PartyAndItemsUtility {
private:
	string name;
public:
	PartyAndItemsUtility(string iname) {
		name = iname;
	}
	string getName() {
		return name;
	}

	// calls the .info method on each monster in a passed in monster list, passes the current index to the info function which is display in the terminal
	void monsterListInfo(vector<Monster> monlist) {
		/*for (Monster mon : monlist) {
			mon.info();
		}*/
		int lSize = monlist.size();
		for (int i = 0; i < lSize; i++) {
			monlist[i].info((to_string(i+1)+". "));
		}
		cout << "\n---\n";
	}
	vector<Monster> monsterSubList(vector<Monster> monsterList);
};

// returns a list of 3 unique monsters from the large monster list
vector<Monster> PartyAndItemsUtility::monsterSubList(vector<Monster> monsterList) {
		srand(time(NULL));
		vector<Monster> returnList = {};
		int listSize = monsterList.size();

		// picks a random monster, checks if it is already in the list, if not it adds to the list
		for (int i = 0; i < 3; i++) {
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
		}
		return returnList;
}
