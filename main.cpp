#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std; 

int main() {
	const int TEXT_LINES = 20;
	char userPlay;
	int userSpace = 0;
	int dieRoll = 0;
	int numPlayers = 0;
	int goodOrBad = 0;
	int moneyAmt = 0;
	int mostMoney = 0;
	string mostName;
	int p = 0;
	bool isFinished = false;
	ifstream inFS; // input file stream
	string goodText;
	string badText;
	int randLine = 0;
	int highestSpace = 0;

	cout << "WELCOME TO MOKELAND!" << endl; 

	while (userPlay != 'n') {
		cout << "How many users will be playing: ";
		cin >> numPlayers;
		while (numPlayers > 20 || numPlayers < 1) {		// makes sure user number is between 1-20
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
		
		isFinished = false;	// resets the value of variable so user can play again
		while (!isFinished) {
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
					randLine = (rand() % 20) + 1;
					
					string goodText[20];
					string badText[20];
					
					inFS.open("good.txt");
					for (int g = 0; g < TEXT_LINES; g++) {
						getline(inFS, goodText[g], '\n');	// places each of the lines from good.txt into an array
					}
					inFS.close();
					
					inFS.open("bad.txt");
					for (int b = 0; b < TEXT_LINES; b++) {
						getline(inFS, badText[b], '\n');	// places each of the lines from bad.txt into an array
					}
					inFS.close();
					
					if (goodOrBad == 1) { // good
						cout << " O   O " << endl << endl;
						cout << "\\_____/" << endl;
						cout << "Awesome! " << goodText[randLine] << endl;
						moneyAmt = (rand() % 100000) + 1;
						money[p] = money[p] + moneyAmt;
						cout << "$" << moneyAmt << " added!" << endl;
						cout << "You have: $" << money[p] << endl;
					}
					else { // bad
						cout << " O   O " << endl;
						cout << " _____ " << endl;
						cout << "/     \\" << endl;
						cout << "You suck! " << badText[randLine] << endl;
						moneyAmt = (rand() % 100000) + 1;
						money[p] = money[p] - moneyAmt;
						cout << "$" << moneyAmt << " removed!" << endl;
						cout << "You have: $" << money[p] << endl;
					}
					
					if (boardSpace[p] >= 25) {
						isFinished = true;
						break;
					}
				}
			}
		}
		
		mostMoney = money[0];
		mostName = names[0];
		highestSpace = boardSpace[0];
		
		for (int i = 0; i < numPlayers; i++) {
			if (money[i] > mostMoney) {
				mostMoney = money[i];
				mostName = names[i];
			}
		}
		cout << mostName << " had the most money with: $" << mostMoney << endl;
		cout << names[p] << " was the only survivor till the end!" << endl << endl;
		cout << "Do you want to play again? y/n" << endl;
		cin >> userPlay;
	}
	return 0;
}
