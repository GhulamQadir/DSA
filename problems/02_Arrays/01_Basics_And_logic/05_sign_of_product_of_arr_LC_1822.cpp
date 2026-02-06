#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // PROBLEM: You are given an integer array nums. Let product be the product of all
    // values in the array nums.
    // 1 if x is positive.
    // -1 if x is negative.
    // 0 if x is equal to 0.

    vector<int> nums = {-19, 23, -7, 5, -1};
    int product = 1;
    int negative = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            cout << "Zero";
            return 0;
        }
        else if (nums[i] < 0)
        {
            negative++;
        }
    }
    if (negative != 0 && negative % 2 == 1)
    {
        cout << "Negative";
        return -1;
    }
    cout << "Positive";
    return 1;
}