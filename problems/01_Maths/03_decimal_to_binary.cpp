#include <iostream>
using namespace std;

// Function to handle negative integers using 32-bit binary representation (2's complement logic)
void negative_to_binary(int n)
{
    int value = -n;
    for (int i = 31; i >= 0; i--)
    {
        // Shift bits to the right 'i' times and mask with 1 to extract the bit at that position
        int bit = (n >> i) & 1;
        cout << bit;
    }
}

// Function to convert positive decimal to binary format as an integer representation
void decimal_to_binary(int n)
{
    int binary = 0;
    int power = 1; // Used to place digits in correct units/tens/hundreds place
    while (n != 0)
    {
        int bit = n & 1;
        n = n >> 1;

        // Construct the binary number mathematically
        binary += bit * power;
        power *= 10;
    }
    cout << binary;
}

int main()
{
    // decimal to binary conversion
    int n;
    cout << "Enter decimal value: ";
    cin >> n;

    if (n < 0)
    {
        negative_to_binary(n);
    }
    else
    {
        decimal_to_binary(n);
    }
    return 0;
}