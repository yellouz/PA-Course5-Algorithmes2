#include<iostream>
using namespace std;

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

void PrintInvertedNumber(int Number)
{
    while(Number != 0)
    {
        for (int i = 0; i < Number; i++)
        {
            cout << Number;
        }
        cout << endl;
        Number--;
    }
}

int main()
{
    PrintInvertedNumber(ReadPositiveNumber("Please enter a positive number : "));
    return 0;
}