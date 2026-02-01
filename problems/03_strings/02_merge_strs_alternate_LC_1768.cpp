#include <iostream>
using namespace std;

int main()
{
    // PROBLEM: Merge two strings by alternating characters.
    // Remaining characters of the longer string should be appended at the end.

    string word1 = "abcd";
    string word2 = "pqrstuv";

    // Identify which string is longer to handle the remaining characters later
    string max_length_word = (word1.length() >= word2.length()) ? word1 : word2;

    // Determine the length of the shorter string to avoid 'out of bounds' errors during alternating merge
    int short_len = (word1.length() <= word2.length()) ? word1.length() : word2.length();

    string merged_str = "";

    // Loop through the strings up to the shorter length to add characters in alternating order
    for (int i = 0; i < short_len; i++)
    {
        // Add one character from word1, then one from word2
        merged_str = merged_str + word1[i] + word2[i];
    }

    // Use substr() to get the remaining part of the longer string (from index short_len to end)
    // and append it to the merged_word
    merged_str += max_length_word.substr(short_len);

    cout << merged_str;
}