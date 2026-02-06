#include <iostream>
using namespace std;

// Using Binary Search for checking Intersection
int binary_search(int value_to_search, int arr[], int arr_length)
{
    bool value_matched = false;
    int left = 0;
    int right = arr_length - 1;
    int mid = (left + right) / 2;
    while (left <= right)
    {
        if (value_to_search == arr[mid])
        {
            return true;
        }
        else if (value_to_search < arr[mid])
        {
            right = mid - 1;
            mid = (left + right) / 2;
        }
        else if (value_to_search > arr[mid])
        {
            left = mid + 1;
            mid = (left + right) / 2;
        }
    }
    return false;
}

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

int main()
{
    // Arrays Intersection Using Binary Search
    int arr_1[8] = {12, 30, 41, 62, 98, 100, 101, 125};
    int arr_2[7] = {1, 12, 41, 47, 100, 100, 140};
    int arr1_length = sizeof(arr_1) / sizeof(int);
    int arr2_length = sizeof(arr_2) / sizeof(int);

    // Array to store results, max possible size is length of arr_2
    int intersection_arr[arr2_length] = {0};
    int matched_index = 0;

    for (int i = 0; i < arr2_length; i++)
    {
        // DUPLICATE HANDLING & BOUNDARY CHECK:
        // i > 0 ensures we don't check index -1.
        // arr_2[i] == arr_2[i-1] skips search if an element is duplicate.
        if (i > 0 && arr_2[i] == arr_2[i - 1])
        {
            continue;
        }

        // Use Binary Search to look for arr_2's current element inside arr_1
        bool match = binary_search(arr_2[i], arr_1, arr1_length);
        if (match)
        {
            // If found, add to intersection array and move result index forward
            intersection_arr[matched_index] = arr_2[i];
            matched_index++;
        }
    }

    cout << "Array 1:\n";
    display_array(arr_1, arr1_length);
    cout << "\nArray 2:\n";
    display_array(arr_2, arr2_length);

    cout << "\n\nIntersection Array:\n";
    display_array(intersection_arr, matched_index);
}