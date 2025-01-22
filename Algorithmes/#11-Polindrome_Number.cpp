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

int ReverseNumber(int Number)
{
    int Number2 = 0;

    while (Number != 0)
    {
        Number2 *= 10;
        Number2 += Number % 10;
        Number /= 10;
    }
    return Number2;
}

void isPolindrome(int Number)
{
    int Number2 = ReverseNumber(Number);
    if (Number == Number2)
        cout << Number << " is Polindrome";
    else
        cout << Number << " is not Polindrome";
}

int main()
{
    isPolindrome(ReadPositiveNumber("Please enter a positive number : "));
}