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

bool isPerfect(int Number)
{
    int Counter = Number / 2;
    int sum = 0;

    for (int i = 1; i <= Counter; i++)
    {
        if(isDivisor(Number, i))
            sum += i;
    }

    if (sum == Number)
        return true;
    else
        return false;
}

void PrintPerfectNumbersFrom1toN(int N)
{
    cout << "Perfect numbers from 1 to " << N << " : " << endl;

    for (int i = 1; i <= N; i++)
    {
        if(isPerfect(i))
            cout << i << endl;
    }
}

int main()
{
    PrintPerfectNumbersFrom1toN(ReadPositiveNumber());
    return 0;
}