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

bool isPrime(int Number)
{
    if (Number == 1)
        return true;

    int M = Number / 2;
    
    for (int i = 2; i < M; i++)
    {
        if (Number % i == 0)
            return false;
    }
    return true;
}

void PrintPrimeNumbersFrom1toN(int N)
{
    cout << "Prime Numbers from 1 to " << N << " :" << endl;

    for (int i = 1; i <= N; i++)
    {
        if(isPrime(i))
            cout << i << endl;
    } 
}

int main()
{
    PrintPrimeNumbersFrom1toN(ReadPositiveNumber());
    return 0;
}