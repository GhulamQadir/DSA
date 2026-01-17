#include <iostream>
using namespace std;

int binary_to_decimal(int n)
{
    int power = 1, answer = 0; // 'power' represents base-2 multipliers (1, 2, 4, 8)
    while (n > 0)
    {
        // Extract the last binary digit (0 or 1)
        int remainder = n % 10;

        // Gather the value by multiplying digit with its corresponding power of 2
        answer += remainder * power;
        n /= 10;
        power *= 2;
    }
    return answer;
}

int main()
{
    // binary to decimal conversion
    int n;
    cout << "Enter decimal value: ";
    cin >> n;
    int binary_val = binary_to_decimal(n);
    cout << binary_val;
    return 0;
}