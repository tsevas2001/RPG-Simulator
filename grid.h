#ifndef GRID_H
#define GRID_H

#pragma once
#include <iostream>
#include <time.h>
#include <cstdlib>
#include "item.h"
#include "spell.h"

using namespace std;

class Grid
{
private:
	char grid[14][23] = {

		"+====================+",
		"#                    #",
		"#XXXXXXXXXXXXXXXXXXXX#",
		"#-------XXXXX--------#",
		"#        XXX         #",
		"#                    #",
		"#          ----------#",
		"#                    #",
		"#XXXXXXXXXXXXXXX     #",
		"#----------------    #",
		"#XXXXXXXXXXXXXXX     #",
		"#                    #",
		"#                M   #",
		"+====================+" };

	Weapon* weapons[3];
	Armor* armors[3];
	Potion* potions[3];
	IceSpell* iceSpells[3];
	FireSpell* fireSpells[3];
	LightingSpell* lightingSpells[3];
	Spell* spellInventory[100];
	Spell* spellInventory2[100];
	Spell* spellInventory3[100];
	Item* inventory[100];
	Item* inventory2[100];
	Item* inventory3[100];
	Hero* Team[3];

	string character1 = "@";
	int position1[2] = { 12, 2 };

public:
	Grid();
	void displayMap();
	void move(char);
	void openMarket();
	void setShopWeapon(Weapon*);
	void setShopArmor(Armor*);
	void setShopPotion(Potion*);
	void setShopIceSpell(IceSpell*);
	void setShopFireSpell(FireSpell*);
	void setShopLightingSpell(LightingSpell*);
	void setTeam(Hero*);
	void battle();
	void displayStats(Monster**);
	void displayTeam();
	void checkInventory();
	void use();
	void equip();
	void attack(Monster**, int, int);
	void castSpell(Monster**, int, int);
	void clear_screen();
	bool nonAccessible(char);
	bool common(char);
	bool market(char);
	void StartGame();

	~Grid();
};

#endif
