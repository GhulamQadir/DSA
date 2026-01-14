#include <iostream>
using namespace std;

int main()
{
    int arr[9] = {5, 7, 3, 10, 155, 22, 76, 1, 4};

    // Calculate the total number of elements in the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    // Outer loop: iterate from the second element to the last
    for (int i = 1; i < arr_len; i++)
    {
        int gap = i - 1;              // Position to compare with previous elements
        int current_element = arr[i]; // Store current element to insert
        int shifting_position = i;    // Position where current element will be inserted

        // Shift elements of the sorted portion to the right to make space
        while (gap >= 0)
        {
            if (current_element < arr[gap])
            {
                arr[gap + 1] = arr[gap]; // Shift element one position to the right
                shifting_position = gap; // Update the position for insertion
                gap--;                   // Move left in the sorted portion
            }
            else
            {
                break; // Found correct position for current_element
            }
        }
        // Insert the current element at the correct position
        arr[shifting_position] = current_element;
    }
    cout << "[";
    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i];
        if (i != arr_len - 1)
        {
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}