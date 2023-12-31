#pragma once
#include <string>

using namespace std;

// items buff an individual monster and are equipped through methods inside the Monster class
class Item {
private:
public:
	string name;
	string rarity;
	int itemHp;
	int itemAtk;
	int itemDef;
	string getName();
	Item(string iName, string iRarity, int iItemHp, int iItemAtk, int iItemDef);
	void info();
};
