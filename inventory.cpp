#include "inventory.h"

Inventory::Inventory(string n, int d, int bl, string t) : name(n), damage(d), blockdmg(bl), type(t) {
    if(type == "WEAPON"){
        enum bonus
        {
            NOTHING,
            KUVALDA
        };
        int b;
        if(name == "KUVALDA") b = KUVALDA;
        else if(name == "NOTHING") b = NOTHING;
        switch(b)
        {
            case NOTHING:
            {
                damage = 0;
                break;
            }
            case KUVALDA:
            {
                damage = 3;
                break;
            }
        };
    }
    if(type == "ARMOUR"){
        enum block_damage
        {
            NOTHING,
            KURTKA
        };
        int a;
        if(name == "KURTKA") a = KURTKA;
        else if(name == "NOTHING") a = NOTHING;
        switch(a)
        {
            case NOTHING:
            {
                blockdmg = 0;
                break;
            }
            case KURTKA:
            {
                blockdmg = 3;
                break;
            }
        };
    }
};
Inventory::~Inventory() {};
string Inventory::getType(){
    return type;
}
int Inventory::Damage(){
    return damage;
}
string Inventory::Name(){
    return name;
}
int Inventory::BLOCK(){
    return blockdmg;
}