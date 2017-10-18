#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std; 

int main() {
	char userPlay;
	int userSpace = 0;
	int dieRoll = 0;
	int numPlayers = 0;
	int goodOrBad = 0;
	int moneyAmt = 0;
	int mostMoney = 0;
	int p = 0;
	ifstream inFS; // input file stream

	cout << "WELCOME TO MOKELAND!" << endl; 

	while (userPlay != 'n') {
		cout << "How many users will be playing: ";
		cin >> numPlayers;
		while (numPlayers > 20 || numPlayers < 1) {		// makes sure user number is between
			cout << "Sorry! There can only be a maximum of 20 players and a minimum of 1 player." << endl;
			cout << "How many users will be playing: ";
			cin >> numPlayers;
		}
		
		string names[numPlayers]; 	// names array
		int boardSpace[numPlayers];	// boards array
		int money[numPlayers];		// money array
		cin.ignore(); 	// prevents the getline below from getting messed up
		
		for (int x = 0; x < numPlayers; x++) {
			cout << "Enter name of player " << x + 1 << ": ";	// loop to have you input all of the players names
			getline(cin, names[x]);
			boardSpace[x] = 0;	// initializes all subscripts of boardSpace to zero
			money[x] = 0;	// intializes all subscripts of money to zero
		}
		
		do {
			for (p = 0; p < numPlayers; p++) {
				cout << names[p] << " press enter to roll die!" << endl;
				if (cin.get() == '\n') {	// waits for user to hit enter
					srand(time(NULL));		// changes the seed everytime you roll
					dieRoll = (rand() % 6) + 1;
					cout << "You rolled a " << dieRoll << "!" << endl;
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
					boardSpace[p] = dieRoll + boardSpace[p];
					cout << names[p] << ": " << boardSpace[p] << endl; // ONLY FOR TESTING remove later!
					goodOrBad = (rand() % 2) + 1;
					
					if (goodOrBad == 1) { // good
						cout << ":-D" << endl;
						moneyAmt = (rand() % 100000) + 1;
						money[p] = money[p] + moneyAmt;
						cout << "You have: $" << money[p] << endl;
					}
					else { // bad
						cout << ":-(" << endl;
						moneyAmt = (rand() % 100000) + 1;
						money[p] = money[p] - moneyAmt;
						cout << "You have: $" << moneyAmt << endl;
					}
				}
			}
		} while (boardSpace[p] < 25);
		
		mostMoney = money[0];	
		
		for (int i = 0; i < numPlayers; i++) {
			if (money[i] > mostMoney) {
				money[i] = mostMoney;
			}
		}
		cout << mostMoney << endl;
		cout << "Do you want to play again? y/n" << endl;
		cin >> userPlay;
	}
	return 0;
}
