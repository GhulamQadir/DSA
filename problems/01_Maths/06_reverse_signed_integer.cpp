#include <iostream>
using namespace std;
#include <climits>

int main()
{
    // Reverse a 32-bit signed integer and return 0 if it overflows
    long long int num;
    cout << "Enter any signed integer: ";
    cin >> num;

    int reversed_num = 0;

    // Initial range check using 64-bit container (long long)
    if (num > INT_MAX | num < INT_MIN)
    {
        return 0;
    }
    else
    {
        while (num != 0)
        {
            int remainder = num % 10;

            // Critical Overflow Check:
            // Before multiplying by 10, ensure the result won't exceed INT_MAX/INT_MIN
            if (reversed_num > (INT_MAX / 10) || reversed_num < (INT_MIN / 10))
            {
                return 0;
            }
            reversed_num = (reversed_num * 10) + remainder;
            num /= 10;
        }
        cout << "Reversed Number: " << reversed_num << endl;
    }
    return 0;
}