#include<iostream>
#include "heroes.h"

using namespace std;
// default constructor
Heroe::Heroe(){
health=0;
attack=0;
defense=0;
special=0;
speed=0;

}
//constructor with all paramaters
Heroe::Heroe(int newHealth, int newAttack, int newDefense, int newSpecial, int newSpeed){
    health = newHealth;
    attack= newAttack;
    defense= newDefense;
    special= newSpecial;
    speed= newSpeed;
}
//returns heroes health
int Heroe:: getHealth(){
return health;
}
// this functions computes the damage/healing done in battle
//if heroe takes damage a negative int is passed and damaged decreased & vice versa.
void Heroe::changeHealth (int change){
health += change;

}// overload output operator , not sure if necessary yet
ostream& operator<<(ostream &out,const Heroe& hero) {
    //Output a Complex here
    out << hero.health <<" "<< hero.attack <<" "<< hero.defense <<" "<< hero.special <<" "<< hero.speed <<endl;
    return out;
}
istream& operator>>(istream &ins, Heroe& hero) {
    if(!ins.eof()){
    ins >> hero.health >>  hero.attack >> hero.defense >> hero.special >> hero.speed;
    }
    return ins;
}
