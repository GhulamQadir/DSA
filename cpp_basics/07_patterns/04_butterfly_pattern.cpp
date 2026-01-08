#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any integer: ";
    cin >> n;

    cout << "Butterfly Pattern\n";

    // UPPER HALF
    for (int i = 0; i < n; i++)
    {
        // left wing stars
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }

        // spaces between wings (first half)
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << "  ";
        }
        // spaces between wings (second half — same as above)
        for (int k = 0; k < n - i - 1; k++)
        {
            cout << "  ";
        }

        // right wing stars
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }

    // LOWER HALF
    for (int i = n; i > 0; i--)
    {
        // left wing stars (decreasing)
        for (int j = 0; j < i; j++)
        {
            cout << "* ";
        }

        // spaces between wings (increasing)
        for (int k = 0; k < n - i; k++)
        {
            cout << "  ";
        }
        // same spaces again
        for (int k = 0; k < n - i; k++)
        {
            cout << "  ";
        }

        // right wing stars (decreasing)
        for (int n = 0; n < i; n++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}