#include <iostream>
using namespace std;

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

// Insertion Sort: Moves each element to its correct position in the sorted part
void sorting(int arr[], int arr_len)
{
    // Outer loop: iterate from the second element to the last
    for (int i = 1; i < arr_len; i++)
    {
        int gap = i - 1;              // Position to compare with previous elements
        int current_element = arr[i]; // Store current element to insert
        int shifting_position = i;    // Position where current element will be inserted

        // Shift elements to the right to create space for insertion
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
}

// Copies only non-duplicate elements into a new array
int extract_unique_elements(int arr[], int unique_arr[], int arr_len)
{
    unique_arr[0] = arr[0]; // The first sorted element is always unique
    int unique_arr_current_index = 1;
    for (int i = 1; i < arr_len; i++)
    {
        // If current element is different from previous, it is a new unique value
        if (arr[i] != arr[i - 1])
        {
            cout << unique_arr_current_index;
            unique_arr[unique_arr_current_index] = arr[i];
            unique_arr_current_index++;
        }
    }
    return unique_arr_current_index; // Return count of unique elements found
}

int main()
{
    // extract only the unique elements into a separate array.
    int arr[12] = {2, 4, 9, 17, 2, 8, 6, 3, 12, 17, 16, 9};
    int arr_length = sizeof(arr) / sizeof(int);
    cout << "Array:\n";
    display_array(arr, arr_length);
    cout << endl;

    sorting(arr, arr_length); // Step 1: Sort to bring duplicates together

    int unique_arr[12] = {0};
    int unique_arr_last_index = extract_unique_elements(arr, unique_arr, arr_length);
    cout << "\n\nUnique Array:\n";
    display_array(unique_arr, unique_arr_last_index);

    return 0;
}