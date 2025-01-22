#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To)
{
//Function to generate a random number
int randNum = rand() % (To - From + 1) + From;
return randNum;
}

char generateRandomChar()
{
    return char(RandomNumber(65,90));
}

string generateWord()
{
    char Word[4];
    for (int i = 0; i < 4; i++)
    {
        Word[i] = generateRandomChar();
    }
    return Word;
}

string getRandomKey()
{
    string Key;
    for (int i = 0; i < 4; i++)
    {
        Key += generateWord();
        Key += '-';
    }
    Key[19] = '\0';

    return Key;
}

void getRandomKeys(int NumberOfKeys)
{
    for (int i = 0; i < NumberOfKeys; i++)
    {
        cout << "Key [" << i+1 << "] : " << getRandomKey() << endl;
    } 
}

int ReadPositiveNumber(string message)
{
    int Number;
    do
    {
        cout << message;
        cin >> Number;
        cout << endl;

    } while (Number <= 0);
    
    return Number;
}

int main()
{
    //Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    getRandomKeys(ReadPositiveNumber("Please Enter Number of Keys : "));

    return 0;
}