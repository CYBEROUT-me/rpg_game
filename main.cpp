#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "weapon.h"
#include "armour.h"
#include "Person.h"

using namespace std;

class Warrior : public Person{
public:
    Warrior(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){}
    int attack(Person &target) override {
        int random = rand() % 7;
        if(random == 5){
            int duration = 1 + rand() % 2;
            cout << "STUN FROM WARRIOR!" << endl;
            target.getEffects("STUN", duration);
        }
        return Person::attack(target);
    }
};

class Mage : public Person{
public:
    Mage(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){};
};

class Rogue : public Person{
public:
    Rogue(string p_race, int p_health, int p_damage) : Person(p_race, p_health, p_damage){}
    int loseHP(int income_damage) override {
        int random = rand() % 7;
        if(random == 3){
            cout << "MISSED ON ROGUE!" << endl;
            return Person::loseHP(0);
        }
        return Person::loseHP(income_damage);
    }

    int attack(Person &target) override {
        int random = rand() % 7;
        if(random == 2){
            int duration = 4 + rand() % 3;
            cout << "RED DAYS!" << endl;
            target.getEffects("BLEEDING", duration);
        }
        return Person::attack(target);
    }
};


int main(){
    Weapon sword("VAMPIRIC_SWORD");
    Weapon kuv("KUVALDA");
    Armour KURTKA("KURTKA");
    Warrior war("nigga", 200, 20);
    Rogue rog("whore", 220, 18);
    //CLEAN WHORING  ^^^^^^^
    war.giveItem(sword);
    war.choose_item(1);
    war.giveItem(sword);
    rog.giveItem(KURTKA);
    war.printINV();
    rog.choose_item(1);
    cout << "START OF GAME!" << endl;

    while(war.isAlive() && rog.isAlive()){
        war.yourTurn(rog);
        cout << rog.getName() << " HP is: " << rog.getHealth() << " | " << war.getName() << " HP is: " << war.getHealth() << endl;
        if(!rog.isAlive()){
            cout << "Congrats! " << war.getName() << " defeated " << rog.getName() << "!" << endl;
            break;
        }
        rog.yourTurn(war);
        cout << war.getName() << " HP is: " << war.getHealth() << " | " << rog.getName() << " HP is: " << rog.getHealth() << endl;
        if(!rog.isAlive()){
            cout << "Congrats! " << rog.getName() << " defeated " << war.getName() << "!" << endl;
            break;
        }
    }
    return 0;
}
