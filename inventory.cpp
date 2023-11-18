#include "inventory.h"

Inventory::Inventory(string n, int d, int bl, string t) : name(n), damage(d), blockdmg(bl), type(t) {
    if(type == "WEAPON"){
        enum bonus
        {
            NOTHING,
            KUVALDA,
            VAMPIRIC_SWORD
        };
        int b;
        if(name == "KUVALDA") b = KUVALDA;
        else if(name == "VAMPIRIC_SWORD") b = VAMPIRIC_SWORD;
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
            case VAMPIRIC_SWORD:
            {
                Inventory::
                damage = 4;
                buffs["VAMPIRISM"] = numeric_limits<int>::max();
                buffs["BREAK"] = 3;
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
unordered_map<string, int> Inventory::getBuffs(){
    return buffs;
}
int Inventory::change(std::string key) {
    buffs[key] -= 1;
    if(buffs[key] <= 0){
        buffs.erase(key);
        return 1;
    }
    return 0;
}