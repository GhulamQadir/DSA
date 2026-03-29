#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    // Given an array of integer and target of type int. Return the list of all pairs of
    // elements such that the sum of elements of each pair equals to target

    // The Two-Pointer approach requires the array to be sorted beforehand.
    int arr[] = {4, 8, 12, 13, 36, 40, 43};
    int arr_length = sizeof(arr) / sizeof(int);

    int target;

    cout << "Enter targeted value of pair: ";
    cin >> target;

    // A 2D vector to store multiple pairs of indices.
    vector<vector<int>> pairs;

    // Initialize two pointers:
    // 'i' at the start (smallest element) and 'j' at the end (largest element)
    int i = 0;
    int j = arr_length - 1;

    // Loop until the two pointers meet
    while (i < j)
    {
        // Case 1: Target sum found.
        if (arr[i] + arr[j] == target)
        {
            // Create a temporary vector to store the current pair of indices.
            vector<int> temp;
            temp.push_back(i);
            temp.push_back(j);

            // Store the pair in our main results vector.
            pairs.push_back(temp);

            // Move both pointers inward to look for other possible pairs.
            i++;
            j--;
        }

        // Case 2: Current sum is too large.
        // Move the right pointer (j) leftward to decrease the total sum.
        else if (arr[i] + arr[j] > target)
        {
            j--;
        }

        // Case 3: Current sum is too small.
        // Move the left pointer (i) rightward to increase the total sum.
        else
        {
            i++;
        }
    }

    // Check if any pairs were found.
    if (pairs.size() > 0)
    {
        cout << "Indices of pairs with target sum " << target << ":" << endl;
        for (int i = 0; i < pairs.size(); i++)
        {
            cout<< "(" << pairs[i][0] << ", " << pairs[i][1]<< ")" << endl;
        }
    }
    else
    {
        cout << "No pair found with the target sum." << endl;
    }
    return 0;
}