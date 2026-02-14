#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    // Original unsorted vector
    vector<int> nums = {4, 36, 8, 40, 13, 43};
    int n = nums.size();

    // Step 1: Create a copy of the original vector to sort it.
    // This is necessary because the Two-Pointer approach only works on sorted data.
    vector<int> sorted_nums = nums;
    vector<int> pair = {};

    // Step 2: Sort the copied vector
    sort(sorted_nums.begin(), sorted_nums.end());

    int target;
    cout << "Enter targeted value of pair: ";
    cin >> target;

    // Step 3: Use Two-Pointer technique on the sorted vector to find the two values
    int i = 0;
    int j = n - 1;

    // till two pointers meet
    while (i < j)
    {
        int sum = sorted_nums[i] + sorted_nums[j];
        if (sum == target)
        {
            // Store the values (not indices) that make up the target sum
            pair.push_back(sorted_nums[i]);
            pair.push_back(sorted_nums[j]);
            break;
        }
        else if (sum > target)
        {
            j--; // Decrease the sum by moving the right pointer to a smaller value
            continue;
        }
        i++; // Increase the sum by moving the left pointer to a larger value
    }

    /* Step 4: Find the original indices of these two values.
       We iterate through the original 'nums' vector to see where these values
       were located before sorting. */
    if (pair.size() == 2)
    {
        vector<int> original_pair_indexes = {};
        int k = 0;

        // We only stop when we find both indices to handle the result
        while (original_pair_indexes.size() < 2 && k < n)
        {
            if (nums[k] == pair[0] || nums[k] == pair[1])
            {
                original_pair_indexes.push_back(k);
            }
            k++;
        }
        cout << "Original Indices: (" << original_pair_indexes[0] << ", " << original_pair_indexes[1] << ")";
    }
    else
    {
        cout << "No Pair Found";
    }
    return 0;
}