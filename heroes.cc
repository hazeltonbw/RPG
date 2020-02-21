#include "heroes.h"
#include <sstream>
using namespace std;
Heroes::Heroes(){};
Heroes::Heroes(string n, int d, int h, int s, int new_x, int new_y) {
    name = n; defense = d; hp = h; speed = s; x = new_x; y = new_y; 
}
int Heroes::getDefense() {return defense;}
int Heroes::getHp() {return hp;}
int Heroes::getSpeed() {return speed;}
void Heroes::setLocation(int new_x, int new_y) {x = new_x, y = new_y;}
string Heroes::getName() {return name;}

Heroes& operator>>(string s, Heroes &hero) {
    stringstream ss(s);
    string discard;
    //ss >> discard >> hero.name >> hero.defense >> hero.hp 
    //>> hero.speed >> hero.x >> hero.y;
    return hero;
}

ostream& operator<<(ostream &outs, Heroes& hero) {
    outs << "hero " << hero.name << " "
    << hero.defense << " "
    << hero.hp << " "
    << hero.speed << " "
    << hero.x << " "
    << hero.y << endl;
	cout << hero.defense << " " << hero.hp << " " << hero.speed << " " << hero.x << " " << hero.y << " " << endl;
    return outs;
}

istream& operator>>(istream &ins, Heroes &hero) {
    if (!ins.eof()) {
		string discard;
		ins >> discard;
        ins >> hero.name 
        >> hero.defense
        >> hero.hp
        >> hero.speed 
        >> hero.x
        >> hero.y;
	}
    return ins;
}

