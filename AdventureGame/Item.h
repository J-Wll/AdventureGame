#pragma once

#include <string>

// Items buff an individual monster and are equipped through methods inside the Monster class
class Item {
private:
public:
	std::string name;
	std::string rarity;
	int itemHp;
	int itemAtk;
	int itemDef;
	std::string getName();
	Item(std::string iName, std::string iRarity, int iItemHp, int iItemAtk, int iItemDef);
	void info();
};
