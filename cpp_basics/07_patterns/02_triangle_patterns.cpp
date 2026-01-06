#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any integer: ";
    cin >> n; // Number of rows

    // Right-angled triangle using stars
    cout << "Triangle Patterns:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    cout << "\n";

    // Triangle with same number in each row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    // Triangle with increasing numbers per row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    // Reverse number triangle
    cout << "\n\n"
         << "Reverse Triangle Pattern\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    // Floyd's triangle (continuous numbers)
    cout << "\n\nFloyd's Triangle Pattern:\n";
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            num++; // Increase number continuously
            cout << num << " ";
        }
        cout << endl;
    }

    // Inverted triangle pattern
    cout << "\n\nInverted Triangle Pattern:\n";
    for (int i = 0; i < n; i++)
    {
        int space = i; // Number of leading spaces
        for (int j = 0; j < n; j++)
        {
            if (space > 0)
            {
                space--;
                cout << "  "; // Print space
            }
            else
            {
                cout << i + 1 << " "; // Print number
            }
        }
        cout << endl;
    }

    // Pyramid number pattern
    cout << "\n\nPyramid Pattern:\n";
    for (int i = 0; i < n; i++) // Rows
    {
        // Print leading spaces
        for (int sp = 0; sp <= n - 1 - i; sp++)
        {
            cout << "  ";
        }
        // Print left side numbers
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }

        // Print right side numbers
        for (int k = i; k > 0; k--)
        {
            cout << k << " ";
        }
        cout << endl;
    }

    return 0;
}