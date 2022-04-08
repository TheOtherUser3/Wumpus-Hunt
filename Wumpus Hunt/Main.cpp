

#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <time.h>
#include "Header.h"

using namespace std;



int main(void) {

	srand(time(NULL));

	Game Wumpus;
	Wumpus.done = false;
	Introduction();
	do {



		static const int caves[20][3]{
		{9, 1, 11}, {17, 2, 0}, {1, 12, 3}, {16, 2, 4}, {13, 5, 3},
		{6, 4, 15}, {7, 5, 14}, {8, 19, 6}, {7, 10, 9}, {18, 0, 8},
		{14, 11, 8}, {10, 0, 12}, {13, 11, 1}, {12, 14, 4}, {13, 10, 6},
		{19, 5, 16}, {15, 3, 17}, {16, 18, 1}, {19, 9, 17}, {15, 18, 7}
		};


		Wumpus.playerfloor = 0;
		Wumpus.wumpusfloor = 0;
		Wumpus.score = 101;
		Wumpus.arrows = 3;
		Wumpus.game_finish = false;
		Wumpus.batfloor1 = 0;
		Wumpus.batfloor2 = 0;
		Wumpus.pitfloor1 = 0;
		Wumpus.pitfloor2 = 0;
		Wumpus.game_loss = -1;
		Wumpus.previousroom = -1;
		Wumpus.wumpusawake = false;
		Wumpus.arrowlocation = -1;
		Wumpus.arrowfired = false;


		Wumpus.batpit(Wumpus);

		do {
			if (Wumpus.arrows == 0) {
				cout << "You have run out of arrows!  You lose!\n";
				cout << "Score = 0/100\n\n\n\n\n";
				break;
			}
			cout << "\nPrevious Room = " << Wumpus.previousroom << "\n\n";
			cout << "\nCurrent Room = " << Wumpus.playerfloor << "\n\n";
			Wumpus.batcheck(caves, Wumpus);
			Wumpus.pitcheck(caves, Wumpus);
			Wumpus.wumpuscheck(caves, Wumpus);
			if (Wumpus.game_loss == 0) {
				cout << "\nYou died and have failed to kill the fearsome Wumpus.  You lose.\n\n\n";
				cout << "Score = 0/100\n\n\n\n\n";
				break;
			}
			else if (Wumpus.game_loss == 1) {
				cout << "\nCongratulations!  You have killed the fearsoem Wumpus and saved the locals!  You win!\n\n\n";
				cout << "Score = " << Wumpus.score << "/100 \n\n\n\n\n";
				break;
			}
			int o = 0;
			Wumpus.previousroom = Wumpus.playerfloor;
			cout << "\nThere are three paths before you.  Enter the number of the room you'd like to enter, or type 20 to shoot an arrow.\n\n\n";
			cout << "To the left lies room " << caves[Wumpus.playerfloor][0] << "\n";
			cout << "Forward lies room " << caves[Wumpus.playerfloor][1] << "\n";
			cout << "To the right lies room " << caves[Wumpus.playerfloor][2] << "\n";
			cout << "Enter 20 to shoot an arrow\n";
			cin >> o;
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			if (o == caves[Wumpus.playerfloor][0] || o == caves[Wumpus.playerfloor][1] || o == caves[Wumpus.playerfloor][2]) {
				Wumpus.playerfloor = o;
			}
			else if (o == 20) {
				cout << "Arrows left: " << Wumpus.arrows << "\n\n\n";
				int c = 0;
				cout << "In which direction would you like to shoot an arrow?\n";
				cout << "To the left towards room " << caves[Wumpus.playerfloor][0] << "\n";
				cout << "Forward towards room " << caves[Wumpus.playerfloor][1] << "\n";
				cout << "To the right towards room " << caves[Wumpus.playerfloor][2] << "\n";
				cout << "Enter 20 to go back and not shoot an arrow\n";
				cin >> c;
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
				if (c == caves[Wumpus.playerfloor][0] || c == caves[Wumpus.playerfloor][1] || c == caves[Wumpus.playerfloor][2]) {
					Wumpus.arrowfired = true;
					Wumpus.arrowlocation = c;
					Wumpus.arrows--;
				}
				else if (c == 20) {
				}
				else {
					cout << "\n\n\n\n\nInvalid Input, Please try again.\n";
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "\n";
					c = 0;
				}
			}
			else {
				cout << "\n\n\n\n\nInvalid Input, Please try again.\n";
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n";
				o = 0;
			}
			Wumpus.arrowcheck(caves, Wumpus);
			Wumpus.arrowlocation = -1;
			Wumpus.arrowfired = false;
			if (Wumpus.wumpusawake == true) {
				int y = rand() % 3;
				Wumpus.wumpusfloor = caves[Wumpus.wumpusfloor][y];
			}
			Wumpus.score--;
		} 
		while (Wumpus.game_finish == false);

		if (Wumpus.game_loss == 1) {
			cout << "\nCongratulations!  You have killed the fearsome Wumpus and saved the locals!  You win!\n\n";
			cout << "Score = " << Wumpus.score << "/100 \n\n\n\n\n";
		}

		int m = 0;
		
		cout << "\n\n\nWould you like to play again?\n";
		cout << "1) Yes\n";
		cout << "2) No\n";
		cin >> m;
		if (m == 2) {
			Wumpus.done = true;
		}
		else if (m == 1) {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		}
		else {
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
			cout << "\n\n\n\n\nInvalid Input, You must play again.\n\n\n\n";
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n";
			m = 0;
		}


	}
	while (Wumpus.done == false);
}