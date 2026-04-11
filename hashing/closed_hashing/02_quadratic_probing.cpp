#include <iostream>
using namespace std;
#include <string>

// Global Hash Table
int hashTable[10] = {0};
int ht_length = sizeof(hashTable) / sizeof(hashTable[0]);

// Flags to track the state of each slot: "empty", "occupied", or "deleted"
// This is essential for Linear/Quadratic probing to handle deletions correctly.
string ht_flags[10] = {};
int total_elements_inserted = 0;

void quadratic_probing_insert(int n)
{
    int i = 0;
    // Check if the table is physically full before trying to insert
    if (total_elements_inserted == ht_length)
    {
        cout << "HashTable is full";
        return;
    }
    int index = n % ht_length; // Calculate initial hash index
    int start = index;

    // Keep probing while the current slot is occupied
    while (ht_flags[index] == "occupied")
    {
        i++;
        // If we have tried as many times as there are slots, stop to avoid infinite loops
        // In Quadratic Probing, some slots might remain unreachable due to the math pattern
        if (i >= ht_length)
        {
            cout << "Slot Unreachable\n";
            return;
        }
        // Formula: (InitialIndex + i^2) % TableSize
        index = (start + (i * i)) % ht_length;
    }

    // Insert the element and update flag
    hashTable[index] = n;
    ht_flags[index] = "occupied";
    total_elements_inserted++;
}

int quadratic_delete(int value)
{
    int i = 0;
    int index = value % ht_length;
    int start = index;

    // Search continues as long as we don't hit a "truly empty" slot or exceed attempts
    while (ht_flags[index] != "empty" && i < ht_length)
    {
        // Only delete if the value matches AND the slot is currently active (occupied)
        if (hashTable[index] == value && ht_flags[index] == "occupied")
        {
            hashTable[index] = -1;       // clear the data
            ht_flags[index] = "deleted"; // Mark as deleted
            total_elements_inserted--;
            return index; // Return the index where deletion happened
        }
        i++;
        if (i >= ht_length)
        {
            cout << "Element Not found!\n";
            break;
        }
        index = (start + (i * i)) % ht_length;
    }
    return -1; // Element was not in the table
}

int quadratic_search(int n)
{
    int i = 0;
    int index = n % ht_length;
    int start = index;

    // Linear/Quadratic search must keep going over "deleted" slots
    // Search only stops when we find the key, hit a "never-occupied" empty slot, or finish ht_length attempts
    while (ht_flags[index] != "empty" && i < ht_length)
    {
        if (hashTable[index] == n && ht_flags[index] == "occupied")
        {
            return index; // Success
        }
        i++;
        if (i >= ht_length)
        {
            cout << "Element Not found!";
            break;
        }
        index = (start + (i * i)) % ht_length;
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
    for (int i = 0; i < 10; i++)
    {
        ht_flags[i] = "empty";
    }

    quadratic_probing_insert(75);
    quadratic_probing_insert(23);
    quadratic_probing_insert(79);
    quadratic_probing_insert(113);
    quadratic_probing_insert(88);
    quadratic_probing_insert(123);
    quadratic_probing_insert(153);

    // This specific element might trigger the "Slot Unreachable" logic depending on table size/math
    quadratic_probing_insert(233);
    display();
}