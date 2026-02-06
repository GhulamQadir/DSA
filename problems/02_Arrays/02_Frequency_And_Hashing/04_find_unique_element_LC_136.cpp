#include <iostream>
using namespace std;

void sort(int arr[], int &arr_len)
{

    for (int i = 1; i < arr_len; i++)
    {
        int gap = i - 1;
        int current_element = arr[i];
        int shifting_position = i;

        while (gap >= 0)
        {
            if (current_element < arr[gap])
            {
                arr[gap + 1] = arr[gap];
                shifting_position = gap;
                gap--;
            }
            else
            {
                break;
            }
        }
        arr[shifting_position] = current_element;
    }
}

void display(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << ", ";
    }
}

// int main()
// {
//     // Given a non-empty array of integers nums, every element appears twice
//     // except for one. Find that single one.
//     // Trick: array hamesha odd size ma hogi qk even ma kabhi bhi single element unique or baqi sab twice nhi hoskty
//     int arr[] = {4, 2, 10, 15, 05, 4, 13, 10, 16, 2, 16, 15, 05};
//     int arr_len = sizeof(arr) / sizeof(arr[0]);

//     sort(arr, arr_len);
//     display(arr, arr_len);

//     int unique_element = -1;
//     int i = 0;
//     cout << endl;
//     while (i < arr_len - 1)
//     {
//         if (arr[i] == arr[i + 1])
//         {
//             i += 2;
//             continue;
//         }
//         unique_element = arr[i];
//         break;
//     }
//     if (unique_element == -1)
//     {
//         unique_element = arr[i];
//     }
//     cout << "\nUnique element: " << unique_element;
// }

int main()
{
    int arr[] = {4, 2, 10, 15, 05, 4, 13, 10, 16, 2, 16, 15, 05};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    int unique = 0;
    for (int i = 0; i < arr_len; i++)
    {
        unique = unique ^ arr[i];
    }
    cout<<"Unique Element: "<<unique;
}