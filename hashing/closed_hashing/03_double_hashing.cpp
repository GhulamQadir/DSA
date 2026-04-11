#include <iostream>
using namespace std;
#include <string>

// Global Configurations
const int ht_length = 11; // Using a Prime Number to avoid cycles
int hashTable[ht_length] = {0};
string ht_flags[ht_length] = {}; // States: "empty", "occupied", "deleted"
int total_elements_inserted = 0;

// Function to initialize flags (can also be done in main)
void initialize()
{
    for (int i = 0; i < ht_length; i++)
    {
        ht_flags[i] = "empty";
    }
}

// Function to Insert
void double_hashing_insert(int n)
{
    if (total_elements_inserted == ht_length)
    {
        cout << "Table Full: Cannot insert " << n << endl;
        return;
    }

    int h1 = n % ht_length; // Primary Hash
    int h2 = 7 - (n % 7);   // Secondary Hash (Step Size)
    int i = 0;
    int index = h1;

    // Iterate until we find a slot that isn't "occupied"
    // Using counter (i < ht_length) to prevent infinite loops
    while (ht_flags[index] == "occupied" && i < ht_length)
    {
        i++;
        index = (h1 + i * h2) % ht_length;
    }

    if (ht_flags[index] != "occupied")
    {
        hashTable[index] = n;
        ht_flags[index] = "occupied";
        total_elements_inserted++;
        cout << "Inserted " << n << " at Index " << index << " (Attempts: " << i + 1 << ")" << endl;
    }
}

// Function to Search using Counter Approach
int double_search(int n)
{
    int h1 = n % ht_length;
    int h2 = 7 - (n % 7);
    int i = 0;
    int index = h1;

    // Iterate up to ht_length times
    while (i < ht_length)
    {
        // If we hit an "empty" slot, it means the value was never here
        if (ht_flags[index] == "empty")
        {
            break;
        }

        // If found and it's currently occupied
        if (ht_flags[index] == "occupied" && hashTable[index] == n)
        {
            return index; // Success!
        }

        i++;
        index = (h1 + i * h2) % ht_length;
    }

    // If loop finishes or breaks, value is not found
    return -1;
}

// Function to Delete using Counter Approach
void double_delete(int n)
{
    int pos = double_search(n);

    if (pos != -1)
    {
        ht_flags[pos] = "deleted"; // Mark as deleted (tombstone)
        hashTable[pos] = -1;       // Optional: clear data
        total_elements_inserted--;
        cout << "Value " << n << " deleted from index " << pos << endl;
    }
    else
    {
        cout << "Delete Failed: Value " << n << " not found in table." << endl;
    }
}

void display()
{
    cout << "\nHash Table: ";
    for (int i = 0; i < ht_length; i++)
    {
        if (ht_flags[i] == "occupied")
            cout << hashTable[i] << " ";
        else if (ht_flags[i] == "deleted")
            cout << "DEL ";
        else
            cout << "___ ";
    }
    cout << endl;
}

int main()
{
    initialize();

    // Inserting values

    double_hashing_insert(75);
    double_hashing_insert(23);
    double_hashing_insert(79);
    double_hashing_insert(113);
    double_hashing_insert(88);
    double_hashing_insert(123);
    double_hashing_insert(153);
    double_hashing_insert(233);
    // quadratic_probing_insert(25);

    display();

    // // Search Test
    // int val = 113;
    // int s = double_search(val);
    // if (s != -1) cout << "Value " << val << " found at " << s << endl;
    // else cout << "Value " << val << " not found!" << endl;

    // // Delete Test
    // double_delete(23);
    // double_delete(999); // Value that doesn't exist

    // display();

    return 0;
}