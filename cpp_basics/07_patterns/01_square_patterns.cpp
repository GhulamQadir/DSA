#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter any integer: ";
    cin >> n; // Size of pattern

    // Square number pattern (1 to n in each row)
    cout << "Square Patterns:\n";
    for (int i = 0; i <= n - 1; i++) // Controls rows

    {
        for (int j = 0; j <= n - 1; j++) // Controls columns
        {
            cout << j + 1 << " ";
        }
        cout << endl; // Move to next row
    }
    cout << endl;

    // Continuous number pattern (1 2 3, 4 5 6, ...)
    int start_num = 0;
    int end_num = start_num + 3;
    for (int y = 0; y < n; y++) // Rows
    {
        for (int z = start_num; z < end_num; z++) // Columns

        {
            cout << z + 1 << " ";
        }
        cout << endl;

        // Update range for next row
        start_num = end_num;
        end_num = start_num + 3;
    }
    cout << endl;

    // Character version of continuous pattern
    char ch = 'A';
    for (int i = 0; i < n; i++) // Rows
    {
        for (int j = 0; j < n; j++) // Columns
        {
            cout << ch << " ";
            ch++; // Move to next character
        }
        cout << endl;
    }
    return 0;
}