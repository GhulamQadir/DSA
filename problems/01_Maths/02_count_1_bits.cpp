#include <iostream>
using namespace std;

int main()
{
    // Count the number of set bits (1s) in the binary representation of an unsigned integer
    unsigned int n;
    cout << "Enter an unsigned integer: ";
    cin >> n;
    short ones_bits = 0;
    while (n != 0)
    {
        // Bitwise AND with 1 checks if the Least Significant Bit (LSB) is 1
        if (n & 1)
        {
            ones_bits++; // like this:  0000101
                         //          &  0000001
        }
        // Right shift the bits by 1 position to process the next bit
        n = n >> 1;
    }
    cout << ones_bits;
    return 0;
}