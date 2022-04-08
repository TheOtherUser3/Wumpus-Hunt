#pragma once

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;


class Game {
public:
	int score;
	int playerfloor;
	int wumpusfloor;
	int arrows;
	bool game_finish;
	int game_loss;
	bool wumpusawake;
	bool arrowfired;
	bool done;
	int batfloor1;
	int batfloor2;
	int pitfloor1;
	int pitfloor2;
	int previousroom;
	int arrowlocation;
	void batpit(Game& Wumpus);
	void batcheck(const int caves[20][3], Game& Wumpus);
	void pitcheck(const int caves[20][3], Game& Wumpus);
	void wumpuscheck(const int caves[20][3], Game& Wumpus);
	void arrowcheck(const int caves[20][3], Game& Wumpus);
};


void Introduction();