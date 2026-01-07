#include <iostream>
using namespace std;

int main()
{
    cout << "Hollow Diamond Pattern\n";
    int n;
    cout << "Enter any integer: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int spaces = n - i - 1; // leading spaces before first '*'
        int print_star = false; // marks whether first star is printed

        // left half of upper diamond
        for (int j = 0; j < n; j++)
        {
            // print spaces until first star is reached
            if (spaces > 0 || print_star == true)
            {
                spaces--;
                cout << " ";
            }
            // print first star of the row
            else if (spaces == 0 && print_star == false)
            {
                cout << "*";
                print_star = true;
            }
        }

        // right half (second star of row), only from 2nd line onward
        if (i > 0)
        {
            // inner spaces between two stars
            int sp = i - 1;
            for (int k = 0; k < n - 1; k++)
            {
                if (sp > 0) // print inner spaces
                {
                    sp--;
                    cout << " ";
                }
                else // print second star
                {
                    cout << "*";
                    break;
                }
            }
        }
        cout << endl;
    }

    // lower half of hollow diamond
    for (int x = 0; x < n - 1; x++)
    {
        int space = x + 1; // leading spaces increase downward
        int print_star = false;

        // left star of lower diamond
        for (int j = 0; j < n; j++)
        {
            if (space > 0 || print_star) // print spaces before first star
            {
                cout << " ";
                space--;
            }
            else if (space == 0) // print first star
            {
                cout << "*";
                print_star = true;
            }
        }

        // right star of lower diamond
        int sp = n - x - 3; // inner space decreases downward

        for (int k = 0; k < n - 1; k++)
        {
            if (sp > 0) // inner gap space
            {
                cout << " ";
                sp--;
            }
            else if (sp == 0) // print second star
            {
                cout << "*";
                break;
            }
        }
        cout << endl;
    }

    cout << "Version 2 of Diamond Pattern\n";
    for (int i = 0; i < n; i++)
    {
        // spaces: n-i-1
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i > 0)
        {
            for (int k = 0; k < 2 * i - 1; k++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    // bottom part
    for (int i = 0; i < n - 1; i++)
    {
        // spaces: j+1
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        cout << "*";
        if (i != n - 2)
        {
            for (int k = 0; k < (2 * (n - 2 - i) - 1); k++)
            {
                cout << " ";
            }
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
