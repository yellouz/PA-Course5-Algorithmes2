#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };

enum enScore { Win = 1, Lose = 2, Draw = 3};

struct stGame
{
    int Rounds = 0;
    int PlayerWonTimes = 0;
    int ComputerWonTimes = 0;
    int DrawTimes = 0;
    string FinalWinner = "";
};

int GetNumberOfRounds()
{
    int Rounds;

    do
    {
        cout << "Choose Number of Rounds (1 to 10) : ";
        cin >> Rounds;
        cout << endl;

    } while ((Rounds < 1) || (Rounds > 10));
    
    return Rounds;
}

enChoice GetUserChoice()
{
    int Choice;

    do
    {
        cout << "Your Choice: [1]:Rock, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;
        cout << endl;

    } while ((Choice < 1) || (Choice > 3));
    
    return enChoice(Choice);
}

int GenerateRandomNumber(int From, int To)
{
    //Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

enChoice GetComputerChoice()
{
    return enChoice(GenerateRandomNumber(1,3));
}

enScore CompareChoices(enChoice UserChoice, enChoice ComputerChoice)
{
    if (UserChoice == enChoice::Rock)
    {
        switch (ComputerChoice)
        {
            case enChoice::Rock :
                return enScore::Draw;

            case enChoice::Paper :
                return enScore::Lose;

            case enChoice::Scissors :
                return enScore::Win;

            default:
            break;
        }
    }
    else if(UserChoice == enChoice::Paper)
    {
        switch (ComputerChoice)
        {
            case enChoice::Rock :
                return enScore::Win;

            case enChoice::Paper :
                return enScore::Draw;

            case enChoice::Scissors :
                return enScore::Lose;

            default:
            break;
        }
    }
    else if (UserChoice == enChoice::Scissors)
    {
        switch (ComputerChoice)
        {
            case enChoice::Rock :
                return enScore::Lose;

            case enChoice::Paper :
                return enScore::Win;

            case enChoice::Scissors :
                return enScore::Draw;

            default:
            break;
        }
    }
}

string ChoiceToWord(enChoice Choice)
{
    switch (Choice)
    {
    case enChoice::Rock :
        return "Rock";

    case enChoice::Paper :
        return "Paper";

    case enChoice::Scissors :
        return "Scissors";
        
    default:
        break;
    }
}

void DisplayScore(enScore Score, int RoundNumber, enChoice UserChoice, enChoice ComputerChoice, stGame &Game)
{
    string RoundWinner;

    switch (Score)
        {
        case enScore::Draw:
            system("Color 6F"); //turn screen into yellow
            RoundWinner = "[No Winner]";
            Game.DrawTimes++;
            break;

        case enScore::Win:
            system("Color 2F"); //turn screen into green
            RoundWinner = "Player";
            Game.PlayerWonTimes++;
            break;
        
        case enScore::Lose:
            system("Color 4F"); //turn screen into red
            cout << "\a"; // play sound
            RoundWinner = "Computer";
            Game.ComputerWonTimes++;
            break;
        
        default:
            break;
        }

    cout << endl;
    cout << "__________________";
    cout << "Round [" << RoundNumber << "]";
    cout << "__________________" << endl;
    cout << endl;

    cout << "Player Choice:   " << ChoiceToWord(UserChoice) << endl;
    cout << "Computer Choice: " << ChoiceToWord(ComputerChoice) << endl;
    cout << "Round Winner :   " << RoundWinner << endl;

    cout << endl;
    cout << "__________________";
    //cout << "Round []";
    cout << "_________";
    cout << "__________________" << endl;
    cout << endl << endl;
}

void GameOver(stGame Game)
{
    cout << endl;
    cout << "\t\t__________________________________________________" << endl << endl;
    cout << "\t\t\t +++ G a m e  O v e r +++" << endl << endl;
    cout << "\t\t__________________________________________________" << endl << endl;
    cout << "\t\t______[Game Results]________" << endl << endl;
    
    cout << "\t\tGame Rounds:         " << Game.Rounds << endl;
    cout << "\t\tPlayer won times:    " << Game.PlayerWonTimes << endl;
    cout << "\t\tComputer won times:  " << Game.ComputerWonTimes << endl;
    cout << "\t\tDraw times:          " << Game.DrawTimes << endl;
    cout << "\t\tFinal Winner:   " << Game.FinalWinner << endl;

    cout << endl;
    cout << "\t\t__________________________________________________" << endl << endl;
}

string FinalWinner(stGame &Game)
{
    if (Game.PlayerWonTimes == Game.ComputerWonTimes)
        return "No Winner";
    else if (Game.PlayerWonTimes > Game.ComputerWonTimes)
        return "Player";
    else
        return "Computer";
}

stGame PlayGame(int Rounds)
{
    enChoice UserChoice;
    enChoice ComputerChoice;
    enScore Score;
    stGame Game;
    Game.Rounds = Rounds;

    for (int i = 1; i <= Rounds; i++)
    {
        cout << "Round [" << i << "] begins : " << endl;
        cout << endl;

        UserChoice = GetUserChoice();
        ComputerChoice = GetComputerChoice();

        Score = CompareChoices(UserChoice, ComputerChoice);
        DisplayScore(Score, i, UserChoice, ComputerChoice, Game);
    }
    Game.FinalWinner = FinalWinner(Game);
    return Game;
}

void StartGame()
{
    char PlayAgain = 'y';

    do
    {
        system("cls"); // clear screen
        system("Color 0F"); 

        stGame Game = PlayGame(GetNumberOfRounds());
        GameOver(Game);

        cout << "Do you Want to Play again? [Y/N] : ";
        cin >> PlayAgain;

    } while ((PlayAgain == 'Y') || (PlayAgain == 'y'));
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    StartGame();


    return 0;
}