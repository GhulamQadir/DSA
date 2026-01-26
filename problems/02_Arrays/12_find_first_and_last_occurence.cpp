#include <iostream>
using namespace std;

// Finds the first occurrence of a target element in a sorted array.
int first_occurence(int arr[], int arr_length, int element_to_search)
{
    int left = 0;
    int right = arr_length - 1;
    int mid = (left + right) / 2;
    int first_occu_index = -1; // Default value if element is not found

    while (left <= right)
    {
        if (arr[mid] == element_to_search)
        {
            first_occu_index = mid; // Potential answer found
            right = mid - 1;        // Keep searching on the left side for an earlier occurrence
        }
        else if (arr[mid] > element_to_search)
        {
            right = mid - 1; // Target is in the left half
        }
        else if (arr[mid] < element_to_search)
        {
            left = mid + 1; // Target is in the right half
        }
        mid = (left + right) / 2;
    }
    return first_occu_index;
}

// Finds the last occurrence of a target element in a sorted array.
int last_occurence(int arr[], int arr_length, int element_to_search, int default_last_occurence)
{
    int left = 0;
    int right = arr_length - 1;
    int mid = (left + right) / 2;
    int last_occu_index = default_last_occurence;

    while (left <= right)
    {
        if (arr[mid] == element_to_search)
        {
            last_occu_index = mid; // Potential answer found
            left = mid + 1;        // Keep searching on the right side for a later occurrence
        }
        else if (arr[mid] > element_to_search)
        {
            right = mid - 1;
        }
        else if (arr[mid] < element_to_search)
        {
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return last_occu_index;
}

int main()
{
    // Problem: Given a sorted array of integers, find the first and last occurrence
    // indices of a specific element using Binary Search. If the element is not found, return -1

    // sorted array with duplicate elements
    int arr[] = {3, 5, 6, 8, 9, 9, 9, 9, 9, 20, 54};
    int arr_length = sizeof(arr) / sizeof(int);
    int n;
    cout << "Enter element to search: ";
    cin >> n;
    int first_occu = first_occurence(arr, arr_length, n);
    int last_occu = last_occurence(arr, arr_length, n, first_occu);
    cout << "First Occurence of " << n << " is at index " << first_occu << " and last occurence is at " << last_occu;
}