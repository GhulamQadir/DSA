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

// Fills an array with the frequency count of each unique number
int count_occurences(int occurence_arr[], int sorted_arr[], int arr_length)
{
    int occu_index = 0;
    for (int i = 1; i < arr_length; i++)
    {
        if (sorted_arr[i] == sorted_arr[i - 1])
        {
            occurence_arr[occu_index]++; // Increment count if same number repeats
        }
        else
        {
            occu_index++; // Move to next slot for a new number
            occurence_arr[occu_index]++;
        }
    }
    return occu_index; // Returns index of last recorded occurrence
}

int main()
{
    // Check if the number of occurrences of each value in the array is unique.
    // Return true if all counts are different, otherwise return false.
    int arr[12] = {2, 4, 9, 17, 2, 8, 6, 3, 12, 17, 16, 9};
    int arr_length = sizeof(arr) / sizeof(int);

    cout << "Array:\n";
    display_array(arr, arr_length);
    cout << endl;

    sorting(arr, arr_length); // Step 1: Sort the main array

    int occurence_count_arr[arr_length] = {0};
    occurence_count_arr[0] = 1; // Start counting the first number
    int occu_arr_last_index = count_occurences(occurence_count_arr, arr, arr_length);

    display_array(occurence_count_arr, occu_arr_last_index + 1);

    sorting(occurence_count_arr, occu_arr_last_index + 1); // Step 2: Sort the counts themselves
    cout << endl;

    // Step 3: Check if any adjacent counts are identical
    for (int i = 1; i < occu_arr_last_index + 1; i++)
    {
        if (occurence_count_arr[i] == occurence_count_arr[i - 1])
        {
            cout << boolalpha << false; // Found duplicate occurrence count
            return 0;
        }
    }
    cout << boolalpha << true; // All occurrence counts were unique

    return 0;
}