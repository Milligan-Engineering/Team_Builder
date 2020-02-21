//File Name: Team Builder
//Name: Tyler Oakes
//Email Address: tsoakes@my.milligan.edu
//Term Project
//Description: This program helps organize players into teams using statistics.
//Version Version 2.0
//Last Changed: 02/14/2020

#include <iostream>
#include <string>
using namespace std;

const int PlayersPerTeam = 10, m = 10;//m is the maximum amount of players the league can hold
string PlayerfirstName[m], PlayerlastName[m], PlayerPhone[m];
int	PlayerAge[m], PlayerYearsPlayed[m], j, TotalPlayers, k;
double PlayerGoals[m], GoalsPerYear[m];

int main()
{
	cout << "How many players do you have to enter?\n";//User can imput number of players
	cin >> k;
	int i = 0;
	while (i < k)//Input while Loop
	{
			cout << "\nPlease Enter Player Information\n";
			cout << "\nEnter Player First Name: ";
			cin >> PlayerfirstName[i];
			cout << "Enter Player Last Name: ";
			cin >> PlayerlastName[i];
			cout << "Please Enter Player's Phone Number: ";
			cin >> PlayerPhone[i];
			cout << "Enter Player Age: ";
			cin >> PlayerAge[i];
			
			cout << "Enter Number Of Years Played: ";
			cin >> PlayerYearsPlayed[i];
			if (PlayerYearsPlayed[i] > 0)//If loop for if first time player it won't ask for Goals scored
			{
				cout << "How Many Goals has the Player Previously Scored: ";
				cin >> PlayerGoals[i];
				cout << "\n";
				GoalsPerYear[i] = PlayerGoals[i] / PlayerYearsPlayed[i];
			}
			i++;
	}
	int n = 0;
	while (n < k)//output while loop, This is to display the information after it is all entered
	{
		cout << "PLAYER NAME: " << PlayerfirstName[n] << " " << PlayerlastName[n] <<
			"    AGE: " << PlayerAge[n] << "    YEARS PLAYED: " << PlayerYearsPlayed[n] <<
			"    GOALS PER YEAR: " << GoalsPerYear[n] << "\n" << endl;
		n++;
	}

	return 0;
}
