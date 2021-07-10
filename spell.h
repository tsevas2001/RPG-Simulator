#ifndef SPELL_H
#define SPELL_H

#pragma once
#include <iostream>
#include "living.h"

using namespace std;

class Spell
{
private:
    string name;
    int price;
    int level;
    int magicDamage;
    int magicPower;
protected:
    int heroPower;
public:
    Spell(string, int, int, int, int);
    string getName();
    int getLevel();
    int getPrice();
    int getMagicDamage();
    int getMagicPower();
    void syncPower(Hero*);
    ~Spell();
};



class IceSpell :
    public Spell
{
private:
    int lessDamage;
    int rounds;
public:
    IceSpell(string, int, int, int, int, int, int);
    ~IceSpell();
};



class FireSpell :
    public Spell
{
private:
    int lessArmor;
    int rounds;
public:
    FireSpell(string, int, int, int, int, int, int);
    ~FireSpell();
};



class LightingSpell :
    public Spell
{
private:
    int miss;
    int rounds;
public:
    LightingSpell(string, int, int, int, int, int, int);
    ~LightingSpell();
};

#endif
