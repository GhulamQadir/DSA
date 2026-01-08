#include <iostream>
using namespace std;

int main()
{
    // Sorted array with multiple occurrences of 198
    int arr[15] = {2, 43, 98, 101, 129, 130, 177, 198, 198, 198, 198, 200, 210, 222, 234};
    int n; // number to search
    cout << "Enter number to search: ";
    cin >> n;

    // search pointers
    int left = 0;
    int right = (sizeof(arr) / sizeof(arr[0])) - 1; // last index
    int mid = (left + right) / 2;                   // middle index
    bool match_found = false;                       // flag to check if element is found

    while (left <= right)
    {
        if (!match_found) // still searching for first match
        {
            if (n == arr[mid]) // found the first occurrence
            {
                match_found = true;
                cout << "Number found at index " << mid << endl;
            }
            else if (n > arr[mid]) // search in right half
            {
                left = mid + 1;
                mid = (left + right) / 2;
            }
            else // search in left half
            {
                right = mid - 1;
                mid = (left + right) / 2;
            }
        }
        else // first match found → now find all duplicates
        {
            // search left side of mid for duplicates
            for (int i = mid - 1; i >= 0; i--)
            {
                if (n == arr[i])
                {
                    cout << "Number found at index " << i << endl;
                }
                else
                {
                    break; // stop when number differs
                }
            }
            // search right side of mid for duplicates
            for (int i = mid + 1; i < 15; i++)
            {
                if (n == arr[i])
                {
                    cout << "Number found at index " << i << endl;
                }
                else
                {
                    break; // stop when number differs
                }
            }
            break; // all duplicates printed -> exit while loop
        }
    }

    // If element not found at all
    if (!match_found)
    {
        cout << "Number not found";
    }
    return 0;
}