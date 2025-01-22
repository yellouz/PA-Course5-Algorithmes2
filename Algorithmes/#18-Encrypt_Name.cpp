#include<iostream>
#include<string>
using namespace std;

string getname()
{
    string name;
    cout << "please enter your name : ";
    cin >> name;

    return name;
}

string EncryptName(string name, int EncryptionKey)
{
    for (int i = 0; i <= name.length(); i++)
    {
        name[i] = char((int)name[i] + EncryptionKey);
    } 
    return name;
}

string DecryptName(string name, int EncryptionKey)
{
    for (int i = 0; i <= name.length(); i++)
    {
        name[i] = char((int)name[i] - EncryptionKey);
    } 
    return name;
}

int main()
{
    string name = getname();
    int EncryptionKey = 2;
    cout << "encrypted name : " << EncryptName(name, EncryptionKey) << endl;
    
    return 0;
}