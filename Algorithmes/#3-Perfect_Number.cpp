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

bool isDivisor(int Number, int Divisor)
{
    if (Number % Divisor == 0)
    {
        return true;
    }
    return false;
}

void isPerfect(int Number)
{
    int Counter = Number / 2;
    int sum = 0;

    for (int i = 1; i <= Counter; i++)
    {
        if(isDivisor(Number, i))
            sum += i;
    }

    if (sum == Number)
        cout << Number << " is Perfect" << endl;
    else
        cout << Number << " is not Perfect" << endl;
}

int main()
{
    isPerfect(ReadPositiveNumber());
    return 0;
}