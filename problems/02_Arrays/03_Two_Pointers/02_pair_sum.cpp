#include <iostream>
using namespace std;
#include <vector>

// Takes a vector of vectors (pairs) and prints them in (x,y) format.
void display(vector<vector<int>> pairs)
{
    for (int i = 0; i < pairs.size(); i++)
    {
        // pairs[i][0] is the first element of the pair, [i][1] is the second
        cout << "(" << pairs[i][0] << "," << pairs[i][1] << ") ";
    }
}

// Sorting based on the FIRST element of each pair.
void insertion_sort(vector<vector<int>> &pairs)
{
    // Start from the second element (index 1) as the first is already "sorted"
    for (int i = 0; i < pairs.size(); i++)
    {
        int gap = i - 1;
        vector<int> current_pair = pairs[i];
        int shifting_position = i;

        while (gap >= 0)
        {
            if (current_pair[0] < pairs[gap][0])
            {
                pairs[gap + 1] = pairs[gap];
                shifting_position = gap;
                gap--;
            }
            else
            {
                break;
            }
        }
        pairs[shifting_position] = current_pair;
    }
}

int main()
{
    // Given an array of integer and target of type int. Return the list of all pairs of
    // elements such that the sum of elements of each pair equals to target
    int arr[] = {41, 36, 40, 8, 12, 7};
    int arr_length = sizeof(arr) / sizeof(int);

    int target;
    cout << "Enter targeted value of pair: ";
    cin >> target;

    // A vector of vectors to store pairs that sum up to the target
    vector<vector<int>> pairs;

    // Brute Force Approach: Compare every element with every other element
    // Time Complexity: O(n^2)
    for (int i = 0; i < arr_length - 1; i++)
    {
        for (int j = i + 1; j < arr_length; j++)
        {
            // Check if the sum of current two elements equals the target
            if (arr[i] + arr[j] == target)
            {
                vector<int> pair;
                // Store the pair in a sorted way: (smaller, larger)
                pair.push_back(min(arr[i], arr[j]));
                pair.push_back(max(arr[i], arr[j]));

                // Add the individual pair to main 'pairs' list
                pairs.push_back(pair);
            }
        }
    }
    // Sort the collected pairs based on their first values
    insertion_sort(pairs);

    cout << "Sorted pairs with target: " << target << endl;
    display(pairs);
}