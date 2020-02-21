//File Name: Team Builder
//Name: Tyler Oakes
//Email Address: tsoakes@my.milligan.edu
//Term Project
//Description: This program helps organize players into teams using statistics.
//Version Version 2.0
//Last Changed: 02/21/2020

#include <iostream>
#include <string>
using namespace std;

double calcSkill (int PlayerYearsPlayed, double GoalsPerYear);

const int PlayersPerTeam = 10, m = 10;//m is the maximum amount of players the league can hold
string PlayerfirstName[m], PlayerlastName[m], PlayerPhone[m];
int	PlayerAge[m], PlayerYearsPlayed[m], j, k, error;// k = The number of players the user has
double PlayerGoals[m], GoalsPerYear[m];

int main()
{
	do// Do While to validate imput
	{
		error = 0;
		cout << "How many players do you have to enter?\n";//User can imput number of players
		cin >> k;
		
		if (cin.fail())
		{
			cout << "Please enter a valid integer\n" << endl;
			error = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	} 
	while (error == 1); 
	

	int i = 0;
	while (i < k)// This is the while Loop where the user will input all the user information
	{
			cout << "\nPlease Enter Player Information\n";
			cout << "\nEnter Player First Name: ";
			cin >> PlayerfirstName[i];
			cout << "Enter Player Last Name: ";
			cin >> PlayerlastName[i];
			cout << "Please Enter Player's Phone Number: ";
			cin >> PlayerPhone[i];
			
			do
			{
				error = 0;
				cout << "Enter Player Age: ";
				cin >> PlayerAge[i];
				
				if (cin.fail())
				{
					cout << "Please enter a valid integer\n" << endl;
					error = 1;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} 
			while (error == 1); 
			
			
			do
			{
				error = 0;
				cout << "Enter Number Of Years Played: ";
				cin >> PlayerYearsPlayed[i];
				
				if (cin.fail())
				{
					cout << "Please enter a valid integer\n" << endl;
					error = 1;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			} 
			while (error == 1);

			if (PlayerYearsPlayed[i] > 0)//If loop for if first time player it won't ask for Goals scored
			{
				
				do
				{
					error = 0;
					cout << "How Many Goals has the Player Previously Scored: ";
					cin >> PlayerGoals[i];
					
					if (cin.fail())
					{
						cout << "Please enter a valid number" << endl;
						error = 1;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				} 
				while (error == 1);

				cout << "\n";
				GoalsPerYear[i] = PlayerGoals[i] / PlayerYearsPlayed[i];
			}
			i++;
	}
	int n = 0;
	while (n < k)//output while loop, This is to display the information after it is all entered
	{
		cout << "PLAYER NAME: " << PlayerfirstName[n] << " " << PlayerlastName[n] <<
			"    AGE: " << PlayerAge[n] << "     PHONE: " << PlayerPhone[n] <<"    YEARS PLAYED: " << PlayerYearsPlayed[n] <<
			"    GOALS PER YEAR: " << GoalsPerYear[n] << "\n" << endl;
		n++;
	}

	return 0;
}

double calcSkill(int PlayerYearsPlayed, double GoalsPerYear)
{
	return(GoalsPerYear + sqrt(PlayerYearsPlayed));
}
