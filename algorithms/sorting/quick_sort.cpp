#include <iostream>
using namespace std;

// Original Array
int arr[] = {22, 98, 18, 17, 11, 52, 78, 66, 51, 85, 111, 89, 87, 18};

/**
 * Function to partition the array.
 * It picks a pivot and ensures all elements to the left are smaller
 * and all elements to the right are larger.
 */
int set_pivot(int left, int right)
{
    // Selecting the middle element as the initial pivot index
    int pivot = left + (right - left) / 2;

    // Continue until the left and right pointers meet at the pivot's final position
    while (left < right)
    {
        // PHASE 1: Scan from the Right
        // Move the right pointer towards the pivot to find an element smaller than the pivot
        while (pivot != right)
        {
            if (arr[pivot] > arr[right])
            {
                // If an element on the right is smaller than the pivot, swap them
                int temp = arr[pivot];
                arr[pivot] = arr[right];
                arr[right] = temp;

                // After swapping, the pivot has moved to the 'right' index
                pivot = right;
                break; // Exit this inner loop to start scanning from the left
            }
            else
            {
                // If the element is already larger, just move the boundary inward
                right--;
            }
        }

        // PHASE 2: Scan from the Left
        // Move the left pointer towards the pivot to find an element larger than the pivot
        while (pivot != left)
        {
            if (arr[pivot] < arr[left])
            {
                // If an element on the left is larger than the pivot, swap them
                int temp = arr[pivot];
                arr[pivot] = arr[left];
                arr[left] = temp;

                // After swapping, the pivot has moved back to the 'left' index
                pivot = left;
                break; // Exit this inner loop to start scanning from the right again
            }
            else
            {
                // If the element is already smaller, move the boundary inward
                left++;
            }
        }
    }
    // Return the final resting position of the pivot
    return pivot;
}

/**
 * The Recursive Quick Sort function
 */
void quick_sort(int left, int right)
{
    // Base Case: If the segment has more than one element
    if (left < right)
    {
        // 1. Partition the array and get the pivot's final index
        int p_index = set_pivot(left, right);

        // 2. Recursively sort the left sub-array (elements before the pivot)
        quick_sort(left, p_index - 1);

        // 3. Recursively sort the right sub-array (elements after the pivot)
        quick_sort(p_index + 1, right);
    }
}

int main()
{
    int arr_length = sizeof(arr) / sizeof(int);

    // Initial call to sort the entire array
    quick_sort(0, arr_length - 1);

    // Display the sorted output
    cout << "Sorted Array:\n";
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << ", ";
    }
}