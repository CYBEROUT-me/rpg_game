#ifndef _PER_
#define _PER_

#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include "inventory.h"
#include <algorithm>
#include <limits>
#include <algorithm>

using namespace std;

class Person{
protected:
    string race;
    int health;
    int max_health;
    int damage;
    Inventory* main_weapon = nullptr;
    int main_weapon_pos;
    Inventory* main_armour = nullptr;
    int main_armour_pos;
    unordered_map<int, Inventory*> inv;
    unordered_map<string, int> effects;
public:
    Person(string p_race, int p_health, int p_damage);
    virtual ~Person();
    virtual string getName();
    bool isAlive();
    virtual double getHealth();
    virtual void giveItem(Inventory &item);
    virtual void printINV();
    virtual void choose_item(int n);
    virtual int attack(Person& target);
    virtual int loseHP(int income_damage);
    virtual void getEffects(string key, int value);
    virtual vector<string> checkEffect();
    virtual void yourTurn(Person& target);
    virtual void restoreHP(int HP);
};

#endif // _PER_