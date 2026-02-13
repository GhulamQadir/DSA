#include <iostream>
using namespace std;

int main()
{
    // PROBLEM: Given a string s consisting of words and spaces, return the
    // length of the last word in the string.
    string s;
    cout << "Enter your string: ";
    getline(cin, s);
    int i = s.length() - 1;
    string lastWord = "";
    while (i >= 0)
    {
        if (lastWord != "" && s[i] == ' ')
        {
            break;
        }
        else if (s[i] != ' ')
        {
            lastWord = s[i] + lastWord;
        }
        i--;
    }
    cout
        << "The last word is " << lastWord << " with length " << lastWord.length();
}