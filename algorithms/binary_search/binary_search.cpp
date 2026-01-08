#include <iostream>
using namespace std;

int main()
{
    // Sorted array (binary search works only on sorted arrays)
    int arr[12] = {2, 43, 65, 98, 101, 129, 130, 177, 200, 210, 222, 234};
    int n;
    cout << "Enter number to search: ";
    cin >> n;

    // left pointer -> start of array
    int left = 0;

    // sizeof(arr) = total bytes of array
    // sizeof(arr[0]) = bytes of one element
    // total elements = total bytes / bytes per element
    // right pointer -> end of array index
    int right = (sizeof(arr) / sizeof(arr[0])) - 1;

    // middle index
    int mid = (left + right) / 2;

    // loop continues until search space ends
    while (left <= right)
    {
        if (n == arr[mid])
        {
            // if middle element matches, number found
            cout << "Number found at index " << mid;
            return 0; // program exit
        }

        // if number is greater -> search right half
        if (n > arr[mid])
        {
            left = mid + 1;           // shift left boundary to right
            mid = (left + right) / 2; // recompute mid
        }
        else // otherwise search left half
        {
            right = mid - 1;          // shift right boundary to left
            mid = (left + right) / 2; // recompute mid
        }
    }
    // loop finished -> element not found
    cout << "Number not found";
    return 0;
}