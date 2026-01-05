#include <iostream>
using namespace std;

int main()
{
    // Demonstrating conditional statements (if-else)
    cout << "Conditional Statements(if-else)\n";
    int num;
    cout << "Enter any number: ";
    cin >> num;

    // Check whether number is positive, negative or zero
    if (num > 0)
    {
        cout << "Number is positive";
    }
    else if (num < 0)
    {
        cout << "Number is negative";
    }
    else
    {
        cout << "Number is zero";
    }

    // Same logic using ternary operator
    cout << "\n\nNow using Ternary statements\n";

    // Nested ternary to handle multiple conditions
    string result = num > 0 ? "Positive" : num < 0 ? "Negative"
                                                   : "Zero";
    cout << "Ternary Result = " << result;

    return 0;
}