#include <iostream>
using namespace std;

int input_function(string value)
{
    int val;
    cout << "Enter " << value << ": ";
    cin >> val;
    return val;
}

int main()
{
    // Using double for base to support decimal results and large ranges
    double base = input_function("Base");
    int power = input_function("Power");

    double answer = 1;
    double x = base;

    // Use long long for the exponent to safely handle INT_MIN (-2147483648)
    // Converting it to positive would overflow a standard 32-bit int
    long long binary = power;

    // Handle Negative Exponents: x^-n is equal to (1/x)^n
    if (binary < 0)
    {
        x = 1 / x;    // Invert the base
        binary *= -1; // Make the power positive for the calculation
    }

    // Edge Case: If the base is 0, the result is always 0 (for positive powers)
    if (x == 0)
    {
        binary = 0;
        answer = 0;
    }

    // Binary Exponentiation Algorithm (O(log N) Time Complexity)
    while (binary > 0)
    {
        // If the current power is odd, multiply the answer by the current x
        // This corresponds to a '1' in the binary representation of the exponent
        int remainder = binary % 2;
        if (remainder == 1)
        {
            answer *= x;
        }

        // Repeatedly square the base (x^1 -> x^2 -> x^4 -> x^8...)
        x *= x;

        // Integer division by 2 effectively shifts to the next binary bit
        binary /= 2;
    }

    cout << "Answer: " << answer;
}