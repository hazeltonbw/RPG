#include<iostream>

using namespace std;


class Monster {
    private:
        int health;
        int attack;
        int defense;
        int special;
        int speed;
    public:
        Monster();
        Monster( int newHealth, int newAttack, int newDefense, int newSpecial, int newSpeed);
        int getHealth();
        int getAttack();
        int getDefense();
        int getSpecial();
        int getSpeed();
        void changeHealth(int change);
        friend ostream& operator<<(ostream &lhs,const Monster& monster);
        friend istream& operator>>(istream &lsh, Monster& monster);

};

~
