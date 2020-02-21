#pragma once
#include <iostream>
using namespace std;

class Monster{
    private:
        string name;
        int defense;
        int hp;
        int speed;
        int x;
        int y;
        bool isDead;
    public:
        Monster();
        Monster(string n);
        Monster(string n, int d, int h, int s, int x, int y, bool dead);
        int getSpeed();
        bool isMonsterDead();
        bool operator<(const Monster& m) ;
        bool monsterSort(const Monster &l, const Monster &r);
        friend Monster& operator>>(string s, Monster &monster);
        friend ostream& operator<<(ostream &outs, const Monster monster);
        friend istream& operator>>(istream &ins, Monster &monster);
};