#include <iostream>
using namespace std;

int main()
{
    /* PROBLEM:
    You are given an array prices where prices[i] is the price of a given stock on the ith day.
    You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    */

    // Sample stock prices where index is the day and value is the price
    int arr[] = {7, 1, 5, 3, 6, 4};

    // Calculate the number of elements in the array
    int arr_len = sizeof(arr) / sizeof(int);

    // Initialize bestBuy with the first day's price
    // This variable tracks the minimum price encountered so far
    int bestBuy = arr[0];

    // Initialize maxProfit to 0 (assuming no profit can be made initially)
    int maxProfit = 0;

    // Start iterating from the second day (index 1)
    for (int i = 1; i < arr_len; i++)
    {
        // Check if selling at today's price (arr[i]) gives a better profit
        // than any profit we've found before
        if ((arr[i] - bestBuy) > maxProfit)
        {
            // Update maxProfit with the new higher value
            maxProfit = arr[i] - bestBuy;
        }

        // Check if today's price is lower than our current bestBuy price
        if (bestBuy > arr[i])
        {
            // Update bestBuy to today's price to maximize potential future profit
            bestBuy = arr[i];
        }
    }
    cout << "Maximum Profit: " << maxProfit;
}