#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main()
{
    // Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

    vector<int> arr = {3, 6, 9, 12, 15};
    sort(arr.begin(), arr.end());

    for (int i = 2; i < arr.size(); i++)
    {
        if (arr[i] - arr[i - 1] != arr[i - 1] - arr[i - 2])
        {
            cout << "This is not an arithmetic progression";
            return 0;
        }
    }
    cout << "This is an arithmetic progression";
}