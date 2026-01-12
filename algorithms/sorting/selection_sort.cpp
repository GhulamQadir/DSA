#include <iostream>
using namespace std;

int main()
{
    // Array containing unsorted elements
    int arr[9] = {5, 7, 3, 10, 155, 22, 76, 1, 4};

    // Calculate the total number of elements in the array
    int arr_len = sizeof(arr) / sizeof(arr[0]);

    // Outer loop: selects the position where the smallest element should be placed
    for (int i = 0; i < arr_len - 1; i++)
    {
        // Assume the current element is the smallest
        int smallest = arr[i];

        // Store the index of the smallest element
        int index_to_replace = i;

        // Inner loop: find the smallest element in the remaining unsorted part
        for (int j = i + 1; j < arr_len; j++)
        {
            // If a smaller element is found, update smallest and its index
            if (arr[j] < smallest)
            {
                smallest = arr[j];
                index_to_replace = j;
            }
        }
        // Swap the smallest element with the element at position i
        arr[index_to_replace] = arr[i];
        arr[i] = smallest;
    }

    for (int i = 0; i < arr_len; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}