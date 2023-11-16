#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

class Weapon : public Inventory{
private:
    string name;
    double damage;
public:
    Weapon(string weapon_name);
};