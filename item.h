#ifndef _INV_

// Defines _ANIMALS_ if above
// conditions fails
#define _INV_

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <limits>

using namespace std;

class Item{
private:
    string name;
    int damage;
    int blockdmg;
    string type;
    unordered_map<string, int> buffs;
public:
    Item(string n, int d, int bl, string t);
    virtual ~Item();
    virtual string getType();
    virtual int Damage();
    virtual string Name();
    virtual int BLOCK();
    virtual unordered_map<string, int> getBuffs();
    virtual int change(string key);
};
#endif // _INV_