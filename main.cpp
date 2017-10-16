#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <time.h>
using namespace std; 

int main() {
	// define variables 
	char userPlay;
	int userSpace = 0;
	int dieRoll = 0;
	int numPlayers = 0;
	
	// arrays
	//int money[];

	// SLIDE 6.4 FOR ALGORITHM FOR FINDING MAXIMUM VALUE
	
	// SLIDE 6.6 FOR SETTING ALL ARRAY ELEMENTS TO 0 (FOR RESTARTING GAME)
	
	// welcome to my game
	cout << "WELCOME TO MOKELAND!" << endl; 

	//while (userPlay != 'n') {
		cout << "How many users will be playing: ";
		cin >> numPlayers;
		while (numPlayers > 20 || numPlayers < 1) {		// makes sure user number is between
			cout << "Sorry! There can only be a maximum of 20 players and a minimum of 1 player." << endl;
			cout << "How many users will be playing: ";
			cin >> numPlayers;
		}
		
		string names[numPlayers]; 	// names array
		cin.ignore(); 	// prevents the getline below from getting messed up
		
		for (int x = 0; x < numPlayers; x++) {
			cout << "Enter name of player " << x + 1 << ": ";	// loop to have you input all of the players names
			getline(cin, names[x]);
		}
		
		int boardSpace[numPlayers]; // creates a seperate subscript for each user to keep track of their place on the board

		do {
			int p = 0;
			for (p = 0; p < numPlayers; p++) {
				cout << names[p] << " press enter to roll die!" << endl;
				if (cin.get() == '\n') {	// waits for user to hit enter
					srand(time(NULL));		// changes the seed everytime you play
					dieRoll = (rand() % 6) + 1;
					cout << "You rolled a " << dieRoll << "!" << endl << endl;
					switch(dieRoll) {
						case 1:
							cout << " _________\n";
							cout << "|         |\n";
							cout << "|    o    |\n";
							cout << "|         |\n";
							cout << "|_________|\n\n";
							break;
						case 2:
							cout << " _________\n";
							cout << "|         |\n";
							cout << "|  o      |\n";
							cout << "|      o  |\n";
							cout << "|_________|\n\n";
							break;
						case 3:
							cout << " _________\n";
							cout << "| o       |\n";
							cout << "|    o    |\n";
							cout << "|       o |\n";
							cout << "|_________|\n\n";
							break;
						case 4:
							cout << " _________\n";
							cout << "| o     o |\n";
							cout << "|         |\n";
							cout << "| o     o |\n";
							cout << "|_________|\n\n";
							break;
						case 5:
							cout << " _________\n";
							cout << "| o     o |\n";
							cout << "|    o    |\n";
							cout << "| o     o |\n";
							cout << "|_________|\n\n";
							break;
						case 6:
							cout << " _________\n";
							cout << "| o     o |\n";
							cout << "| o     o |\n";
							cout << "| o     o |\n";
							cout << "|_________|\n\n";
							break;
					}
					boardSpace[p] = boardSpace[p + dieRoll];
					cout << boardSpace[p] << endl;
				}
			} while (boardSpace[p] < 25);
		}
	//}
	
	return 0;
}
