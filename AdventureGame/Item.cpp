#include "Item.h"
#include <iostream>

using namespace std;

Item::Item(string iName, string iRarity, int iItemHp, int iItemAtk, int iItemDef) {
	name = iName;
	rarity = iRarity;
	itemHp = iItemHp;
	itemAtk = iItemAtk;
	itemDef = iItemDef;
}

string Item::getName() {
	return name;
}

void Item::info() {
	cout << "Name: " << name << ", Rarity: " << rarity
		<< ", HP: " << itemHp << ", Attack: " << itemAtk
		<< ", Defense: " << itemDef << "\n";
}