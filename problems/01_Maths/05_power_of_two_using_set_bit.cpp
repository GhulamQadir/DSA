#include <iostream>
using namespace std;

int main()
{
    // Verify if a number is a power of 2.
    // In binary, power of 2 numbers always have exactly one bit set to '1'.
    int n;
    cout << "Enter any integer: ";
    cin >> n;

    // Use a copy to avoid modifying the original 'n'
    int bit_value = n;
    int set_bit_count = 0;

    // Zero and negative numbers are not considered powers of 2 in this context
    while (bit_value != 0)
    {
        if (bit_value & 1)
        {
            set_bit_count++;
        }
        bit_value = bit_value >> 1;
    }
    // If exactly one bit was set, it's a power of 2
    if (set_bit_count == 1)
    {
        cout << n << " is a power of 2";
    }
    else
    {
        cout << n << " is not a power of 2";
    }
}