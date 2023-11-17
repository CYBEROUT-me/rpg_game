#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

class Weapon : public Inventory{
private:
    string name;
    int damage;
    int chance_to_broke;
public:
    Weapon(string weapon_name);
};