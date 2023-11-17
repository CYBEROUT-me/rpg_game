#include "Person.h"

Person::Person(string p_race, int p_health, int p_damage) : race(p_race),
max_health(p_health), damage(p_damage){
    health = max_health;
};
Person::~Person(){};
string Person::getName(){
    string name = typeid(*this).name();
    return name.substr(1, name.length()-1);
}
bool Person::isAlive() {
    return health > 0;
}
double Person::getHealth(){
    return health;
}
void Person::giveItem(Inventory &item){
    inv.push_back(&item);
}
void Person::printINV(){
    cout << "COUNT OF ITEMS: " << inv.size() << endl;
    int count = 1;
    for(const auto& item : inv){
        cout << count << "|: " << "NAME: " << item->Name() << " TYPE: " << item->getType() <<
             " DAMAGE: " << item->Damage() << endl;
        count++;
    }
}
void Person::choose_item(int n){
    string item_type = inv[n-1]->getType();
    if(item_type == "WEAPON"){
        main_weapon = inv[n-1];
        for(auto item : main_weapon->getBuffs()){
            getEffects(item.first, numeric_limits<int>::max());
        }
    }
    else if(item_type == "ARMOUR"){
        main_armour = inv[n-1];
    }
}
int Person::attack(Person& target){
    int dmg = (damage + main_weapon->Damage());
    dmg = dmg + rand() % int(-0.2*(dmg));
    return target.loseHP(dmg);
}
int Person::loseHP(int income_damage){
    int recievedDamage = income_damage - main_armour->BLOCK();
    if(recievedDamage < 0) recievedDamage = 0;
    health -= recievedDamage;
    if(health < 0){
        health = 0;
    }
    cout << "DAMAGE: " << income_damage << " (->" << getName() << ")" << endl;
    return recievedDamage;
}
void Person::getEffects(std::string key, int value) {
    effects[key] = value;
}
vector<string> Person::checkEffect(){
    vector<string> effects_list;
    vector<string> to_delete;
    for(auto& item : effects){
        effects_list.push_back(item.first);
        effects[item.first] = item.second - 1;
        if(item.second <= 0){
            to_delete.push_back(item.first);
        }
    }
    for(auto item : to_delete){
        effects.erase(item);
    }
    return effects_list;
}
void Person::yourTurn(Person &target){
    vector<string> effects_list = checkEffect();
    if(find(effects_list.begin(), effects_list.end(), "BLEEDING") != effects_list.end()){
        loseHP(4);
        if(!isAlive()){
            return;
        }
    }
    if(find(effects_list.begin(), effects_list.end(), "STUN") == effects_list.end()){
        int damaged_HP = attack(target);
        if(find(effects_list.begin(), effects_list.end(), "VAMPIRISM") != effects_list.end() && damaged_HP > 0){
            restoreHP(0.2*damaged_HP);
        }
        auto it = main_weapon->getBuffs().find("BREAK");
        if(it != main_weapon->getBuffs().end()){
            main_weapon->change("BREAK");
        }
    }
}
void Person::restoreHP(int HP){
    health += HP;
    if(health > max_health){
        health = max_health;
    }
}