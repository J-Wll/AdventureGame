#include "Monster.h"
#include "UtilityVariables.h"
#include "Item.h"

#include <vector>
#include <iostream>
#include <iomanip>
#include <windows.h>   

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
	string cooldownText = "";
	if (cooldown > 0) {
		cooldownText = "\n---ON COOLDOWN FOR "  + to_string(cooldown) + " TURNS---";
	}
	cout << "\n---\n" << opt 
		<< setw(5) << left << "Name: " << setw(34) << left << name << " |  Type: " << type 
		<< "\nStats: HP: " << setw(3) << left << hp << " ATK: " << setw(3)
		<< left << atk << " DEF: " << setw(14) << left << def << " |  Equipped: " << equipped
		<< cooldownText;
}

int Monster::takeDamage(int attackValue) {
	// Damage formula scales so that low def monsters do not take an insane amount of damage, and high defence monsters are not undefeatable
	int damageTaken = (attackValue / ((def + 50) * 0.022)) + 1;
	if (damageTaken <= 0) {
		return 0;
	}
	hp -= damageTaken;
	if (hp <= 0) {
		hp = 0;
	}
	return damageTaken;
}


bool Monster::attack(Monster* attacking, bool playerAttack) {
	string extraText = "Enemy ";
	string colour1 = redColour;
	string colour2 = greenColour;
	if (playerAttack) {
		extraText = "Your ";
		colour1 = greenColour;
		colour2 = redColour;
	}
	if (cooldown == 0) {
		int attackValue = getAttack();
		string enemyType = attacking->getType();
		string effectiveAttack = "\nThe attack was super effective!";

		if (type == "Fire" && enemyType == "Earth") {
			attackValue *= 1.5;
		} else if (type == "Earth" && enemyType == "Water") {
			attackValue *= 1.5;
		} else if (type == "Water" && enemyType == "Fire") {
			attackValue *= 1.5;
		} else {
			effectiveAttack = "";
		}
		
		cout << colour1 << "\n" << extraText << name << " Attacks " << attacking->getName() <<
			" dealing " << attacking->takeDamage(attackValue) << " damage" << effectiveAttack;
		Sleep(SMLSLEEPTIME);
		cout << colour2 << "\n" << extraText << name << " Takes " << takeDamage(attacking->getAttack() / 4) << " damage during the combat\n\n" << defaultColour;
		// Cooldown number is 1 higher than reality because it goes down right after the attack
		cooldown += 2;
		// Attacked
		return true;
	}
	else {
		if (playerAttack) {
			cout << redColour << "\n" << name << " Is on cooldown\n\n\n" << defaultColour;
		}
		// Didn't attack
		return false;
	}
}

void Monster::decreaseCooldown() {
	if (cooldown > 0) {
		cooldown -= 1;
	}
}

void Monster::resetHealth() {
	hp = maxHp;
}

int Monster::getCooldown() {
	return cooldown;
}


int Monster::getHp() {
	return hp;
}

int Monster::getAttack() {
	int randomDmg = rand() % (atk / 5);
	return (atk + randomDmg);
}

string Monster::getName() { return name; };
string Monster::getType() { return type; };

void Monster::setEquipment(Item item) {
	maxHp += item.getHp();
	hp += item.getHp();
	atk += item.getAtk();
	def += item.getDef();
	if (itemCount == 0) {
		equipped = item.getName();
	}
	else {
		equipped += ", " + item.getName();
	}
	itemCount += 1;

}

// Comparison operator for use with find(), returns true/false depending on the name of the monster you are comparing against
bool Monster::operator==(const Monster& compare) {
	return (name == compare.name);
}