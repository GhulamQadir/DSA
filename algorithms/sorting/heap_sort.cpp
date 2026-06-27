#include <iostream>
using namespace std;
#include <vector>

// Global vector to store heap elements
vector<int> heap_arr;

// Restores the heap property by moving an element UP the tree.
// Used after inserting a new element at the bottom.
void up_heapify(int curr_idx, int parent)
{
    // If the current element is larger than its parent, swap them (Max-Heap rule)
    if (heap_arr[curr_idx] > heap_arr[parent])
    {
        int temp = heap_arr[curr_idx];
        heap_arr[curr_idx] = heap_arr[parent];
        heap_arr[parent] = temp;

        // Recursively check the new parent until we reach the root (index 0)
        if (parent != 0)
        {
            int curr = parent;
            int new_parent = (curr - 1) / 2;
            up_heapify(curr, new_parent);
        }
    }
    return;
}

// Adds a new element to the heap.
void insert(int element)
{
    // Step 1: Add the element to the very end of the array
    heap_arr.push_back(element);

    int curr_idx = heap_arr.size() - 1;
    int parent = (heap_arr.size() - 1) / 2;

    // Step 2: "Bubble up" the element to its correct position
    if (curr_idx > 0)
    {
        up_heapify(curr_idx, parent);
    }
}

// Restores the heap property by moving an element DOWN the tree.
// Used after the root is replaced by the last element during a pop.
void down_heapify(int index, int new_size)
{
    int child1 = 2 * index + 1; // Left child index
    int child2 = 2 * index + 2; // Right child index

    // Base case: If the node has no left child, it's a leaf node; stop.
    if (child1 >= new_size)
    {
        return;
    }

    int greatest = -1;

    // Case 1: Only left child exists
    if (child2 >= new_size)
    {
        greatest = child1;
    }
    // Case 2: Both children exist; find the larger of the two
    else
    {
        greatest = child2;
        if (heap_arr[child1] > heap_arr[child2])
        {
            greatest = child1;
        }
    }

    // If the largest child is greater than the parent, swap and continue down
    if (heap_arr[index] < heap_arr[greatest])
    {
        int temp = heap_arr[index];
        heap_arr[index] = heap_arr[greatest];
        heap_arr[greatest] = temp;
        down_heapify(greatest, new_size);
    }
    return;
}

void heap_sort()
{
    // loop till second last element because the last element because the 
    // last element will automatically reach its correct position at the end
    for (int i = 0; i < heap_arr.size() - 1; i++)
    {
        int updated_heap_size = heap_arr.size() - i - 1;
        int temp = heap_arr[updated_heap_size];
        heap_arr[updated_heap_size] = heap_arr[0];
        heap_arr[0] = temp;
        down_heapify(0, updated_heap_size);
    }
}

void display()
{
    cout << endl;
    for (int i = 0; i < heap_arr.size(); i++)
    {
        cout << heap_arr[i] << "   ";
    }
    cout << "\n\n";
}

int main()
{
    const int arr_size = 9;
    int arr[arr_size] = {43, 90, 42, 65, 87, 27, 80, 76, 49};
    for (int i = 0; i < arr_size; i++)
    {
        insert(arr[i]);
    }

    display();

    heap_sort();

    display();
}