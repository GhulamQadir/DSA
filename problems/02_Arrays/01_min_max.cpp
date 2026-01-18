#include <iostream>
using namespace std;

// Function to find both min and max values in a single pass
int find_min_max(int arr[], int arr_length)
{
    int min = arr[0]; // Assume first element is the smallest
    int max = arr[0]; // Assume first element is the largest
    for (int i = 1; i < arr_length; i++)
    {
        // If current element is smaller than our recorded min, update min
        if (arr[i] < min)
        {
            min = arr[i];
        }

        // If current element is larger than our recorded max, update max
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "Minimum Value of an array: " << min << endl;
    cout << "Maximum Value of an array: " << max << endl;
}

int main()
{
    // a program to find the minimum and maximum element in an integer array.
    int arr[5];
    int arr_length = sizeof(arr) / sizeof(int);
    cout << "Enter values: ";
    for (int i = 0; i < arr_length; i++)
    {
        cin >> arr[i]; // Input array elements from user
    }

    find_min_max(arr, arr_length);
}