#include <iostream>
using namespace std;

int main()
{
    // Problem: Find the index of the peak element in a Mountain Array. A mountain array increases
    // to a maximum value (the peak) and then decreases.

    // A mountain array (strictly increasing then strictly decreasing)
    int arr[] = {3, 5, 6, 8, 10, 20, 54, 73, 32, 21};
    int arr_length = sizeof(arr) / sizeof(int);
    int left = 0;
    int right = arr_length - 1;

    // Initial mid calculation using overflow-safe formula
    int mid = left + (right - left) / 2;

    /* Binary Search for Peak:
       We use (left < right) because we are comparing mid with mid+1.
       When left == right, we have narrowed down to the peak index.*/
    while (left < right)
    {
        // Case 1: If mid is smaller than the next element, we are on the ascending slope.
        // The peak must be to the right, so we move the left pointer.
        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        // Case 2: If mid is greater than the next element, we are either at the peak
        // or on the descending slope. The peak is to the left or is mid itself.
        else
        {
            right = mid;
        }
        // Recalculate mid for the next iteration
        mid = left + (right - left) / 2;
    }
    // At the end of the loop, left and right will converge at the peak index.
    cout << "Peak index in a mountain array is: " << left;
}