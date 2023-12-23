#include "Item.h"

using namespace std;

string Item::getName() {
	return name;
}

Item::Item(string iName, string iType, int iItemHp, int iItemAtk, int iItemDef) {
	name = iName;
	type = iType;
	itemHp = iItemHp;
	itemAtk = iItemAtk;
	itemDef = iItemDef;
}