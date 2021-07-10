#include "item.h"
using namespace std;

Item::Item(string nm, int pr, int lvl) : name(nm), price(pr), level(lvl)
{
	//std::cout << "Item: " << name << " Price: " << price << " Recommended Level: " << level << " Has  been created successfully!" << endl;
}

Item::~Item()
{
	//std::cout << "Deleting Item with name " << name << endl;
}

string Item::getName()
{
	//std::cout << name << " " << price << " " << level << endl;
	return name;
}

int Item::getPrice()
{
	return price;
}

int Item::getLevel()
{
	return level;
}

Weapon::Weapon(string name, int price, int level, int dmg, int hds = 1) : Item(name, price, level), damage(dmg), hands(hds)
{
	//std::cout << "Weapon: " << name << " Price: " << price << " Recommended Level:" << level << " Damage: " << damage << " Hands: " << hands << endl;

}

void Weapon::syncDamage(Hero* d)
{
	heroDamage = d->getDamage();
	damage += heroDamage;
	std::cout << "New damage: " << damage << endl;
}

int Weapon::getDamge()
{
	return damage;
}

int Weapon::getHands()
{
	return hands;
}

Weapon::~Weapon()
{
	//std::cout << "Destructor of " << Item::getName() << endl;
}


Armor::Armor(string name, int price, int level, int rc) : Item(name, price, level), resistance(rc)
{
	//std::cout << "Armor: " << name << " Price: " << price << " Recommended Level:" << level << " Resistance: " << resistance << endl;
}

int Armor::getResistance()
{
	return resistance;
}


Armor::~Armor()
{
	//std::cout << "Destructor of " << getName() << endl;
}



Potion::Potion(string name, int price, int level, int ma) : Item(name, price, level), moreAbility(ma)
{
	//std::cout << "Potion: " << name << " Price: " << price << " Recommended Level:" << level << " Ability: " << moreAbility << endl;
}

int Potion::getAbility()
{
	return moreAbility;
}

Potion::~Potion()
{
	//std::cout << "Destructor of " << getName() << endl;
}

