#pragma once
#include <string>

using namespace std;

// items could buff the whole party, equipment could buff an individual monsterd
class Item {
private:

public:
	string name;
	string rarity;
	int itemHp = 0;
	int itemAtk = 0;
	int itemDef = 0;
	string getName();
	Item(string iName, string iRarity, int iItemHp, int iItemAtk, int iItemDef);
};

//class Equipment : public Item {
//
//};