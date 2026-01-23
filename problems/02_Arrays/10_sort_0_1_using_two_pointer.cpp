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
    /*
    Given an array containing only 0s and 1s, sort the array in-place using the Two-Pointer
    technique so that all 0s appear at the beginning and all 1s appear at the end. */

    // Input array containing only 0s and 1s
    int arr[] = {0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0};
    int arr_length = sizeof(arr) / sizeof(int);

    // Initialize two pointers
    int left_index = 0;               // Starts from the beginning
    int right_index = arr_length - 1; // Starts from the end

    while (left_index < right_index)
    {
        // Increment left_index as long as we find 0s (they are already in the right place)
        while (left_index < right_index && arr[left_index] == 0)
        {
            left_index++;
        }

        // Decrement right_index as long as we find 1s (they are already in the right place)
        while (left_index < right_index && arr[right_index] == 1)
        {
            right_index--;
        }

        // Swapping values
        arr[left_index] = 0;
        arr[right_index] = 1;

        // Move pointers further to continue checking the rest of the array
        left_index++;
        right_index--;
    }
    display_array(arr, arr_length);
    cout << "\n";
}