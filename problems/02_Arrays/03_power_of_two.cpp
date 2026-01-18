#include <iostream>
using namespace std;
#include <cmath>

int main()
{
    // Identify and print elements in an array that are powers of 2 (e.g., 1, 2, 4, 8, 16).
    int arr[10] = {0, 4, 9, 17, 2, 8, 6, 3, 12, 16};
    int arr_length = sizeof(arr) / sizeof(int);

    for (int i = 0; i < arr_length; i++)
    {
        int power_index = 0;
        int power = pow(2, power_index); // Start checking from 2^0

        // Compare current element with power of 2
        if (arr[i] == power)
        {
            cout << arr[i] << " is the power of 2^" << power_index << endl;
        }
        else if (arr[i] > power)
        {
            // Keep incrementing power until it matches or exceeds the array element
            while (arr[i] > power)
            {
                power_index++;
                power = pow(2, power_index);
                if (arr[i] == power)
                {
                    cout << arr[i] << " is the power of 2^" << power_index << endl;
                    break;
                }
            }
        }
    }
}