#include <iostream>
using namespace std;

int main()
{
    cout << "BitWise Operators\n";

    // 1) Bitwise AND  (&)
    // -------------------------
    // Result bit = 1 only when BOTH bits are 1
    // Example:
    // 4  = 0100
    // 8  = 1000
    //            AND
    //      0000  = 0
    // ____
    // 0000
    cout << "\n1)Bitwise AND:\n";
    cout << (4 & 8) << endl;
    cout << (6 & 10); // 6=0110 , 10=1010 -> 0010 = 2

    // 2) Bitwise OR  (|)
    // Result bit = 1 if AT LEAST ONE bit is 1
    // Example:
    // 4  = 0100
    // 8  = 1000
    //             OR
    //      1100 = 12
    cout << "\n\n2)Bitwise OR:\n";
    cout << (4 | 8) << endl;
    cout << (6 | 10); // 0110 | 1010 = 1110 = 14

    // 3) Bitwise XOR (^)
    // Result bit = 1 when bits are DIFFERENT
    // Example:
    // 3 = 0011
    // 7 = 0111
    //            XOR
    //     0100 = 4
    cout << "\n\n3)Bitwise XOR:\n";
    cout << (3 ^ 7) << endl;
    cout << (6 ^ 10); // 0110 ^ 1010 = 1100 = 12

    // 4) Left Shift (<<)
    // Shifts bits to the LEFT and fills with 0 on the right
    // Equivalent to: number * 2^n
    // Example:
    // 4  = 0100
    // 4<<1 = 1000 = 8
    cout << "\n\n4)Bitwise LEFTSHIFT:\n";
    int n = 1;
    cout << (4 << n) << "\n"; // 4 * 2^1 = 8
    cout << (10 << 2);        // 10 * 2^2 = 40

    // Shifts bits to the RIGHT
    // Equivalent to: number / 2^n  (for positive integers)
    // Example:
    // 10 = 1010
    // 10 >> 1 = 0101 = 5
    cout << "\n\n4)Bitwise RIGHTSHIFT:\n";
    cout << (10 >> n) << "\n"; // 10 / 2^1 = 5
    cout << (8 >> 2);          // 8 / 2^2 = 2  (1000 -> 10)

    return 0;
}