#include "monster.h"
#include <sstream>
using namespace std;

Monster::Monster() {}
// Default constructor
Monster::Monster(string name) {
    isDead = false;
}

Monster::Monster(string n, int d, int h, int s, int new_x, int new_y, bool dead) {
    name = n; defense = d; hp = h; speed = s; x = new_x; y = new_y; isDead = dead;
}
int Monster::getSpeed() {return speed;}
bool Monster::operator<(const Monster& m)  {return speed < m.speed;}
bool Monster::isMonsterDead() {return isDead;}
bool Monster::monsterSort(const Monster &l, const Monster &r) {return l.speed < r.speed;}
ostream& operator<<(ostream &outs, const Monster monster) {
    outs << "monster " << monster.name << " " << 
    monster.defense << " " <<
    monster.hp << " " <<
    monster.speed << " " <<
    monster.x << " " << 
    monster.y << " " <<
    monster.isDead << endl;
    return outs;
}
Monster& operator>>(string s, Monster &monster) {
    stringstream ss(s);
    string discard;
    ss >> discard >> monster.name >> monster.defense >>
    monster.hp >> monster.speed >> monster.x >> monster.y >> monster.isDead;
    return monster;
}

istream& operator>>(istream& ins, Monster &monster) {
    if (!ins.eof()) {
        string discard; ins >> discard; if (discard == "monster") cout << "h\n";
        ins >> monster.name >> monster.defense >>
        monster.hp >> monster.speed >> monster.x >> monster.y >> monster.isDead;
    }
    return ins;
}
