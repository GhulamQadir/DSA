#include <iostream>
#include <vector>
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
    // Given an integer array nums of length n where all the integers of nums are in the range
    // [1, n] and each integer appears at most twice, return an array of all the integers that
    // appears twice.
    int arr[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int arr_length = sizeof(arr) / sizeof(int);

    vector<int> duplicates_arr;

    cout << "Original Array:\n";
    display_array(arr, arr_length);

    for (int i = 0; i < arr_length; i++)
    {
        // Step 1: Get the absolute value because the current element
        // might have been negated in a previous iteration.
        int val = abs(arr[i]);

        // Step 2: Use (val - 1) as the index to map the range [1, n].
        // Check if the value at this target index is already negative.
        if (arr[val - 1] < 0)
        {
            // If it's already negative, it means we've seen 'val' before.
            duplicates_arr.push_back(val);
            continue;
        }
        // Step 3: If it's positive, this is the first time seeing 'val'.
        // Mark it by negating the value at target index.
        arr[val - 1] *= -1;
    }

    // Output the duplicates
    cout << "\n\nDuplicates Array:\n";
    for (int i = 0; i < duplicates_arr.size(); i++)
    {
        cout << duplicates_arr[i] << "  ";
    }
    return 0;
}