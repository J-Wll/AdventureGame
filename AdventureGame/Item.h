#pragma once

#include <string>

// Items buff an individual monster and are equipped through methods inside the Monster class
class Item {
private:
	std::string name;
	std::string rarity;
	int itemHp;
	int itemAtk;
	int itemDef;
public:
	std::string getRarity();
	std::string getName();
	int getHp();
	int getAtk();
	int getDef();
	Item(std::string iName, std::string iRarity, int iItemHp, int iItemAtk, int iItemDef);
	void info();
};
