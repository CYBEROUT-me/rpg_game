#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "inventory.h"
#include "weapon.h"
#include "armour.h"
#include <vector>

using namespace std;

class Person{
protected:
    string race;
    int health;
    int damage;
    string main_weapon_name;
    int weapon_damage = 0;
    string main_armour_name;
    int armour_block = 0;
    vector<Inventory*> inv;
public:
    Person(string p_race, int p_health, int p_damage) : race(p_race),
    health(p_health), damage(p_damage){};
    virtual ~Person(){};
    virtual string getName(){
        string name = typeid(*this).name();
        return name.substr(1, name.length()-1);
    }
    bool isAlive() {
        return health > 0;
    }
    virtual double getHealth(){
        return health;
    }
    virtual void giveItem(Inventory &item){
        inv.push_back(&item);
    }
    virtual void printINV(){
        cout << "COUNT OF ITEMS: " << inv.size() << endl;
        int count = 1;
        for(const auto& item : inv){
            cout << count << "|: " << "NAME: " << item->Name() << " TYPE: " << item->getType() <<
            " DAMAGE: " << item->Damage() << endl;
            count++;
        }
    }
    virtual void choose_item(int n){
        string item_type = inv[n-1]->getType();
        if(item_type == "WEAPON"){
            weapon_damage = inv[n-1]->Damage();
            main_weapon_name = inv[n-1]->Name();
        }
        else if(item_type == "ARMOUR"){
            armour_block = inv[n-1]->Damage();
            main_armour_name = inv[n-1]->Name();
        }
    }
    virtual void attack(Person& target){
        int dmg = (damage + weapon_damage - armour_block);
        dmg = dmg + rand() % int(-0.2*(dmg));
        loseHP(target, dmg);
        return;
    }
    virtual void loseHP(Person& target, int income_damage){
        int chance = rand() % 6;
        cout << "CHANCE: " << chance << endl;
        if(chance == 3 && target.getName() == "Rogue"){
            cout << "\nROGUE IS TOO COOL!\n" << endl;
        }
        else{
            target.health -= income_damage;
            if(target.health < 0){
                target.health = 0;
            }
            if(getName() == "Warrior" && chance == 2 && health > 0){
                cout << "\nWARRIOR IS TOO COOL!\n" << endl;
                attack(target);
            }
            cout << "DAMAGE: " << income_damage << " (" << getName() << "->" << target.getName() << ")" << endl;
        }
    }
};

class Warrior : public Person{
public:
    Warrior(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){};
};

class Mage : public Person{
public:
    Mage(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){};
};

class Rogue : public Person{
public:
    Rogue(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){};
};


int main() {
    Weapon kuv("KUVALDA");
    Armour KURTKA("KURTKA");
    Warrior war("nigga", 200, 20);
    Rogue rog("whore", 220, 18);
    war.giveItem(kuv);
    rog.giveItem(KURTKA);
    war.printINV();
    war.choose_item(1);
    rog.choose_item(1);
    cout << "START OF GAME!" << endl;
    while(war.isAlive() && rog.isAlive()){
        war.attack(rog);
        cout << rog.getName() << " HP is: " << rog.getHealth() << " | " << war.getName() << " HP is: " << war.getHealth() << endl;
        if(!rog.isAlive()){
            cout << "Congrats! " << war.getName() << " defeated " << rog.getName() << "!" << endl;
            break;
        }
        rog.attack(war);
        cout << war.getName() << " HP is: " << war.getHealth() << " | " << rog.getName() << " HP is: " << rog.getHealth() << endl;
        if(!rog.isAlive()){
            cout << "Congrats! " << rog.getName() << " defeated " << war.getName() << "!" << endl;
            break;
        }
    }
    return 0;
}
