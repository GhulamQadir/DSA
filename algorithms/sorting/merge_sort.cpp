#include <iostream>
using namespace std;
#include <vector>

/**
 * The Merge function:
 * This is where the actual sorting happens. It takes two sorted halves
 * of an array and merges them into a single sorted section.
 */
void merge(int arr[], int start, int mid, int end)
{
    // A temporary vector to store the merged elements
    vector<int> temp;

    // Pointer for the start of the Left half
    int i = start;
    // Pointer for the start of the Right half
    int j = mid + 1;

    // Compare elements from both halves and push the smaller one to 'temp'
    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // If any elements remain in the Left half, add them to 'temp'
    while (i <= mid)
    {
        temp.push_back(arr[i]);
        i++;
    }

    // If any elements remain in the Right half, add them to 'temp'
    while (j <= end)
    {
        temp.push_back(arr[j]);
        j++;
    }

    // TRANSFER: Copy the sorted elements from 'temp' back into the original array
    // We use (i + start) to ensure we are overwriting the correct section of 'arr'
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i + start] = temp[i];
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);   // left half
        mergeSort(arr, mid + 1, end); // right half

        merge(arr, start, mid, end);
    }
}

int main()
{
    int arr[] = {22, 98, 18, 17, 11, 52, 78, 66, 51, 85, 111, 89, 87, 18};
    int arr_length = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, arr_length - 1);
    for (int val : arr)
    {
        cout << val << "  ";
    }
}