#include <iostream>
using namespace std;
#include <climits>

int main()
{
    // PROBLEM: Given an integer x, return true if x is a palindrome, and false otherwise.

    int num;
    cout << "Enter any integer: ";
    cin >> num;

    int temp = num;
    int palindrome = 0;
    if (num < 0)
    {
        return false;
    }

    while (temp != 0)
    {
        if (palindrome > (INT_MAX / 10) || palindrome < (INT_MIN / 10))
        {
            return 0;
        }

        int remainder = temp % 10;
        palindrome = (palindrome * 10) + remainder;
        temp /= 10;
    }
    if (palindrome == num)
    {
        cout << num << " is a palindrome number";
        return true;
    }
    cout << num << " is not a palindrome number";
    return false;
}