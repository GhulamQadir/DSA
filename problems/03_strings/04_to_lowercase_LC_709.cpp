#include <iostream>
using namespace std;

int main()
{
    // Problem: Given a string s, return the string after replacing every
    // uppercase letter with the same lowercase letter
    string s;
    cout << "Enter your string: ";
    cin >> s;
    string lowercase = "";
    for (int i = 0; i < s.length(); i++)
    {
        int ascii = s[i];
        if (ascii < 65 || ascii > 90)
        {
            lowercase += s[i];
            continue;
        }
        lowercase += (s[i] + 32);
    }
    cout << lowercase;
}