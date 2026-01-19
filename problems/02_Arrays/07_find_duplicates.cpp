#include <iostream>
using namespace std;

void display_array(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "  ";
    }
}

void sorting(int arr[], int arr_len)
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

int main()
{
    int arr[8] = {4, 3, 2, 7, 8, 2, 3, 1};
    int arr_length = sizeof(arr) / sizeof(int);
    int duplicates_arr[arr_length];
    int duplicates_index = 0;

    sorting(arr, &arr_length);

    cout << "Original Array:\n";
    display_array(arr, arr_length);

    for (int i = 1; i < arr_length; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            duplicates_arr[duplicates_index] = arr[i];
            duplicates_index++;
        }
    }

    cout << "\n\nDuplicates Array:\n";
    display_array(duplicates_arr, duplicates_index);
    return 0;
}