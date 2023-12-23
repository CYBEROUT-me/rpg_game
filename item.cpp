#include "item.h"

Item::Item(string n, int d, int bl, string t) : name(n), damage(d), blockdmg(bl), type(t) {
    if(type == "WEAPON"){
        enum bonus
        {
            KUVALDA,
            VAMPIRIC_SWORD
        };
        int b;
        if(name == "KUVALDA") b = KUVALDA;
        else if(name == "VAMPIRIC_SWORD") b = VAMPIRIC_SWORD;
        switch(b)
        {
            case KUVALDA:
            {
                damage = 3;
                break;
            }
            case VAMPIRIC_SWORD:
            {
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
            KURTKA
        };
        int a;
        if(name == "KURTKA") a = KURTKA;
        switch(a)
        {
            case KURTKA:
            {
                blockdmg = 3;
                break;
            }
        };
    }
};
Item::~Item() {};
string Item::getType(){
    return type;
}
int Item::Damage(){
    return damage;
}
string Item::Name(){
    return name;
}
int Item::BLOCK(){
    return blockdmg;
}
unordered_map<string, int> Item::getBuffs(){
    return buffs;
}
int Item::change(std::string key) {
    buffs[key] -= 1;
    if(buffs[key] <= 0){
        buffs.erase(key);
        return 1;
    }
    return 0;
}