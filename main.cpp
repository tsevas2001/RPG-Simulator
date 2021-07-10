
#include <iostream>
using namespace std;
#include "item.h"
#include "spell.h"
#include "living.h"
#include "grid.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    Grid* map = new Grid;
    //                               name,lvl,health,magicpower,strength,dexterity,agility,money,exp             
    Warrior* malphite = new Warrior("Malphite", 1, 1000, 100, 150, 2, 40, 1000, 0);
    Sorcerer* morgana = new Sorcerer("Morgana", 1, 1000, 100, 100, 5, 40, 1000, 0);
    Paladin* jax = new Paladin("Jax", 1, 1000, 100, 150, 5, 20, 1000, 0);
    //name,price,lvl,damge,hands
    Weapon* sa1 = new Weapon("Avenger", 250, 1, 100, 1);
    Weapon* sa2 = new Weapon("Master Sword", 500, 2, 250, 1);
    Weapon* sa3 = new Weapon("Rod of Roses", 1500, 3, 750, 2);
    Armor* test = new Armor("Wizard Shield", 250, 1, 20);
    Armor* test2 = new Armor("Shell Shield", 500, 2, 50);
    Armor* test3 = new Armor("Tetra Shield", 1500, 3, 100);
    Potion* klsd = new Potion("Agility-Potion", 5000, 1, 30);
    Potion* klasdas = new Potion("Damage-Potion", 5000, 1, 30);
    Potion* klasd = new Potion("Defense-Potion", 5000, 1, 30);
    IceSpell* test12 = new IceSpell("Freeze", 250, 1, 250, 5, 20, 4);
    IceSpell* test13 = new IceSpell("Ice Beam", 500, 2, 500, 10, 20, 4);
    IceSpell* test14 = new IceSpell("Blizzard", 1500, 3, 1000, 15, 20, 4);
    FireSpell* kj2 = new FireSpell("Pyro Ball", 250, 1, 250, 5, 15, 2);
    FireSpell* kj3 = new FireSpell("Flamethrower", 500, 2, 500, 10, 15, 2);
    FireSpell* kj4 = new FireSpell("Fire Blast", 1500, 3, 1000, 15, 15, 2);
    LightingSpell* sdf1 = new LightingSpell("Shock Wave", 250, 1, 250, 5, 20, 2);
    LightingSpell* sdf2 = new LightingSpell("Charge Beam", 500, 2, 500, 10, 20, 2);
    LightingSpell* sdf3 = new LightingSpell("Thunderbolt", 1500, 3, 1000, 15, 20, 2);
    map->setTeam(malphite);
    map->setTeam(morgana);
    map->setTeam(jax);
    map->setShopWeapon(sa1);
    map->setShopWeapon(sa2);
    map->setShopWeapon(sa3);
    map->setShopArmor(test);
    map->setShopArmor(test2);
    map->setShopArmor(test3);
    map->setShopPotion(klsd);
    map->setShopPotion(klasdas);
    map->setShopPotion(klasd);
    map->setShopIceSpell(test12);
    map->setShopIceSpell(test13);
    map->setShopIceSpell(test14);
    map->setShopFireSpell(kj2);
    map->setShopFireSpell(kj3);
    map->setShopFireSpell(kj4);
    map->setShopLightingSpell(sdf1);
    map->setShopLightingSpell(sdf2);
    map->setShopLightingSpell(sdf3);
    






    map->StartGame();







    delete map;
    delete malphite;
    delete morgana;
    delete jax;
    delete sa1;
    delete sa2;
    delete sa3;
    delete test;
    delete test2;
    delete test3;
    delete klsd;
    delete klasdas;
    delete klasd;
    delete test12;
    delete test13;
    delete test14;
    delete kj2;
    delete kj3;
    delete kj4;
    delete sdf1;
    delete sdf2;
    delete sdf3;

    

    return 0;
}
