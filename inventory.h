#ifndef _INV_

// Defines _ANIMALS_ if above
// conditions fails
#define _INV_

#include <iostream>
#include <string>

using namespace std;

class Inventory{
private:
    string name;
    int damage;
    int blockdmg;
    string type;
public:
    Inventory(string n, int d, int bl, string t);
    virtual ~Inventory();
    virtual string getType();
    virtual int Damage();
    virtual string Name();
    virtual int BLOCK();
};
#endif // _INV_