#include "Monster.h"

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

Monster::Monster(string iname, string itype, int ihp, int iatk, int idef) {
	name = iname;
	type = itype;
	hp = ihp;
	atk = iatk;
	def = idef;
}

void Monster::info(string opt = "") {
	cout << "\n---\n" << opt
		<< setw(5) << left << "Name: " << setw(23) << left << name << " |  Type: " << type 
		<< "\nStats: HP: " << setw(3) << left << hp << " ATK: " << setw(3)
		<< left << atk << " DEF: " << setw(3) << left << def << " |  Equipped: " << equipped;
}

int Monster::takeDamage(int attackValue) {
	int damageTaken = (attackValue * def / 100);
	hp -= damageTaken;
	if (hp <= 0) {
		hp = 0;
	}
	return damageTaken;
}

int Monster::getHp() {
	return hp;
}

int Monster::getAttack() {
	int randomDmg = rand() % atk / 5;
	return atk + randomDmg;
}

void Monster::setName(string in) { name = in; };
string Monster::getName() { return name; };

void Monster::setType(string in) { type = in; };
string Monster::getType() { return type; };

void Monster::setEquipment(Item* item) {
	hp += item->itemHp;
	atk += item->itemAtk;
	def += item->itemDef;
	equipped = item->getName();
}

bool Monster::operator==(const Monster& compare) {
	return (name == compare.name);
}