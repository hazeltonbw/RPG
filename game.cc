#include "game.h"
#include "map.h"
#include "monster.h"
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unistd.h>

using namespace std;

Game::Game() {
	//saveGame();
	if (saveFileExists())
		loadGame();
	else 
		newGame();
	startGame();

	/*if (savedGame) // if there is a saved game
	  cout << "Would you like to load your saved game? (Yes or no)\n";
	  string userInput = "";
	  cin >> userInput; if (!cin) exit(EXIT_FAILURE);
	  if (!userInput.empty() && tolower(userInput.at(0)) == 'y')
	  loadGame();
	  */
}

void Game::turn_on_ncurses() {
	const unsigned int TIMEOUT = 10;
	initscr();                              // Start curses mode
	start_color();                          // Enable Colors if possible
	init_pair(1, COLOR_WHITE, COLOR_BLACK); // Set up some color pairs
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_RED, COLOR_BLACK);
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
	clear();
	noecho();
	cbreak();
	timeout(TIMEOUT); // Set a max delay for key entry
}

void Game::startGame() {

	// Milliseconds to wait for a getch to finish
	const int UP = 65; // Key code for up arrow
	const int DOWN = 66;
	const int LEFT = 68;
	const int RIGHT = 67;
	
	Game::turn_on_ncurses();
	Map map;
	int x = Map::SIZE / 2, y = Map::SIZE / 2; // Start in middle of the world
	while (true) {
	  int ch = getch(); // Wait for user input, with TIMEOUT delay
	  if (ch == 'q' || ch == 'Q')
	  break;
	  else if (ch == RIGHT) {
	  x++;
	  if (y >= Map::SIZE)
	  y = Map::SIZE - 1; // Clamp value
	  } else if (ch == LEFT) {
	  x--;
	  if (y < 0)
	  y = 0;
	  } else if (ch == UP) {
	  y--;
	  if (x < 0)
	  x = 0;
	  } else if (ch == DOWN) {
	  y++;
	  if (x >= Map::SIZE)
	  x = Map::SIZE - 1;  // Clamp value
	  } else if (ch == ERR) { // No keystroke
	  ;                     // Do nothing
	  }
	  clear();
	  map.draw(x, y);
	  mvprintw(11, 11, "X: %i Y: %i\n", x, y);
	  refresh();
	  usleep(5000);
	  }

	  clear();
	  endwin(); // End curses mode
	  system("clear");
	cout << "Would you like to save your game? (Y)es or (n)o\n ";
	string s; cin >> s;
	if (s.size() && s.at(0) == 'y')
		Game::saveGame();
	else {
		cout << "Goodbye!\n";
		exit(0);
	}
}

bool Game::saveFileExists() {
	string file = "SaveFile.txt";
	if (access(file.c_str(), F_OK) != -1)
		return true;
	else return false;
}

void Game::loadGame() {
	string file = "SaveFile.txt";
	ifstream ins(file); if (!ins) return;
	while (ins) {
		string temp;
		getline(ins,temp);
		if (temp.find("monster")) {
			Monster m;
			cout << temp << "load monster " << endl;
			string cont; cin >> cont; 
			temp >> m;
			cout << m;
			monsters.push_back(m);
		}

		if (temp.find("hero")) {
			Heroes h;
			cout << temp << "load hero" << endl;
			string cont; cin >> cont; 
			heroes.push_back(temp >> h);
			cout << h;
		}
	}
}

	void Game::saveGame() {
		string file = "SaveFile.txt";
		if (access(file.c_str(), F_OK) != -1) {
			// file exists
			cout << "Save file"
				<< " exists, would you like to overwrite this slot? (Y)es or (n)o\n";
			string s; cin >> s;
			if (!cin)
				exit(EXIT_FAILURE);
			if (s.size()) { // make sure string isnt empty
				if (tolower(s.at(0)) == 'y') {
					string command = "rm " + file;
					system(command.c_str());
					Game::writeFile(file);
					cout << "Game saved\n";
				}
				else if (tolower(s.at(0)) == 'n')
					cout << "Not saving\n";
				else {
					cout << "Invalid input. Quitting.\n";
					exit(1);
				}
			}
		}
		else // No input, default save to file
			Game::writeFile(file);
	}



	void Game::writeFile(string file) {
		ofstream outs(file);
		if (outs) {
			for (int i = 0; i < monsters.size(); i++)
				outs << monsters.at(i);
			for (int i = 0; i < heroes.size(); i++) 
				outs << heroes.at(i);
			outs.close();
		}

	}
	void Game::newGame() {
		Monster new_monster1 = Monster("CCC", 1,2,3,50,50,0);
		Monster new_monster2 = Monster("Kerney", 2,3,4,50,50,0);
		Heroes new_hero1 = Heroes("Brandon", 2,10,2,51,51);
		Heroes new_hero2 = Heroes("Tomas", 1,10,1,53,53);
		Game::pushBackMonsters(new_monster1);
		Game::pushBackMonsters(new_monster2);
		Game::pushBackHeroes(new_hero1);
		Game::pushBackHeroes(new_hero2);
		// TODO
	}

	void Game::pushBackMonsters(Monster &m) {
		monsters.push_back(m);
	}

	void Game::pushBackHeroes(Heroes &h) {
		heroes.push_back(h);
	}
/*
	bool Game::sortSpeed(Monster md31, Monster m2) {
		return m1.speed < m2.speed;
	}
*/
