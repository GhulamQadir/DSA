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
    // Reverse an array without using a temporary third variable for swapping.
    int arr[7] = {1, 4, 2, 8, 6, 3, 0};
    int arr_length = sizeof(arr) / sizeof(int);

    // We only need to iterate through half of the array to swap all elements
    int iter_size = (sizeof(arr) / sizeof(int)) / 2;

    cout << "Normal Array\n";
    display_array(arr, arr_length);

    for (int i = 0; i < iter_size; i++)
    {
        int index_to_replace = arr_length - i - 1; // Calculate the opposite index

        // Swapping logic using Arithmetic (Addition and Subtraction)
        arr[i] = arr[index_to_replace] + arr[i];
        arr[index_to_replace] = arr[i] - arr[index_to_replace];
        arr[i] = arr[i] - arr[index_to_replace];
    }

    cout << "\n\nReversed Array\n";
    display_array(arr, arr_length);

    return 0;
}