#include <iostream>
using namespace std;
#include <string>

// Global Hash Table - Initialized with -1 to represent empty data
int hashTable[10] = {-1};
int ht_length = sizeof(hashTable) / sizeof(hashTable[0]);

// States: "empty", "occupied", "deleted"
string ht_flags[10] = {};
int total_elements_inserted = 0;

void linear_probing_insert(int n)
{
    // Prevent insertion if table is physically full
    if (total_elements_inserted == ht_length)
    {
        cout << "HashTable is full";
        return;
    }
    int index = n % ht_length; // Initial Hash function

    // Linear Search for the next available slot
    // We stop at "empty" OR "deleted" slots to insert new data
    while (ht_flags[index] == "occupied")
    {
        index = (index + 1) % ht_length; // Move to the next slot (circularly)
    }
    hashTable[index] = n;
    ht_flags[index] = "occupied";
    total_elements_inserted++;
}

int linear_delete(int value)
{
    int index = value % ht_length;
    int start = index;

    // Search continues as long as we don't hit a "truly empty" slot
    while (ht_flags[index] != "empty")
    {
        // Only delete if data matches AND the slot is currently active
        if (hashTable[index] == value && ht_flags[index] == "occupied")
        {
            hashTable[index] = -1;       // Clear the data
            ht_flags[index] = "deleted"; // update flag
            total_elements_inserted--;
            return index;
        }
        index = (index + 1) % ht_length;

        // Safety break: if we wrap around to the start, the element isn't there
        if (start == index)
        {
            break;
        }
    }
    return -1; // Value not found
}

int linear_search(int n)
{
    int index = n % ht_length;
    int start = index;

    // A "never-occupied" empty slot means the search can stop
    while (ht_flags[index] != "empty")
    {
        // Must check if the slot is "occupied" because the value
        // at a "deleted" slot might still be the old data
        if (ht_flags[index] == "occupied" && hashTable[index] == n)
        {
            return index;
        }
        index = (index + 1) % ht_length;

        if (start == index)
        {
            break;
        }
    }
    return -1;
}

void display()
{
    for (int i = 0; i < ht_length; i++)
    {
        cout << hashTable[i] << "  ";
    }
}

int main()
{
    // Initialize all flags to "empty"
    for (int i = 0; i < 10; i++)
    {
        ht_flags[i] = "empty";
    }
    linear_probing_insert(37);
    linear_probing_insert(44);
    linear_probing_insert(100);
    linear_probing_insert(98);
    linear_probing_insert(99);
    linear_probing_insert(24);
    linear_probing_insert(47);
    linear_probing_insert(33);
    linear_probing_insert(25);

    int search_element = linear_search(98);
    if (search_element < 0)
    {
        cout << "Element not found\n";
    }
    else
    {
        cout << "Element found at index: " << search_element << "\n";
    }
    display();
}