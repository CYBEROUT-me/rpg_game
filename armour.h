#include <iostream>
#include <string>
#include "item.h"

using namespace std;

class Armour : public Item{
private:
    string name;
    int block;
public:
    Armour(string armour_name);
};