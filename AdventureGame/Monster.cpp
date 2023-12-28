#include "Monster.h"

#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

Monster::Monster(string iname, string itype, int iMaxHp, int iatk, int idef) {
	name = iname;
	type = itype;
	maxHp = iMaxHp;
	hp = maxHp;
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
	maxHp += item->itemHp;
	hp += item->itemHp;
	atk += item->itemAtk;
	def += item->itemDef;
	if (itemCount == 0) {
		equipped = item->getName();
	} else {
		equipped += ", " + item->getName();
	}
	itemCount += 1;
}

void Monster::attack(Monster* attacking) {
	cout << "\n" << name << " Attacks " << attacking->getName() <<
		" dealing " << attacking->takeDamage(atk) << " damage\n";
	cout << "\n" << name << " Takes " << takeDamage(attacking->getAttack()/2) << " damage during the combat\n";
}

void Monster::resetHealth() {
	hp = maxHp;
}

bool Monster::operator==(const Monster& compare) {
	return (name == compare.name);
}