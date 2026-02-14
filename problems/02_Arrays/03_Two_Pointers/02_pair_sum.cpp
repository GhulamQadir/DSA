#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    // Given an array of integer and target of type int. Return the list of all pairs of
    // elements such that the sum of elements of each pair equals to target

    // The Two-Pointer approach requires the array to be sorted beforehand.
    int arr[] = {4, 8, 13, 36, 40, 43};
    int arr_length = sizeof(arr) / sizeof(int);

    int target;

    cout << "Enter targeted value of pair: ";
    cin >> target;

    // Vector to store the indices of the pair that matches the target sum
    vector<int> pair;

    // Initialize two pointers:
    // 'i' at the start (smallest element) and 'j' at the end (largest element)
    int i = 0;
    int j = arr_length - 1;

    // Loop until the two pointers meet
    while (i != j)
    {
        // Case 1: If current sum matches target, store indices and exit loop
        if (arr[i] + arr[j] == target)
        {
            pair.push_back(i);
            pair.push_back(j);
            break;
        }
        // Case 2: If sum is greater than target, we need a smaller sum.
        // Move the right pointer (j) leftwards to point to a smaller value.
        else if (arr[i] + arr[j] > target)
        {
            j--;
        }
        // Case 3: If sum is smaller than target, we need a larger sum.
        // Move the left pointer (i) rightwards to point to a larger value.
        else
        {
            i++;
        }
    }

    if (pair.size() > 0)
    {
        cout << "Sorted pair with target: " << target << endl;
        cout << "(" << pair[0] << ", " << pair[1] << ")";
    }
    else
    {
        cout << "No pair found with the target sum." << endl;
    }
    return 0;
}