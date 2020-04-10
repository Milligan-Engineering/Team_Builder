//File Name: Team Builder
//Name: Tyler Oakes
//Email Address: tsoakes@my.milligan.edu
//Term Project
//Description: This program helps organize players into teams using statistics.
//Version Version 2.10a
//Last Changed: 04/08/2020

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int numberofteams = 2, PlayersPerTeam = 10, m = 5;//m is the maximum amount of players the league can hold
string fname[numberofteams][PlayersPerTeam], lname[numberofteams][PlayersPerTeam], phone[numberofteams][PlayersPerTeam];
int age[numberofteams][PlayersPerTeam], years[numberofteams][PlayersPerTeam];
double GPY[numberofteams][PlayersPerTeam], Skill[numberofteams][PlayersPerTeam];

void listPrint(string fnames[], string lnames[], string phone[], int age[], int years[], double gpy[], double calcskill[], int arraysize);
//Precondition: User has Entered input for strings First Name, Last Name, Phone Number. Intergers 
//of Age, Years Played. The double of years scored.
//Postcondition: It will list all the input in single lines readable for the user.

double calcSkill (int PlayerYearVal, double GPYVal);
//Precondition: User has Entered number of years played and goals made both as intergers.
//Postcondition: The program will have performed a calculation converting yearsplayed and 
//goalsscored to a double. It will output a double to be used as the skill player metric 
//to be ranked with as a double.

int search(string a[], int number_used, string term);
//Precondition: number_used is <= the declared size of a.
//Also, a[0] through a[number_used − 1] have values.
//Returns the first index such that a[index] == target,
//provided there is such an index; otherwise, returns −1. 

int main()
{
	string PlayerfirstName[m], PlayerlastName[m], PlayerPhone[m];
	int	PlayerAge[m], PlayerYearsPlayed[m], i, n;
	double PlayerGoals[m], GoalsPerYear[m];
	char Menu;

	cout << "Welcome to the Team Builder Program.\n";

	do
	{
		cout << "Will you be entering Player Information,"
			" Reviewing Information, Searching for a Player or Editing Information?\n"
			"Enter N for Enter, R for Reviewing,"
			" E for Editing (Not working yet), S for searching, or D if you are done!\n";
		cin.get(Menu);

		if (Menu == 'N' || Menu == 'n')//If loop if the user is entering data
		{
			ofstream out_stream;
			out_stream.open("PlayerInfo.txt");
			if (out_stream.fail())
			{
				cout << "Output file opening failed.\n";
				exit(1);
			}

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

				} while (error == 1);
			} while (k > m);
			n = k;
			i = 0;
			while (i < n)// This is the while Loop where the user will input all the user information
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
				} while (error == 1);


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
				} while (error == 1);

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
					} while (error == 1);

					cout << "\n";
					GoalsPerYear[i] = PlayerGoals[i] / PlayerYearsPlayed[i];
				}
				i++;
			}
			i = 0;
			if (i < n)// If loop for outputing data to the external file
			{

				out_stream << " " << PlayerfirstName[i] << " " << PlayerlastName[i] <<
					" " << PlayerAge[i] << " " << PlayerPhone[i] <<
					" " << PlayerYearsPlayed[i] << " " << GoalsPerYear[i] <<
					" " << calcSkill(PlayerYearsPlayed[i], PlayerGoals[i]) << "\n";
				i++;
			}

			out_stream.close();

			continue;
		}

		if (Menu == 'R' || Menu == 'r')// If the user is just reviewing data
		{
			ifstream in_stream;
			in_stream.open("PlayerInfo.txt");

			if (in_stream.fail())
			{
				cout << "Input file opening failed.\n";
				exit(1);
			}

			string firstName[m], lastName[m], Phone[m], PlayerNumber[m];
			int	Age[m], YearsPlayed[m],q;
			double Skill[m], GoalsPYear[m];

			if (in_stream.is_open())
			{
				i = 0;
				while(!in_stream.eof() && i < m)  
				{
					in_stream >> firstName[i] >> lastName[i] >> Age[i]
						>> Phone[i] >> YearsPlayed[i] >> GoalsPYear[i]
						>> Skill[i];
					i++;
				}
				q = i - 1;
			}
			listPrint(firstName, lastName, Phone, Age, YearsPlayed, GoalsPYear, Skill, q);
			in_stream.close();
			continue;
		}
		
		if (Menu == 'S' || Menu == 's')
		{
			ifstream in_stream;
			in_stream.open("PlayerInfo.txt");

			if (in_stream.fail())
			{
				cout << "Input file opening failed.\n";
				exit(1);
			}

			string firstName[m], lastName[m], Phone[m], PlayerNumber[m], term;
			int	Age[m], YearsPlayed[m], result;
			double Skill[m], GoalsPYear[m];

			if (in_stream.is_open())
			{
				for (i = 0; i < m; ++i)//for  
				{
					in_stream >> firstName[i] >> lastName[i] >> Age[i]
						>> Phone[i] >> YearsPlayed[i] >> GoalsPYear[i]
						>> Skill[i];
				}
			}
			char ans;
			do
			{
				cout << "Enter a last name to search for: ";
				cin >> term;
				result = search(lastName, m, term);
				if (result == 1)
					cout << term << " is not on the list.\n";
				else
					cout << term << " is stored in array position "
					<< result << endl
					<< "(Remember: The first position is 0.)\n";
				cout << "Search again?(y/n followed by Return): ";
				cin >> ans;
			} while ((ans != 'n') && (ans != 'N'));
			continue;
		}
		if (Menu == 'D' || Menu == 'd')
		{
			Menu = 'D';
			return 0;
		}
		else// Else loop for incase the user does not input a valid answer asked
		{
			cout << "\nEnter a N, R, or D please! \n";
				continue;
		}
	} 
	while (Menu != 'D' || Menu != 'd');// Once the user is done they will enter D
	return 0;
}

double calcSkill(int PlayerYearVal, double GPYVal)
{
	return(sqrt(GPYVal) + PlayerYearVal);
}

void listPrint(string fnames[], string lnames[], string phone[], int age[], int years[], 
	double gpy[], double calcskill[], int arraysize)
{

	int n = 0;
	while (n < arraysize)
	{
		cout << "PLAYER NAME: " << setw(10) << fnames[n] << " " << setw(10) << lnames[n] <<
			" AGE: " << setw(3) << setprecision(2) << age[n] << " PHONE: " << setw(10) << phone[n] <<
			" YEARS PLAYED: " << setw(3) << years[n] << " GOALS PER YEAR: " << setw(4) << setprecision(3) <<
			gpy[n] << " Skill level: " << setprecision(3) << calcskill[n] << "\n\n";
		n++;
	}
	return;
}

int search(string a[], int number_used, string term)
{
	int q = 0;
	bool found = false;
	while ((!found) && (q < number_used))
		if (term == a[q])
			found = true;
		else
			q++;
	if (found)
		return q;
	else 
		return 1;
}
