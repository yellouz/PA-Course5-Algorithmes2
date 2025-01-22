#include<iostream>
using namespace std;

void checkPassword(string password)
{
    string word;
    int counter = 0;

    for (int i = 65; i <= 90; i++)
    {
        for (int j = 65; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                word += char(i);
                word += char(j);
                word += char(k);
                counter++;

                cout << "Tial [" << counter << "] : " << word << endl;
                if (word == password)
                {
                    cout << endl;
                    cout << "Password : " << password << " found after " << counter << " trials";
                    return;
                }

                word = "";
            }
            
        }
        
    }
    
}

int main()
{
    checkPassword("FFA");
    return 0;
}