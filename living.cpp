
#include "living.h"

using namespace std;

Living::Living(string nm, int level, int health) : Level(level), healthPower(health), name(nm)
{
    //std::cout << "Living: " << name << " Level: " << Level << " Health: " << healthPower << " Just created!" << endl;
}

int Living::getHealth()
{
    return healthPower;
}

string Living::getName()
{
    return name;
}

int Living::getLevel()
{
    return Level;
}

void Living::addHealth(int hp)
{
    healthPower += hp;
}

void Living::removeHealth(int h)
{
    healthPower -= h;
}

void Living::setLevel()
{
    Level++;
    std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
    std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

    std::cout << "\033[1;92m                   _      _____ _   _ _____ _       _   _______   _ _ _     \033[0m" << endl;
    std::cout << "\033[1;92m                  | |    |  ___| | | |  ___| |     | | | | ___ \\ | | | |       \033[0m" << endl;
    std::cout << "\033[1;92m                  | |    | |__ | | | | |__ | |     | | | | |_/ / | | | |  \033[0m" << endl;
    std::cout << "\033[1;92m                  | |    |  __|| | | |  __|| |     | | | |  __/  | | | |  \033[0m" << endl;
    std::cout << "\033[1;92m                  | |____| |___\\ \\_/ / |___| |____ | |_| | |     |_|_|_|  \033[0m" << endl;
    std::cout << "\033[1;92m                  \\_____/\\____/ \\___/\\____/\\_____/  \\___/\\_|     (_|_|_)          \033[0m" << endl;

    std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
    std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
    std::cout << "Level Up: " << Level << endl;
}

void Living::recoverHealth()
{
    if (healthPower <= 0)
    {
        healthPower = 500;
    }
    else
    {
        healthPower = 1000;
    }
}

Living::~Living()
{
    //std::cout << "Deleting Living:  " << name << endl;

}






Hero::Hero(string name, int level, int health, int mP, int str, int dext, int agil, int mn, int xp) : Living(name, level, health), magicPower(mP), strength(str), dexterity(dext), agility(agil), money(mn), experience(xp)
{
    //std::cout << "Hero: " << name << " Level: " << level << " Health: " << health << " Magic Power: " << magicPower << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility << " Money: " << money << " Experience: " << experience << " Just created!" << endl;

}

int Hero::getDamage()
{
    return strength;
}

int Hero::getMagicPower()
{
    return magicPower;
}

int Hero::getAgility()
{
    return agility;
}

int Hero::getDexterity()
{
    return dexterity;
}

int Hero::getMoney()
{
    return money;
}

int Hero::getDefense()
{
    return defense;
}

void Hero::recoverMagicPower()
{
    magicPower = maxMagicPower;
}

void Hero::addMagicPower(int mp)
{
    magicPower += mp;
}

void Hero::removeDefense(int def)
{
    defense -= def;
}

void Hero::addDefense(int def)
{
    defense += def;
}
void Hero::removeDamage(int dmg)
{
    strength -= dmg;
}

void Hero::removeMagicPower(int mp)
{
    magicPower -= mp;
}

void Hero::addDamage(int dmg)
{
    strength += dmg;
}

void Hero::addAgility(int agil)
{
    agility += agil;
}

void Hero::addMoney(int cash)
{
    money += cash;
}

void Hero::removeMoney(int cash)
{
    money -= cash;
}

void Hero::addDexterity(int dext)
{
    dexterity += dext;
}

void Hero::checkXP(int xp)
{
    int temp;
    temp = experience + xp;

    if (temp >= 100)
        levelUp();
    else
        experience += xp;
}

void Hero::levelUp()
{

    setLevel();
    experience -= 100;
    strength += strength * 20 / 100;
    dexterity += dexterity * 20 / 100;
    agility += agility * 20 / 100;

    updateStats();
}

void Hero::updateStats()
{
    std::cout << "UPDATE STATS! " << " Name: "<< getName() <<" Magic Power: " << magicPower << " Strength: " << strength << " Dexterity: " << dexterity << " Agility: " << agility << endl;
}


Hero::~Hero()
{
    //std::cout << "Deleting Hero:  " << Living::getName() << endl;
}






