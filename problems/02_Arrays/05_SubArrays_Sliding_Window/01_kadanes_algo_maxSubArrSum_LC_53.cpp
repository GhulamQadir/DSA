#include <iostream>
using namespace std;
#include <climits>
int main()
{
    /* KADANE'S ALGORITHM CONCEPT:
       The idea is to scan the array and at each position, decide whether to:
       1. Extend the existing subarray sum.
       2. Or start a fresh subarray from the current element.

       If the 'current_sum' becomes negative, it will only decrease the sum of any
       future subarray. Therefore, we reset it to 0 and start over.
    */
    int nums[10] = {2, 9, -3, 5, -10, -1, 7, 5, -6, 4};
    int arr_len = sizeof(nums) / sizeof(nums[0]);

    int current_sum = 0;

    // Initialize max_sum with the first element.
    // This handles cases where all numbers in the array might be negative.
    int max_sum = nums[0];

    for (int i = 0; i < arr_len; i++)
    {
        // Step 1: Add the current element to the running total
        current_sum += nums[i];

        // Step 2: Update max_sum if the current_sum is the largest we've seen so far
        if (current_sum > max_sum)
        {
            max_sum = current_sum;
        }

        // Step 3: Reset current_sum to 0 if it falls below zero.
        // Logic: A negative sum cannot contribute to a "maximum" sum in the future.
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    cout << "Maximum Sub Array Sum: " << max_sum;
    return max_sum;
}