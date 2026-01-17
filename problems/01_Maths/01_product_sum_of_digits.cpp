#include <iostream>
using namespace std;

int main()
{
    // Calculate the difference between the product and sum of digits of an integer
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    int product = 1;
    int sum = 0;
    while (n > 0)
    {
        // Get the last digit using modulo operator
        int remainder = n % 10;
        product *= remainder;
        sum += remainder;

        // Remove the last digit using integer division
        n /= 10;
    }
    cout << "Product of digits = " << product << endl;
    cout << "Sum of digits = " << sum << endl;
    cout << "Difference = " << product - sum;
    return 0;
}