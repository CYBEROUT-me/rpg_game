#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class Weapon : public Item{
private:
    string name;
    int damage;
    int chance_to_broke;
public:
    Weapon(string weapon_name);
};