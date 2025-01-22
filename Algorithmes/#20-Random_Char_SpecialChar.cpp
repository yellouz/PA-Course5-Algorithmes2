#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum enCharType { SmallLetter = 1, CapitalLetter, SpecialCharacter, Digit };

int RandomNumber(int From, int To)
{
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

char getRandomChar(enCharType Choice)
{
    // switch case would be better
    if(Choice == enCharType::SmallLetter)
    {
        return char(RandomNumber(97,122));
    }
    else if(Choice == enCharType::CapitalLetter)
    {
        return char(RandomNumber(65,90));
    }
    else if(Choice == enCharType::SpecialCharacter)
    {
        return char(RandomNumber(33,47));
    }
    else if(Choice == enCharType::Digit)
    {
        return char(RandomNumber(48,57));
    }
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    cout << getRandomChar(enCharType::SmallLetter) << endl;
    cout << getRandomChar(enCharType::CapitalLetter) << endl;
    cout << getRandomChar(enCharType::SpecialCharacter) << endl;
    cout << getRandomChar(enCharType::Digit) << endl;

    return 0;
}