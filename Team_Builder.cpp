//File Name: Team Builder
//Name: Tyler Oakes
//Email Address: tsoakes@my.milligan.edu
//Term Project
//Description: This program helps organize players into teams using statistics.
//Version Version 2.07
//Last Changed: 03/2/2020

#include <iostream>
#include <string>
using namespace std;

const int PlayersPerTeam = 10, m = 10;//m is the maximum amount of players the league can hold
string PlayerfirstName[m], PlayerlastName[m], PlayerPhone[m];
int	PlayerAge[m], PlayerYearsPlayed[m], i;
double PlayerGoals[m], GoalsPerYear[m];

void listPrint(string fnames[], string lnames[], string phone[], int age[], int years[], double goals[],
	double gpy[], int arraysize);
//Precondition: User has Entered input for strings First Name, Last Name, Phone Number. Intergers 
//of Age, Years Played. The double of years scored.
//Postcondition: It will list all the input in single lines readable for the user.

double calcSkill (int PlayerYearVal, double GPYVal);
//Precondition: User has Entered number of years played and goals made both as intergers.
//Postcondition: The program will have performed a calculation converting yearsplayed and 
//goalsscored to a double. It will output a double to be used as the skill player metric 
//to be ranked with as a double.

int main()
{
	int error, k;// k = The number of players the user has
	do// Do while to make sure that the desired number of players is not bigger than the array size
	{
		do// Do While to validate imput
		{
		error = 0;
		cout << "How many players do you have to enter?\nMake sure your amount is below "
			<< m << " for the value to be Valid!\n";//User can imput number of players
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
	} 
	while (k>m);

	i = 0;
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
	listPrint(PlayerfirstName, PlayerlastName, PlayerPhone, PlayerAge, PlayerYearsPlayed,
		PlayerGoals, GoalsPerYear, k);

	return 0;
}

double calcSkill(int PlayerYearVal, double GPYVal)
{
	return(sqrt(GPYVal) + PlayerYearVal);
}

void listPrint(string fnames[], string lnames[], string phone[], int age[], int years[], double goals[], double gpy[], int arraysize)
{

	int n = 0;
	while (n < arraysize)
	{
		cout << "PLAYER NAME: " << fnames[n] << " " << lnames[n] <<
			"    AGE: " << age[n] << "     PHONE: " << phone[n] << "    YEARS PLAYED: " << years[n] <<
			"    GOALS PER YEAR: " << gpy[n] << "     Skill level: " << calcSkill(years[n], gpy[n]) << "\n";
		n++;
	}
	return;
}
