#include <iostream>
using namespace std;

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

// Swaps two elements in the array using a temporary variable.
void swap_values(int arr[], int val1, int val2)
{
    int temp = arr[val1];
    arr[val1] = arr[val2];
    arr[val2] = temp;
}

int main()
{
    /* Given an array of integers containing only 0s, 1s, and 2s, sort the array
       in-place in a single pass without using any built-in sorting functions. The result
       should have all 0s first, followed by 1s, and then 2s. */

    // Input array containing 0s, 1s, and 2s in random order
    int arr[15] = {0, 2, 1, 2, 0, 1, 0, 1, 0, 0, 2, 1, 1, 2, 0};
    int arr_length = sizeof(arr) / sizeof(int);

    cout << "Original Array:\n";
    display_array(arr, arr_length);

    // 3-Pointer Approach
    // low  -> tracks the boundary for 0s (left side)
    // mid  -> current element being scanned
    // high -> tracks the boundary for 2s (right side)
    int low = 0, mid = 0, high = arr_length - 1;

    // We process the array until the scan pointer (mid) passes the high boundary
    while (mid <= high)
    {
        // Case 1: If current element is 0
        if (arr[mid] == 0)
        {
            // Swap it with the element at 'low' boundary
            swap_values(arr, low, mid);
            low++; // Expand the 0s territory
            mid++; // Move to next element
        }
        // Case 2: If current element is 1
        else if (arr[mid] == 1)
        {
            // 1s stay in the middle, so just move the scan pointer
            mid++;
        }
        // Case 3: If current element is 2
        else if (arr[mid] == 2)
        {
            // Swap it with the element at 'high' boundary
            swap_values(arr, mid, high);
            high--; // Shrink the '2s' boundary from the right

            // mid is NOT incremented here because the new element
            // brought from 'high' needs to be checked (it could be 0, 1, or 2).
        }
    }

    cout << "\nAfter Sorting:\n";
    display_array(arr, arr_length);
}