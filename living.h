#ifndef LIVING_H
#define LIVING_H

#pragma once
#include <iostream>


using namespace std;

class Living
{
private:
    string name;
    int Level;
    int healthPower;
public:
    Living(string, int, int);
    string getName();
    int getHealth();
    int getLevel();
    void addHealth(int);
    void removeHealth(int);
    void setLevel();
    void recoverHealth();
    ~Living();
};



class Hero :
    public Living
{
private:
    int magicPower;
    int maxMagicPower = 100;
    int strength;
    int dexterity;
    int agility;
    int money;
    int experience;
    int defense=0;

public:
    Hero(string, int, int, int, int, int, int, int, int);
    int getDamage();
    int getMagicPower();
    int getAgility();
    int getDexterity();
    int getMoney();
    int getDefense();
    void recoverMagicPower();
    void addMagicPower(int);
    void removeDefense(int);
    void addDefense(int);
    void removeMagicPower(int);
    void addDamage(int);
    void removeDamage(int);
    void addAgility(int);
    void addMoney(int);
    void removeMoney(int);
    void addDexterity(int);
    void levelUp();
    void checkXP(int);
    void updateStats();
    ~Hero();
};




class Warrior :
    public Hero
{
private:
    int strength = 20;
    int agility = 10;
public:
    Warrior(string, int, int, int, int, int, int, int, int);
    ~Warrior();
};




class Sorcerer :
    public Hero
{
private:
    int dexterity = 10;
    int agility = 10;
public:
    Sorcerer(string, int, int, int, int, int, int, int, int);
    ~Sorcerer();
};




class Paladin :
    public Hero
{
private:
    int damage = 15;
    int dexterity = 30;
public:
    Paladin(string, int, int, int, int, int, int, int, int);
    ~Paladin();
};





class Monster :
    public Living
{
private:
    int damage;
    int defense;
    int miss;
public:
    Monster(string, int, int, int, int, int);
    int getDamage();
    int getDefense();
    int getMiss();
    void addMiss(int);
    void removeMiss(int);
    void addDefense(int);
    void addDamage(int);
    void removeDamage(int);
    void removeDefense(int);
    ~Monster();
};


class Dragon :
    public Monster
{
private:
    int damage = 20;
public:
    Dragon(string, int, int, int, int, int);
    ~Dragon();
};


class Exoskeleton :
    public Monster
{
private:
    int defense = 20;
public:
    Exoskeleton(string, int, int, int, int, int);
    ~Exoskeleton();
};


class Spirit :
    public Monster
{
private:
    int miss = 10;
public:
    Spirit(string, int, int, int, int, int);
    ~Spirit();
};


#endif
