
#include <iostream>
using namespace std;
#include <vector>
#include <climits> // For INT_MIN

int main()
{
    /* PROBLEM STATEMENT:
       Majority Element II - Find all elements that appear more than floor(n/3) times in an array.
       Logic: Boyer-Moore Majority Voting Algorithm (Extended to 2 Candidates).
    */

    vector<int> nums = {1, 4, 1, 4, 1, 4, 1, 4, 2, 3, 5};

    // We maintain two candidates because at most only TWO elements can appear > n/3 times.
    int freq_count_1 = 0, freq_count_2 = 0;
    int answer1 = INT_MIN, answer2 = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        // CASE 1: The current element is NOT one of our existing candidates
        if (nums[i] != answer1 && nums[i] != answer2)
        {
            // If both candidate slots are currently occupied and have voting power,
            // the new unique element "challenges" both. All three cancel each other out.
            if (freq_count_1 != 0 && freq_count_2 != 0)
            {
                freq_count_1--;
                freq_count_2--;
            }
            // If Candidate 1's slot is empty, the current element takes over as Candidate 1.
            else if (freq_count_1 == 0)
            {
                answer1 = nums[i];
                freq_count_1 = 1;
            }
            // If Candidate 1 is occupied but Candidate 2's slot is empty,
            // the current element takes over as Candidate 2.
            else if (freq_count_2 == 0)
            {
                answer2 = nums[i];
                freq_count_2 = 1;
            }
        }
        // CASE 2: The current element matches Candidate 1
        else if (nums[i] == answer1)
        {
            freq_count_1++; // Increase voting power for Candidate 1
        }
        // CASE 3: The current element matches Candidate 2
        else if (nums[i] == answer2)
        {
            freq_count_2++; // Increase voting power for Candidate 2
        }
    }

    // Boyer-Moore only gives potential candidates. We must verify their actual frequency.
    int verify_frequency_1 = 0;
    int verify_frequency_2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == answer1)
        {
            verify_frequency_1++;
        }
        else if (nums[i] == answer2)
        {
            verify_frequency_2++;
        }
    }

    // Checking if the candidates meet the (> n/3) criteria independently
    vector<int> answers;
    if (verify_frequency_1 > (nums.size() / 3))
    {
        answers.push_back(answer1);
    }

    if (verify_frequency_2 > (nums.size() / 3))
    {
        answers.push_back(answer2);
    }

    bool element_found = false;
    for (int i = 0; i < answers.size(); i++)
    {
        element_found = true;
        cout << answers[i] << "  ";
    }

    if (!element_found)
    {
        cout << "Majority Element Not Found";
    }
}