#include<iostream>
using namespace std;

int ReadPositiveNumber()
{
    int Number;
    do
    {
        cout << "Please enter a positive number : ";
        cin >> Number;
        cout << endl;

    } while (Number <= 0);
    
    return Number;
}

void PrintDigitsInReverseOrder(int Number)
{
    int Digits[10];
    int Counter = 0;

    while (Number != 0)
    {
        Digits[Counter] = Number % 10;
        Number /= 10;
        Counter++;
    }

    for (int i = 0; i < Counter; i++)
    {
        cout << Digits[i];
    }
}

int main()
{
    PrintDigitsInReverseOrder(ReadPositiveNumber());
    return 0;
}