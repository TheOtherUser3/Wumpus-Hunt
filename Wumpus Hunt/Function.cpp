#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include "Header.h"

using namespace std;

void Introduction() {
	cout << "********************************************************************************************\n";
	cout << "Welcome to the Wumpus Hunt.  You are a well renowned adventurer, and you have\n";
	cout << "come to slay the mighty Wumpus that has been terrorizing the locals.  The Wumpus\n";
	cout << "lives in a dark cave system made out of 20 rooms.  It is a treacherous location, with\n";
	cout << "bottomless pits that can kill you and giant bats that can carry you away.  In addition, if\n";
	cout << "the mighty Wumpus catches you, then you will be killed.  Since the cave is dark, you will not\n";
	cout << "be able to see anything.  You will have to rely on your senses to avoid danger. Each\n";
	cout << "room is connected to three other rooms, and you have three arrows with you to shoot the Wumpus.\n";
	cout << "If you shoot your arrow into the rooms that the Wumpus resides in, you win.  Be wary,\n";
	cout << "however, for if you shoot a room that the Wumpus is sleeping next to, then it may wake up\n";
	cout << "and will move to an adjacent room in pursuit of the noise.  And you may just be in that room.\n";
	cout << "Good Luck, and happy Wumpus hunting!\n";
	cout << "*********************************************************************************************\n\n\n\n\n\n\n";
	system("pause");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nYou enter the first room of the cave system.\n\n";
}



void Game::batpit(Game &Wumpus) {
	do {
		Wumpus.batfloor1 = rand() % (20 - 1) + 1;
		Wumpus.batfloor2 = rand() % (20 - 1) + 1;
		Wumpus.pitfloor1 = rand() % (20 - 1) + 1;
		Wumpus.pitfloor2 = rand() % (20 - 1) + 1;
		Wumpus.wumpusfloor = rand() % (20 - 1) + 1;
	} 
	while (Wumpus.batfloor1 == Wumpus.batfloor2 || Wumpus.batfloor1 == Wumpus.pitfloor1 || Wumpus.batfloor1 == Wumpus.pitfloor2 || Wumpus.batfloor2 == Wumpus.pitfloor1 || Wumpus.batfloor2 == Wumpus.pitfloor2 || Wumpus.pitfloor1 == Wumpus.pitfloor2);
}
void Game::batcheck(const int caves[20][3], Game& Wumpus) {
	if (Wumpus.playerfloor == Wumpus.batfloor1 || Wumpus.playerfloor == Wumpus.batfloor2) {
		cout << "\n\nAfter entering the room, you are lifted off your feet. It seems\n";
		cout << "a Giant Bat has taken you!  After struggling for what seems\n";
		cout << "like hours, it finally releases you, but you have no idea where you are.\n\n\n";
		Wumpus.playerfloor = rand() % 20;
	}
	if (Wumpus.batfloor1 == caves[playerfloor][0] || Wumpus.batfloor1 == caves[playerfloor][1] || Wumpus.batfloor1 == caves[playerfloor][2] || Wumpus.batfloor2 == caves[playerfloor][0] || Wumpus.batfloor2 == caves[playerfloor][1] || Wumpus.batfloor2 == caves[playerfloor][2]){
		cout << "\nYou hear a faint rustling\n\n";
	}
}
void Game::pitcheck(const int caves[20][3], Game& Wumpus) {
	if (Wumpus.playerfloor == Wumpus.pitfloor1 || Wumpus.playerfloor == Wumpus.pitfloor2) {
		cout << "\nAfter entering the room, you lose your footing and trip into a bottomless pit!\n\n";
		Wumpus.game_finish = true;
		Wumpus.game_loss = 0;
	}
	else if (Wumpus.pitfloor1 == caves[playerfloor][0] || Wumpus.pitfloor1 == caves[playerfloor][1] || Wumpus.pitfloor1 == caves[playerfloor][2] || Wumpus.pitfloor2 == caves[playerfloor][0] || Wumpus.pitfloor2 == caves[playerfloor][1] || Wumpus.pitfloor2 == caves[playerfloor][2]) {
		cout << "\nYou feel a faint breeze\n\n";
	}
}
void Game::wumpuscheck(const int caves[20][3], Game& Wumpus) {
	if (Wumpus.playerfloor == Wumpus.wumpusfloor) {
		cout << "As you begin walking to the next room, the terrible Wumpus stumbles forward\n";
		cout << "and devours you in one gulp before you have any time to react!\n\n";
		Wumpus.game_finish = true;
		Wumpus.game_loss = 0;
	}
	else if (Wumpus.wumpusfloor == caves[playerfloor][0] || Wumpus.wumpusfloor == caves[playerfloor][1] || Wumpus.wumpusfloor == caves[playerfloor][2]) {
		cout << "\nA horrible stench hits your nostrils\n\n";
	}
}

void Game::arrowcheck(const int caves[20][3], Game& Wumpus) {
	if (Wumpus.arrowfired == true) {
		if (Wumpus.arrowlocation == Wumpus.wumpusfloor) {
			cout << "You hear a great roar of pain that soon falls silent.  Upon following the noise,\n";
			cout << "you find the dead body of the mighty Wumpus.\n";
			Wumpus.game_finish = true;
			Wumpus.game_loss = 1;
		}
		else if (Wumpus.arrowlocation == caves[Wumpus.wumpusfloor][0] || Wumpus.arrowlocation == caves[Wumpus.wumpusfloor][1] || Wumpus.arrowlocation == caves[Wumpus.wumpusfloor][2]) {
			int x = rand() % 4;
			if (x == 0) {
				cout << "Your arrow missed!\n\n";
			}
			else if (Wumpus.wumpusawake == false) {
				cout << "Your arrow missed!  But from the horrifying growl you hear nearby, it seems the\n";
				cout << "noise has awoken the Wumpus!  It is now stumbling through the caves trying to find you!\n";
				Wumpus.wumpusawake = true;
			}
		}
		else if (Wumpus.playerfloor == caves[Wumpus.wumpusfloor][0] || Wumpus.playerfloor == caves[Wumpus.wumpusfloor][1] || Wumpus.playerfloor == caves[Wumpus.wumpusfloor][2]) {
			int l = rand() % 4;
			if (l == 0) {
				cout << "Your arrow missed!\n\n";
			}
			else if (Wumpus.wumpusawake == false) {
				cout << "Your arrow missed!  But from the horrifying growl you hear nearby, it seems the\n";
				cout << "noise has awoken the Wumpus!  It is now stumbling through the caves trying to find you!\n";
				Wumpus.wumpusawake = true;
			}
		}
		else {
			cout << "Your arrow missed!\n\n";
		}
	}
}

/* cin.clear();
cin.ignore(1000, '\n');
cout << "\n";
c = 0;
return; */