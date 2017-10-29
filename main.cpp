#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
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
	ifstream inFS; // inputs file stream
	int randLine = 0;
	int highestSpace = 0;
	string goodText[TEXT_LINES];
	string badText[TEXT_LINES];
	
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

	cout << "WELCOME TO MOKELAND!" << endl;	
	
	while (tolower(userPlay) != 'n') {
		cout << "HOW MANY PLAYERS WILL THERE BE: ";
		cin >> numPlayers;
		while (numPlayers > 20 || numPlayers < 1) {		// makes sure user number is between 1-20
			cout << "Sorry! There can only be a maximum of 20 players and a minimum of 1 player." << endl;
			cout << "HOW MANY PEOPLE WILL BE PLAYING: ";
			cin >> numPlayers;
		}
		
		string names[numPlayers]; 	// names, boardspace and money arrays
		int boardSpace[numPlayers];
		int money[numPlayers];		
		cin.ignore(); 	// prevents the getline below from getting messed up
		
		for (int x = 0; x < numPlayers; x++) {
			cout << "ENTER NAME OF PLAYER " << x + 1 << ": ";	// loop to have you input all of the players names
			getline(cin, names[x]);
			boardSpace[x] = 0;	// initializes all subscripts of boardSpace to zero
			money[x] = 0;	// intializes all subscripts of money to zero
		}
		
		isFinished = false;	// resets the value of variable so user can play again
		while (!isFinished) {
			for (p = 0; p < numPlayers; p++) {
				cout << string(40, '=') << endl;
				cout << endl << names[p] << ", PRESS ENTER TO ROLL DIE.";
				if (cin.get() == '\n') {	// waits for user to hit enter
					srand(time(NULL));		// changes the seed everytime you roll
					dieRoll = (rand() % 6) + 1;
					cout << "YOU ROLLED A " << dieRoll << "." << endl;
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
					
					if (boardSpace[p] >= 25) {		// stops the loops from continuing to run once a player reaches the end of the board
						isFinished = true;
						break;
					}
					
					cout << names[p] << " HAS ADVANCED TO SPACE " << boardSpace[p] << endl << endl;
					
					goodOrBad = (rand() % 2) + 1;	
					randLine = (rand() % 20) + 1;
									
					if (goodOrBad == 1) {	// runs if user lands on a good space
						cout << " O   O " << endl << endl;
						cout << "\\_____/" << endl << endl;
						cout << "AWESOME! " << goodText[randLine] << endl;
						moneyAmt = (rand() % 100000) + 1;		
						money[p] = money[p] + moneyAmt;
						cout << "$" << moneyAmt << " WAS ADDED TO YOUR ACCOUNT." << endl;
						cout << "YOU HAVE: $" << money[p] << " IN YOUR ACCOUNT." << endl;
					}
					
					else {	// runs if user lands on a bad space
						cout << " O   O " << endl;
						cout << " _____ " << endl;
						cout << "/     \\" << endl << endl;
						cout << "YOU SUCK! " << badText[randLine] << endl;
						moneyAmt = (rand() % 100000) + 1;
						money[p] = money[p] - moneyAmt;
						cout << "$" << moneyAmt << " WAS REMOVED FROM YOUR ACCOUNT." << endl;
						cout << "YOU HAVE: $" << money[p] << " IN YOUR ACCOUNT." << endl;
					}
				}
			}
		}
		
		cout << "YOU COMPLETED THE MOKELAND BOARD! CONGRATS!" << endl << string(20, '=') << endl << endl;
		
		mostMoney = money[0];
		mostName = names[0];
		highestSpace = boardSpace[0];
		
		for (int i = 0; i < numPlayers; i++) {		// determines who had the most money and who got to the end of the board
			if (money[i] > mostMoney) {
				mostMoney = money[i];			
				mostName = names[i];
			}
		}
		
		cout << "PLAYER WHO COMPLETED THE BOARD FIRST: " << names[p] << endl;
		cout << "PLAYER WHO HAD THE MOST MONEY: " << mostName << " WITH $" << mostMoney << endl << endl;
		cout << "DO YOU WANT TO PLAY AGAIN?" << endl << "Y or N:";
		cin >> userPlay;
	}
	cout << endl << "THANKS FOR PLAYING!!!" << endl;
	return 0;
}
