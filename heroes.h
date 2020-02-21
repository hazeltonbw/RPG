#pragma once
#include <iostream>
using namespace std;

class Heroes{
    private:
        string name;
        int defense;
        int hp;
        int speed;
		int x; //location
		int y; //location
    public:
        Heroes();
        Heroes(string n, int d, int h, int s, int x, int y);
        Heroes getHero();
		void setLocation(int x, int y);
        int getDefense();
        int getHp();
        int getSpeed();
        string getName();
        friend Heroes& operator>>(string s, Heroes &hero);
        friend ostream& operator<<(ostream &lhs, Heroes& hero);
        friend istream& operator>>(istream &lhs, Heroes &hero);
};
