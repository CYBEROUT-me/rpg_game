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
    int attack(Person *target) override {
        int random = rand() % 7;
        if(random == 5){
            int duration = 1 + rand() % 2;
            cout << "STUN FROM WARRIOR!" << endl;
            target->getEffects("STUN", duration);
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

    int attack(Person *target) override {
        int random = rand() % 7;
        if(random == 2){
            int duration = 4 + rand() % 3;
            cout << "RED DAYS!" << endl;
            target->getEffects("BLEEDING", duration);
        }
        return Person::attack(target);
    }
};


Person* priority(vector<Person*> team){
    Person* maxHP = team[0];
    for(auto pers : team){
        if(pers->getHealth() > maxHP->getHealth()){
            maxHP = pers;
        }
    }
    return maxHP;
}

bool teamAlive(vector<Person*> team){
    for(int i = 0; i < team.size(); i++){
        if(team[i]->isAlive()){
            return true;
        }
    }
    return false;
}

void fight(vector<Person*> team1, vector<Person*> team2){
    int queue1 = 0;
    int queue2 = 0;
    int turn = 1;
    while(teamAlive(team1) && teamAlive(team2)){
        if(turn == 1){
            team1[queue1]->yourTurn(priority(team2));
            cout << "TEAM 1 HP: " << endl;
            for(auto pers : team1){
                cout << pers->getName() << " HP is: " << pers->getHealth() << endl;
            }
            cout << "TEAM 2 HP: " << endl;
            for(auto pers : team2){
                cout << pers->getName() << " HP is: " << pers->getHealth() << endl;
            }
            if(!teamAlive(team2)){
                cout << "CONGRATS! TEAM 1 HAS WON!!!" << endl;
                break;
            }
            queue1++;
            if(queue1 >= team1.size()){
                queue1 = 0;
            }
        }

        if(turn == 2){
            team2[queue2]->yourTurn(priority(team1));
            cout << "TEAM 1 HP: " << endl;
            for(auto pers : team1){
                cout << pers->getName() << " HP is: " << pers->getHealth() << endl;
            }
            cout << "TEAM 2 HP: " << endl;
            for(auto pers : team2){
                cout << pers->getName() << " HP is: " << pers->getHealth() << endl;
            }
            if(!teamAlive(team1)){
                cout << "CONGRATS! TEAM 2 HAS WON!!!" << endl;
                break;
            }
            queue2++;
            if(queue2 >= team2.size()){
                queue2 = 0;
            }
        }
        if(turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }
    }
}

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

    fight({&war}, {&rog});

//    while(war.isAlive() && rog.isAlive()){
//        war.yourTurn(rog);
//        cout << rog.getName() << " HP is: " << rog.getHealth() << " | " << war.getName() << " HP is: " << war.getHealth() << endl;
//        if(!rog.isAlive()){
//            cout << "Congrats! " << war.getName() << " defeated " << rog.getName() << "!" << endl;
//            break;
//        }
//        rog.yourTurn(war);
//        cout << war.getName() << " HP is: " << war.getHealth() << " | " << rog.getName() << " HP is: " << rog.getHealth() << endl;
//        if(!rog.isAlive()){
//            cout << "Congrats! " << rog.getName() << " defeated " << war.getName() << "!" << endl;
//            break;
//        }
//    }
    return 0;
}
