#include <iostream>
using namespace std;

int main()
{
    // Array containing unsorted elements
    int arr[9] = {5, 7, 3, 10, 155, 22, 76, 1, 4};

    // Calculate the total number of elements in the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    // Outer loop controls the number of passes
    // After each pass, the largest element moves to the end
    for (int i = 0; i < arr_len - 1; i++)
    {
        bool swapped = false;
        // Inner loop compares adjacent elements
        // (arr_len - (i + 1)) avoids checking already sorted elements
        for (int j = 0; j < arr_len - (i + 1); j++)
        {
            // If current element is greater than the next one, swap them
            if (arr[j] > arr[j + 1])
            {
                // Temporary variable used for swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
    }
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}