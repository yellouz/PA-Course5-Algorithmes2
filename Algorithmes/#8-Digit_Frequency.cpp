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

int FrequencyOfDigit(int Number, int Digit)
{
    int frequency = 0;

    while (Number != 0)
    {
        if(Digit == Number % 10)
            frequency++;
        
        Number /= 10;
    }
    return frequency;
}

int main()
{
    int Number = ReadPositiveNumber("please enter a positive number : ");
    short Digit = ReadPositiveNumber("please enter one digit : ");

    int frequency = FrequencyOfDigit(Number, Digit);

    cout << "frequency = " << frequency;

    return 0;
}