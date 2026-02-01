#include <iostream>
using namespace std;

int main()
{
    // PROBLEM: String 't' (s2) is 's' (s1) shuffled with one extra character added.
    // Goal: Identify that extra character.

    string s1 = "neetcode";
    string s2 = "doceueten";

    int sum1 = 0; // Stores the total ASCII sum of characters in s1
    int sum2 = 0; // Stores the total ASCII sum of characters in s2

    // Loop through s1 length (since s1 is shorter)
    // We add ASCII values of characters from both strings simultaneously
    for (int i = 0; i < s1.length(); i++)
    {
        sum1 += s1[i];
        sum2 += s2[i];
    }

    // Since s2 has one extra character at the end (or any random position),
    // and our loop only ran for s1.length(), we must add the last character of s2 manually.
    sum2 += s2[s2.length() - 1];
    cout << "Sum 1: " << sum1;
    cout << "\nSum 2: " << sum2;

    // The difference between the two sums will be the ASCII value of the added character.
    int difference = sum2 - sum1;
    cout << "\nDifference: " << difference;

    // Convert the integer difference back into a character (Typecasting)
    char additional_char = difference;
    cout << "\nAdditional Char: " << additional_char;
}