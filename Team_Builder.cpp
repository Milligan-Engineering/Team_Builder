//File Name: Team Builder
//Name: Tyler Oakes
//Email Address: tsoakes@my.milligan.edu
//Term Project
//Description: This program helps organize players into teams using statistics.
//Version Version 3
//Last Changed: 05/06/2020

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int numberofteams = 2, PlayersPerTeam = 10, LEAGUEMAX = 20;//m is the maximum amount of players the league can hold
//string teams;
int n;

struct TeamInfo
{
	string teamname[numberofteams];
	string coachName;
};

class playerinfo
{
public:
	int search(string a[], int number_used, string term);
	//Precondition: number_used is <= the declared size of a.
	//Also, a[0] through a[number_used − 1] have values.
	//Returns the first index such that a[index] == target,
	//provided there is such an index; otherwise, returns −1. 

	int skillRanker(double Skill[], int Rank[], int Size);
	//Preconditions: Skill values are stored in Skill (double) and the rank is stored in Rank (0 first, 1 second, ...)
	//				The size of the arrays are stored in Size
	//Postcondition: The array Rank holds index of the smallest value in its 0 index, the second smallest in 1 ...

	string fname[LEAGUEMAX];
	string lname[LEAGUEMAX];
	string phone[LEAGUEMAX];
	int age[LEAGUEMAX]; 
	int years[LEAGUEMAX];
	double GPY[LEAGUEMAX];
	double Skill[LEAGUEMAX];
	int Rank[LEAGUEMAX];

};

void listPrint(string fnames[], string lnames[], string phone[], int age[], int years[], double gpy[], double calcskill[], int arraysize);
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
	playerinfo Player;
	int i, PlayerGoals[LEAGUEMAX];
	char Menu;

	cout << "Welcome to the Team Builder Program.";

	do
	{
		cout << "\nWill you be entering Player Information,"
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

			int error, NPLAYER;// NPLAYER = number of players user has to enter;
			do// Do while to make sure that the desired number of players is not bigger than the array size
			{
				do// Do While to validate imput
				{
					error = 0;
					cout << "How many players do you have to enter?\nMake sure your amount is below "
						<< LEAGUEMAX << " for the value to be Valid!\n";//User can imput number of players
					cin >> NPLAYER;

					if (cin.fail() || NPLAYER < 0)
					{
						cout << "Please enter a valid positive integer\n" << endl;
						error = 1;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

				} while (error == 1);
			} while (NPLAYER > LEAGUEMAX);
			n = NPLAYER;
			i = 0;
			while (i < n)// This is the while Loop where the user will input all the user information
			{
				cout << "\nPlease Enter Player Information\n";
				cout << "\nEnter Player First Name: ";
				cin >> Player.fname[i];
				cout << "Enter Player Last Name: ";
				cin >> Player.lname[i];
				cout << "Please Enter Player's Phone Number: ";
				cin >> Player.phone[i];

				do
				{
					error = 0;
					cout << "Enter Player Age: ";
					cin >> Player.age[i];

					if (cin.fail() || Player.age[i] < 0)
					{
						cout << "Please enter a valid positive integer\n" << endl;
						error = 1;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				} while (error == 1);

				do
				{
					error = 0;
					cout << "Enter Number Of Years Played: ";
					cin >> Player.years[i];

					if (cin.fail() || Player.years[i] < 0)
					{
						cout << "Please enter a valid integer greater than or equal to 0\n" << endl;
						error = 1;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
				} while (error == 1);

				if (Player.years[i] > 0)//If loop for if first time player it won't ask for Goals scored
				{

					do
					{
						error = 0;
						cout << "How Many Goals has the Player Previously Scored: ";
						cin >> PlayerGoals[i];

						if (cin.fail() || PlayerGoals[i] < 0)
						{
							cout << "Please enter a valid positive number" << endl;
							error = 1;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
					} while (error == 1);

					cout << "\n";
					Player.GPY[i] = PlayerGoals[i] / Player.years[i];
					Player.Skill[i] = calcSkill(Player.years[i], PlayerGoals[i]);
				}
				i++;
			}

			Player.skillRanker(Player.Skill, Player.Rank, n);

			i = 0;
			do // while loop for outputing data to the external file
			{
				Player.Rank[i] = i;

				out_stream << " " << Player.Rank[i] << " " << Player.fname[i] << " " << Player.lname[i] <<
					" " << Player.age[i] << " " << Player.phone[i] <<
					" " << Player.years[i] << " " << Player.GPY[i] <<
					" " << calcSkill(Player.years[i], PlayerGoals[i]) << "\n";
				i++;
			} while ((i < n));
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

			int q;
			playerinfo Player;

			if (in_stream.is_open())
			{
				i = 0;
				while(!in_stream.eof() && i < LEAGUEMAX)  
				{
					in_stream >> Player.Rank[i] >> Player.fname[i] >> Player.lname[i] >> Player.age[i]
						>> Player.phone[i] >> Player.years[i] >> Player.GPY[i]
						>> Player.Skill[i];
					i++;
				}
				q = i - 1;
			}
			listPrint(Player.fname, Player.lname, Player.phone, Player.age, Player.years, Player.GPY, Player.Skill, q);
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

			string term;
			int	result;
			playerinfo Player;

			if (in_stream.is_open())
			{
				for (i = 0; i < LEAGUEMAX; ++i)//for  
				{
					in_stream >> Player.fname[i] >> Player.lname[i] >> Player.age[i]
						>> Player.phone[i] >> Player.years[i] >> Player.GPY[i]
						>> Player.Skill[i];
				}
			}
			char ans;
			do
			{
				cout << "Enter a last name to search for: ";
				cin >> term;
				result = Player.search(Player.lname, n, term);
				if (result == 1)
					cout << term << " is not on the list.\n";
				else
					cout << term << " is stored in array position "
					<< result << endl
					<< "(Remember: The first position is 0.)\n"
					<< "The player info is: \nName: " << Player.fname[result] << " " <<
					Player.lname[result] << " Age: " << Player.age[result] << " Phone: " << Player.phone[result]
					<< " Years Played: " << Player.years[result] << " Goals Per Year: " << Player.GPY[result]
					<< " Skill Level: " << Player.Skill[result] << endl;
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
		cout << "RANK: " << setw(3) << "PLAYER NAME: " << setw(10) << fnames[n] << " " << setw(10) << lnames[n] <<
			" AGE: " << setw(3) << setprecision(2) << age[n] << " PHONE: " << setw(10) << phone[n] <<
			" YEARS PLAYED: " << setw(3) << years[n] << " GOALS PER YEAR: " << setw(4) << setprecision(3) <<
			gpy[n] << " Skill level: " << setprecision(3) << calcskill[n] << "\n\n";
		n++;
	}
	return;
}

int playerinfo::search(string a[], int number_used, string term)
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

int playerinfo::skillRanker(double Skill[], int Rank[], int Size)
{
	int temp;
	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = 0; j < Size - i - 1; j++)
		{
			if (Skill[Rank[j]] > Skill[Rank[j + 1]])
			{
				temp = Rank[j];
				Rank[j] = Rank[j + 1];
				Rank[j + 1] = temp;
			}
		}
	}
	return(0);
}