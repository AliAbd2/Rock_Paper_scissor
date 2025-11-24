#include <iostream>
#include <cmath>
#include <string>

using namespace std;

enum enRockPaperScissor { Rock = 1, Paper = 2, Scissor = 3 };

enum enWhoWin { PlayerWin = 1, ComputerWin = 2, Draw = 0 };

int ReadNumber(string Message, int From, int To)
{
	int Num;
	do 
	{

		cout << Message << endl;
		cin >> Num;

	} while (Num <= From && Num >= To);

	return Num;
}

int RandomNumber(int From, int To)
{

	return rand() % (To - From + 1) + From;

}

int WhoWin(int PlayerChoice, int ComputerChoice)
{

	if (PlayerChoice == enRockPaperScissor::Rock && ComputerChoice == enRockPaperScissor::Scissor)
	{
		return enWhoWin::PlayerWin;
	}
	else if (PlayerChoice == enRockPaperScissor::Rock && ComputerChoice == enRockPaperScissor::Paper)
	{
		return enWhoWin::ComputerWin;
	}
	else if (PlayerChoice == enRockPaperScissor::Paper && ComputerChoice == enRockPaperScissor::Rock)
	{
		return enWhoWin::PlayerWin;
	}
	else if (PlayerChoice == enRockPaperScissor::Paper && ComputerChoice == enRockPaperScissor::Scissor)
	{
		return enWhoWin::ComputerWin;
	}
	else if (PlayerChoice == enRockPaperScissor::Scissor && ComputerChoice == enRockPaperScissor::Paper)
	{
		return enWhoWin::PlayerWin;
	}
	else if (PlayerChoice == enRockPaperScissor::Scissor && ComputerChoice == enRockPaperScissor::Rock)
	{
		return enWhoWin::ComputerWin;
	}
	else
	{
		return enWhoWin::Draw;
	}
}

string PlayerChoiceAsString(int PlayerChoice)
{
	if (PlayerChoice == enRockPaperScissor::Paper)
	{
		return "Paper";
	}
	else if (PlayerChoice == enRockPaperScissor::Rock)
	{
		return "Rock";
	}
	else
	{
		return "Scissor";
	}

}

string ComputerChoiceAsString(int ComputerChoise)
{
	if (ComputerChoise == enRockPaperScissor::Paper)
	{
		return "Paper";
	}
	else if (ComputerChoise == enRockPaperScissor::Rock)
	{
		return "Rock";
	}
	else
	{
		return "Scissor";
	}

}

int RoundResult(int RoundNumber)
{
	cout << "\t\tRound [" + to_string(RoundNumber) + "] begins:\n" << endl;

	int PlayerChoice = ReadNumber("Please enter your choice: [1]:Rock, [2]:Paper, [3]:Scissor ?", 1, 3);
	int ComputerChoise = RandomNumber(1, 3);

	if (WhoWin(PlayerChoice, ComputerChoise) == enWhoWin::PlayerWin)
	{
		cout << "____________Round [" + to_string(RoundNumber) + "] ____________\n" << endl;
		cout << "Player choice  : " << PlayerChoiceAsString(PlayerChoice) << endl;
		cout << "Computer choice: " << ComputerChoiceAsString(ComputerChoise) << endl;
		cout << "Round Winner   : [Player] " << endl << endl;
		cout << "__________________________________\n";
		system("color 2F");
		
		return enWhoWin::PlayerWin;
	}
	else if (WhoWin(PlayerChoice, ComputerChoise) == enWhoWin::ComputerWin)
	{
		cout << "____________Round [" + to_string(RoundNumber) + "] ____________\n" << endl;
		cout << "Player choice  : " << PlayerChoiceAsString(PlayerChoice) << endl;
		cout << "Computer choice: " << ComputerChoiceAsString(ComputerChoise) << endl;
		cout << "Round Winner   : [Computer] " << endl << endl;
		cout << "__________________________________\n\a";
		system("color 4F");

		return enWhoWin::ComputerWin;
	}
	else
	{
		cout << "____________Round [" + to_string(RoundNumber) + "] ____________\n" << endl;
		cout << "Player choice  : " << PlayerChoiceAsString(PlayerChoice) << endl;
		cout << "Computer choice: " << ComputerChoiceAsString(ComputerChoise) << endl;
		cout << "Round Winner   : [No winner] " << endl << endl;
		cout << "__________________________________\n";
		system("color 6F");

		return enWhoWin::Draw;
	}
}

void FinaleResul()
{
	char PlayMore = ' ';
	
	do
	{
		int NumberOfRounds = ReadNumber("Please enter the number of rounds you want to play: ", 1, 100);

		int PlaterWins = 0, ComputerWins = 0;

		for (int x = 1; x <= NumberOfRounds; x++)
		{

			switch (RoundResult(x))
			{
			case enWhoWin::PlayerWin:
				PlaterWins++;
				break;
			case enWhoWin::ComputerWin:
				ComputerWins++;
				break;
			}

		}

		cout << "\t\t\t__________________________________________________________\n\n";
		cout << "\t\t\t\t\t+++ G a m e O v e r +++\n\n";
		cout << "\t\t\t__________________________________________________________\n\n";
		cout << "\t\t\t____________________ [ Game Result ] _____________________\n\n";
		cout << "\t\t\tGame Rounds       : " << NumberOfRounds << endl;
		cout << "\t\t\tPlayer win times  : " << PlaterWins << endl;
		cout << "\t\t\tComputer win times: " << ComputerWins << endl;
		cout << "\t\t\tDraw times        : " << NumberOfRounds - PlaterWins - ComputerWins << endl;
		if (PlaterWins > ComputerWins)
			cout << "\t\t\tFinal winner      : Player" << endl;
		else if (PlaterWins < ComputerWins)
			cout << "\t\t\tFinal winner      : Computer" << endl;
		else
			cout << "\t\t\tFinal winner      : Non" << endl;
		cout << "\t\t\t__________________________________________________________\n\n";




		cout << "\nDo you want to play again? Y/N";
		cin >> PlayMore;

	} while (PlayMore == 'Y' || PlayMore == 'y');

}

int main()
{
	srand((unsigned)time(NULL));
	FinaleResul();

}