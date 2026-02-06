#include <iostream>
using namespace std;

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

int main()
{
    // Swap every two adjacent elements in an array (Swap 0 with 1, 2 with 3, and so on).
    int arr[10] = {0, 4, 9, 17, 2, 8, 6, 3, 12, 16};
    int arr_length = sizeof(arr) / sizeof(int);

    // Logic only applies if we have pairs
    if (arr_length % 2 == 1)
    {
        cout << "Length have to be in even";
    }
    else
    {
        cout << "Array:\n";
        display_array(arr, arr_length);

        // Increment i by 2 to jump to the next pair
        for (int i = 0; i < arr_length; i += 2)
        {
            // Arithmetic swap for adjacent elements
            arr[i] += arr[i + 1];
            arr[i + 1] = arr[i] - arr[i + 1];
            arr[i] -= arr[i + 1];
        }

        cout << "\n\n Alternate elements:\n";
        display_array(arr, arr_length);
    }

    return 0;
}