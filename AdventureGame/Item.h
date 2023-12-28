#pragma once
#include <string>

using namespace std;

// items could buff the whole party, equipment could buff an individual monsterd
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

//class Equipment : public Item {
//
//};