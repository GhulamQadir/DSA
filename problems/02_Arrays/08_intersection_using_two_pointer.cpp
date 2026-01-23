#include <iostream>
using namespace std;

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

int main()
{
    // Arrays Intersection Using Two-Pointer Approach (Works Only on Sorted Arrays)
    int arr_1[8] = {12, 30, 41, 62, 98, 100, 101, 125};
    int arr_2[7] = {1, 12, 41, 47, 100, 100, 140};
    int n1 = sizeof(arr_1) / sizeof(int);
    int n2 = sizeof(arr_2) / sizeof(int);

    // Intersecting Elements Array
    int intersection_arr[n2] = {0};
    int intersect_index = 0;

    // Two pointers: 'i' for arr_2 and 'j' for arr_1
    int i = 0, j = 0;

    // Iterate until we reach the end of either array
    while (i < n2 && j < n1)
    {
        // Skip duplicate elements in arr_2 to ensure unique elements in result
        if (i > 0 && arr_2[i] == arr_2[i - 1])
        {
            i++;
            continue;
        }

        // Case 1: Elements match
        if (arr_2[i] == arr_1[j])
        {
            intersection_arr[intersect_index] = arr_2[i];
            intersect_index++;
            i++;
            j++;
        }
        // Case 2: Element in arr_1 is smaller, move j forward to find a larger value
        else if (arr_2[i] > arr_1[j])
        {
            j++;
        }
        // Case 3: Element in arr_2 is smaller, move i forward
        else if (arr_2[i] < arr_1[j])
        {
            i++;
        }
    }

    cout << "Array 1:\n";
    display_array(arr_1, n1);
    cout << "\nArray 2:\n";
    display_array(arr_2, n2);

    if (intersect_index == 0)
    {
        cout << "\n\nIntersection Array:\n";
        display_array(intersection_arr, intersect_index);
    }
    else
    {
        cout << "No Common Elements found";
    }
    return 0;
}