#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
    // Increment the large integer by one and return the resulting array of digits.
    vector<int> arr = {9, 7, 9, 9};
    int i = arr.size() - 1;
    bool plusOne = false;
    while (i >= 0 && arr[i] == 9)
    {
        arr[i] = 0;
        i--;
    }
    if (i == -1)
    {
        arr.insert(arr.begin(), 1);
    }
    else
    {
        arr[i] += 1;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ", ";
    }
}