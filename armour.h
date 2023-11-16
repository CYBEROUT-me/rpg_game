#include <iostream>
#include <string>
#include "inventory.h"

using namespace std;

class Armour : public Inventory{
private:
    string name;
    int block;
public:
    Armour(string armour_name);
};