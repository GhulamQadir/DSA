/* MOORE'S VOTING ALGORITHM (Short Summary):
   The logic is based on "Cancellation". If we pair the majority element
   with every other different element, the majority element will still
   have remaining occurrences because it exists more than n/2 times.
*/
#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // Problem: Find majority element which appears greater than size/2 times in an array
    vector<int> nums = {1, 4, 2, 4, 4, 1, 4, 4, 3, 4, 1};

    // We start by assuming the first element is the winner.
    int frequency = 1;
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        // If frequency becomes 0, it means the previous candidate
        // was "voted out" by different elements. Reset to current element.
        if (frequency == 0)
        {
            result = nums[i];
            frequency = 1;
        }
        // If current element is same as candidate, increase its power (vote).
        else if (result == nums[i])
        {
            frequency++;
        }
        // If different, the current element "fights" the candidate; both lose 1 power
        else
        {
            frequency--;
        }
    }

    // Moore's Algorithm only gives a 'candidate'. We must verify if it
    // actually appears more than n/2 times (important if majority might not exist).
    int verify_frequency = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == result)
        {
            verify_frequency++;
        }
    }

    // Check if the total count satisfies the Majority condition (> n/2)
    if (verify_frequency > (nums.size() / 2))
    {
        cout << "Majority Element: " << result;
        return 0;
    }
    cout << "Majority Element Not Found";
}