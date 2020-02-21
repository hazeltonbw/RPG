#pragma once
#include <vector>
#include "monster.h"
#include "heroes.h"
using namespace std;

class Game{
    private:
        vector<Monster> monsters;
        vector<Heroes> heroes;

    public:
        Game();
        void turn_on_ncurses();
		bool saveFileExists();
        void pushBackMonsters(Monster &m);
        void pushBackHeroes(Heroes &h);
        void writeFile(string s);
        void startGame();
        void loadGame();
        void saveGame();
        void newGame();
};
