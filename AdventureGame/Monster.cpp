#include "Monster.h"

#include <vector>
#include <iostream>

using namespace std;

Monster::Monster(string iname, string itype, int ihp, int iatk, int idef) {
	name = iname;
	type = itype;
	hp = ihp;
	atk = iatk;
	def = idef;
}

void Monster::info(string opt = "") {
	cout << "\n---\n" << opt << "Monsters name: " << name << "\nType: " << type << "\nStats: HP: " << hp << " ATK: " << atk << " DEF: " << def << "\n" << "Equipped: " << equipped;
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

bool Monster::operator==(const Monster& compare) {
	return (name == compare.name);
}