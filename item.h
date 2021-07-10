#ifndef ITEM_H
#define ITEM_H

#pragma once
#include <cstring>
#include <iostream>
#include "living.h"

using namespace std;




class Item
{
private:
	string name;
	int price;
	int level;
public:
	Item(string, int, int);
	~Item();
	string getName();
	int getPrice();
	int getLevel();

};



class Weapon :
	public Item
{
private:
	int damage;
	int hands;
protected:
	int heroDamage;
public:
	Weapon(string, int, int, int, int);
	void syncDamage(Hero*);
	int getDamge();
	int getHands();
	~Weapon();
};


class Armor :
	public Item
{
private:
	int resistance;
public:
	Armor(string, int, int, int);
	int getResistance();
	void removeResistance(int);
	void addResistance(int);
	
	~Armor();
};




class Potion :
	public Item
{
private:
	int moreAbility;
public:
	Potion(string, int, int, int);
	int getAbility();
	~Potion();
};


#endif
