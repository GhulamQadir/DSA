#include <iostream>
using namespace std;

int main()
{
    // Array with repeated values (duplicates possible)
    int arr[9] = {2, 31, 23, 90, 78, 23, 6, 23, 45};
    int num_to_search;        // number to search in array
    bool match_found = false; // flag to check if any match occurs

    cout << "Enter the number to search: ";
    cin >> num_to_search;
    for (int i = 0; i < 9; i++)
    {
        // compare each element with target
        if (num_to_search == arr[i])
        {
            cout << "Number found at index " << i << endl;
            match_found = true; // mark that at least one match exists
            // if no occurrence found in whole array
        }
    }
    if (match_found == false)
    {
        cout << "Number not found";
    }
    return 0;
}