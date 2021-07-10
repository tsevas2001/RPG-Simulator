
#include "spell.h"

using namespace std;

Spell::Spell(string nm, int pr, int lvl, int md, int mp) : name(nm), price(pr), level(lvl), magicDamage(md), magicPower(mp)
{
	//std::cout << " Spell: " << nm << " Price: " << pr << " Recommended Level:" << lvl << " Magic damage: " << magicDamage << " Recommended Magic Power: "<< magicPower << endl;
}

string Spell::getName()
{
	return name;
}

int Spell:: getLevel()
{
	return level;
}

int Spell::getPrice()
{
	return price;
}

int Spell::getMagicDamage()
{
	return magicDamage;
}

int Spell::getMagicPower()
{
	return magicPower;
}

void Spell::syncPower(Hero* p)
{
	heroPower = p->getMagicPower();
	magicPower += heroPower;
	std::cout << "New Magic Power!" << magicPower << endl;
}


Spell::~Spell()
{
	//std::cout << "Deleting Spell with name " << name << endl;
}


IceSpell::IceSpell(string name, int price, int level, int magicDamage, int magicPower, int lp, int rd) : Spell(name, price, level, magicDamage, magicPower), lessDamage(lp), rounds(rd)
{
	//std::cout << "Ice Spell: " << name << " Price: " << price << " Recommended Level:" << level << " Magic Damage: " << magicDamage << " Recommended Magic Power: " << magicPower << " Less Damage: " << lessDamage << " Rounds: " << rounds << endl;
}

IceSpell::~IceSpell()
{
	//std::cout << "Destructor of " << getName() << endl;
}


FireSpell::FireSpell(string name, int price, int level, int magicDamage, int magicPower, int la, int rd) : Spell(name, price, level, magicDamage, magicPower), lessArmor(la), rounds(rd)
{
	//std::cout << "Fire Spell: " << name << " Price: " << price << " Recommended Level:" << level << " Magic Damage: " << magicDamage << " Recommended Magic Power: " << magicPower << " Less Armor: " << lessArmor << " Rounds: " << rounds << endl;
}

FireSpell::~FireSpell()
{
	//std::cout << "Destructor of " << getName() << endl;
}


LightingSpell::LightingSpell(string name, int price, int level, int magicDamage, int magicPower, int ms, int rd) : Spell(name, price, level, magicDamage, magicPower), miss(ms), rounds(rd)
{
	//std::cout << "Lighting Spell: " << name << " Price: " << price << " Recommended Level:" << level << " Magic Damage: " << magicDamage << " Recommended Magic Power: " << magicPower << " Chance to miss: " << miss << " Rounds: " << rounds << endl;
}

LightingSpell::~LightingSpell()
{
	//std::cout << "Destructor of " << getName() << endl;
}

