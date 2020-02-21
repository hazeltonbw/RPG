#include<iostream>

using namespace std;


class Heroe {
    private:
        int health;
        int attack;
        int defense;
        int special;
        int speed;
    public:
        Heroe();
        Heroe( int newHealth, int newAttack, int newDefense, int newSpecial, int newSpeed);
        int getHealth();
        int getAttack();
        int getDefense();
        int getSpecial();
        int getSpeed();
        void changeHealth(int change);
        friend ostream& operator<<(ostream &lhs,const Heroe& hero);
        friend istream& operator>>(istream &lsh, Heroe& hero);

};
~
