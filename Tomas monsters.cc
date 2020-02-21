#include<iostream>
#include "monsters.h"

using namespace std;
// default constructor
Monster::Monster(){
health=0;
attack=0;
defense=0;
special=0;
speed=0;
speed+= 0;
}
//constructors with all paramaters
Monster::Monster(int newHealth, int newAttack, int newDefense, int newSpecial, int newSpeed){
    health = newHealth;
    attack= newAttack;
    defense= newDefense;
    special= newSpecial;
    speed= newSpeed;
}
//returns heroes health
int Monster:: getHealth(){
return health;
}
// this functions computes the damage/healing done in battle
//if monster takes damage a negative int is passed and damaged decreased & vice versa.
void Monster::changeHealth(int change){
health += change;
}
ostream& operator<<(ostream &out,const Monster& monster) {
    //Output a monster
    out << monster.health <<" " << monster.attack <<" "<< monster.defense <<" "<< monster.special <<" "<< monster.speed << endl;
    return out;
}
istream& operator>>(istream &ins, Monster& monster) {
    if(!ins.eof())
    ins >> monster.health >>  monster.attack >> monster.defense >> monster.special >> monster.speed;

    return ins;
}

