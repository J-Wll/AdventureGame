#pragma once

// items could buff the whole party, equipment could buff an individual monsterd
class Item {
	string name;
	string type;
	int itemHp = 0;
	int itemAtk = 0;
	int itemSpd = 0;
};

class Equipment : public Item {

};