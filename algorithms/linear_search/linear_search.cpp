#include <iostream>
using namespace std;

int main()
{
    // Fixed-size array with 7 integers
    int arr[7] = {2, 31, 23, 90, 78, 6, 45};

    int num_to_search;        // number user wants to search
    bool match_found = false; // flag to track if value exists

    cout << "Enter the number to search: ";
    cin >> num_to_search;
    for (int i = 0; i < 7; i++)
    {
        // check current element
        if (num_to_search == arr[i])
        {
            cout << "Number found at index " << i;
            match_found = true; // mark as found
            break;              // stop after first match
        }
    }
    // If never found in loop
    if (match_found == false)
    {
        cout << "Number not found";
    }
    return 0;
}