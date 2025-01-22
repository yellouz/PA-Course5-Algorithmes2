#include<iostream>
using namespace std;

void print_header()
{

    cout << "\n\n\t\t\t Multipliaction Table From 1 to 10\n\n";
    
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << endl;
    cout << "___________________________________________________________________________________________";
    cout << endl;
}

string separator(int i)
{
    if(i < 10)
        return "    |  ";
    else
        return "   |  ";
}

void print_body()
{
    for (int i = 1; i <= 10; i++)
    {
        //cout << i << "    |  ";    problem with 10
        cout << i << separator(i);

        for(int j = 1; j <= 10; j++)
        {
            cout << i*j << "\t";
        }
        cout << endl;
    }
}

void print_mult_table()
{
    print_header();
    print_body();
}

int main()
{   
    print_mult_table();
    return 0;
}