Warrior::Warrior(string name, int level, int health, int magicPower, int str, int dext, int agil, int money, int xp) : Hero(name, level, health, magicPower, str, dext, agil, money, xp)
{
    addDamage(strength);
    addAgility(agility);
   // std::cout << "Warrior: " << name << " Level: " << level << " Health: " << health << " Magic Power" << magicPower << " Strength: " << getDamage() << " Dexterity: " << dext << " Agility: " << getAgility() << " Money: " << money << " XP: " << xp << endl;
}

Warrior::~Warrior()
{
    //std::cout << "Deleting Warrior: " << getName() << endl;
}



Sorcerer::Sorcerer(string name, int level, int health, int magicPower, int str, int dext, int agil, int money, int xp) : Hero(name, level, health, magicPower, str, dext, agil, money, xp)
{
    addDexterity(dexterity);
    addAgility(agility);
    //std::cout << "Sorcerer: " << name << " Level: " << level << " Health: " << health << " Magic Power" << magicPower << " Strength: " << str << " Dexterity: " << getDexterity() << " Agility: " << getAgility() << " Money: " << money << " XP: " << xp << endl;
}

Sorcerer::~Sorcerer()
{
    //std::cout << "Deleting Sorcerer: " << getName() << endl;
}





Paladin::Paladin(string name, int level, int health, int magicPower, int str, int dext, int agil, int money, int xp) : Hero(name, level, health, magicPower, str, dext, agil, money, xp)
{
    addDamage(damage);
    addDexterity(dexterity);
    //std::cout << "Sorcerer: " << name << " Level: " << level << " Health: " << health << " Magic Power" << magicPower << " Strength: " << getDamage() << " Dexterity: " << getDexterity() << " Agility: " << agil << " Money: " << money << " XP: " << xp << endl;
}

Paladin::~Paladin()
{
    //std::cout << "Deleting Paladin " << getName() << endl;
}







Monster::Monster(string name, int level, int health, int dmg, int def, int ms) : Living(name, level, health), damage(dmg), defense(def), miss(ms)
{
    //std::cout << "Monster: " << name << " Level: " << level << " Health: " << health << " Damage: " << damage << " Defense: " << defense << " Chance to miss: " << miss << endl;
}

int Monster::getDamage()
{
    return damage;
}

int Monster::getDefense()
{
    return defense;
}

int Monster::getMiss()
{
    return miss;
}

void Monster::addMiss(int ms)
{
    miss += ms;
}

void Monster::removeMiss(int ms)
{
    miss -= ms;
}

void Monster::addDamage(int dmg)
{
    damage += dmg;
}

void Monster::removeDamage(int dmg)
{
    damage -= dmg;
}

void Monster::addDefense(int def)
{
    defense += def;
}

void Monster::removeDefense(int def)
{
    defense -= def;
}

Monster::~Monster()
{
    //std::cout << "Deleting Monster " << getName() << endl;
}





Dragon::Dragon(string name, int level, int health, int dmg, int def, int ms) : Monster(name, level, health, dmg, def, ms)
{
    addDamage(damage);
    //std::cout << "Dragon: " << name << " Level: " << level << " Health: " << health << " Damage: " << getDamage() << " Defense: " << def << " Chance to miss: " << ms << endl;
}

Dragon::~Dragon()
{
    //std::cout << "Deleting Dragon: " << getName() << endl;
}



Exoskeleton::Exoskeleton(string name, int level, int health, int dmg, int def, int ms) : Monster(name, level, health, dmg, def, ms)
{
    addDefense(defense);
    //std::cout << "Exoskeleton: " << name << " Level: " << level << " Health: " << health << " Damage: " << dmg << " Defense: " << getDefense() << " Chance to miss: " << ms << endl;
}

Exoskeleton::~Exoskeleton()
{
    //std::cout << "Deleting Exoskeleton" << endl;
}



Spirit::Spirit(string name, int level, int health, int dmg, int def, int ms) : Monster(name, level, health, dmg, def, ms)
{
    addMiss(miss);
    //std::cout << "Spirit: " << name << " Level: " << level << " Health: " << health << " Damage: " << dmg << " Defense: " << def << " Chance to miss: " << getMiss() << endl;
}

Spirit::~Spirit()
{
    //std::cout << "Deleting Spirit " << getName() << endl;
}
