#include "Item.h"

using namespace std;

string Item::getName() {
	return name;
}

Item::Item(string iName, string iRarity, int iItemHp, int iItemAtk, int iItemDef) {
	name = iName;
	rarity = iRarity;
	itemHp = iItemHp;
	itemAtk = iItemAtk;
	itemDef = iItemDef;
}