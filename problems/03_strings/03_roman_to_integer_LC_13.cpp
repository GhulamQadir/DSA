#include <iostream>
using namespace std;

// Function to convert a Roman character to its corresponding integer value
int val_converter(char c)
{
    switch (c)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
       return -1; // Return -1 for any character that isn't a valid Roman numeral
    }
}

int main()
{
    // PROBLEM: Given a roman numeral, convert it to an integer.

    string roman_val;
    cout << "Enter Value in Roman: ";
    cin >> roman_val;

    int i = 0;
    int sum = 0;

    // Iterate through each character of the string
    while (i < roman_val.length())
    {
        int val = val_converter(roman_val[i]);

        // Basic Error Handling: If character is not a valid Roman numeral
        if (val == -1)
        {
            cout << "Invalid Value";
            return 0;
        }

        // Check if we are not at the last character (to look ahead for subtraction)
        if (i != roman_val.length() - 1)
        {
            // Error Handling: Catch invalid subtraction attempts (e.g., 'IC' or 'XM')
            // Roman rules only allow specific pairs for subtraction (IV, IX, XL, XC, CD, CM)
            if ((val == 1 || val == 10 || val == 100) && (roman_val[i + 1] == 'L' || roman_val[i + 1] == 'C' || roman_val[i + 1] == 'D' || roman_val[i + 1] == 'M'))
            {
                cout << "Invalid Value";
                return 0;
            }

            // Subtraction Rule: If a smaller value precedes a larger value (Specific pairs)
            if (val == 1 && (roman_val[i + 1] == 'V' || roman_val[i + 1] == 'X'))
            {
                sum -= 1; // Subtract 1 for cases like IV (4) or IX (9)
            }
            else if (val == 10 && (roman_val[i + 1] == 'L' || roman_val[i + 1] == 'C'))
            {
                sum -= 10; // Subtract 10 for cases like XL (40) or XC (90)
            }
            else if (val == 100 && (roman_val[i + 1] == 'D' || roman_val[i + 1] == 'M'))
            {
                sum -= 100; // Subtract 100 for cases like CD (400) or CM (900)
            }
            else
            {
                sum += val; // Standard addition for normal sequences (e.g., VI, XI)
            }
        }
        // Final character handling: Always add the value of the very last character
        if (i == roman_val.length() - 1)
        {
            sum += val;
        }
        i++;
    }
    cout << "\nInteger Value: "
         << sum;
}