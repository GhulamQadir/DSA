#include <iostream>
using namespace std;
#include <vector>

int main()
{
    // PROBLEM: Given an integer array nums, find a subarray that has the
    // largest product, and return the product.

    // Example array with an odd number of negative integers
    int arr[] = {2, 3, -2, -5, 6, -1, 15};
    int arr_length = sizeof(arr) / sizeof(int);

    // Initialize maxProduct with the first element of the array
    int maxProduct = arr[0];

    // leftProd will store the product starting from the beginning (Prefix)
    // rightProd will store the product starting from the end (Suffix)
    int leftProd = 1;
    int rightProd = 1;
    for (int i = 0; i < arr_length; i++)
    {
        /* 1. RESET ON ZERO:
           If the previous product became 0, the subarray chain is broken.
           We reset the product to 1 to start a fresh subarray from the current element.
        */
        if (leftProd == 0)
        {
            leftProd = 1;
        }
        if (rightProd == 0)
        {
            rightProd = 1;
        }

        /* 2. PRODUCT CALCULATION:
           Accumulate product from the left (i) and from the right (length - 1 - i) simultaneously.
        */
        leftProd *= arr[i];
        rightProd *= arr[arr_length - 1 - i];

        /* 3. UPDATE MAXIMUM:
           Check if the current prefix or suffix product is greater than our global max.
           In cases with an odd number of negatives, either the prefix (ignoring the last negative)
           or the suffix (ignoring the first negative) will yield the maximum value.
        */
        if (maxProduct < leftProd)
        {
            maxProduct = leftProd;
        }
        if (maxProduct < rightProd)
        {
            maxProduct = rightProd;
        }
    }
    cout << "Maximum Product: " << maxProduct;
}