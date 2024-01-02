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

string Item::getRarity() {
	return rarity;
};

int Item::getHp() {
	return itemHp;
};

int Item::getAtk(){
	return itemAtk;
};

int Item::getDef(){
	return itemDef;
};

void Item::info() {
	cout << "Name: " << name << ", Rarity: " << rarity
		<< ", HP: " << itemHp << ", ATK: " << itemAtk
		<< ", DEF: " << itemDef << "\n";
}