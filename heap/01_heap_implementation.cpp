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
void down_heapify(int index)
{
    int child1 = 2 * index + 1; // Left child index
    int child2 = 2 * index + 2; // Right child index

    // Base case: If the node has no left child, it's a leaf node; stop.
    if (child1 >= heap_arr.size())
    {
        return;
    }

    int greatest = -1;

    // Case 1: Only left child exists
    if (child2 >= heap_arr.size())
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
        down_heapify(greatest);
    }
    return;
}

// Removes and returns the maximum element (the root) from the heap.
int pop()
{
    if (heap_arr.size() == 0)
    {
        cout << "Heap is Empty";
        return -1;
    }

    int element_to_pop = heap_arr[0];

    // Special case: Only one element in heap
    if (heap_arr.size() == 1)
    {
        heap_arr.pop_back();
        return element_to_pop;
    }

    // Step 1: Move the last element in the array to the root position
    heap_arr[0] = heap_arr[heap_arr.size() - 1];

    // If there were only two elements, just remove the last one and skip down_heapify
    if (heap_arr.size() == 2)
    {
        heap_arr.pop_back();
        return element_to_pop;
    }

    // Step 2: Remove the last element and "trickle down" the new root to restore order
    heap_arr.pop_back();
    down_heapify(0);

    return element_to_pop;
}

// Simple utility to print the array representation of the heap.
void display()
{
    cout << endl;
    for (int i = 0; i < heap_arr.size(); i++)
    {
        cout << heap_arr[i] << "   ";
    }
}

int main()
{
    cout << "Max-Heap Operations\n\n";
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Push \n2. Pop\n3. Display\n4. Exit:\n";
        cin >> num;
        if (num == 1)
        {
            cout << "Enter value to add: ";
            int n;
            cin >> n;
            insert(n);
        }
        else if (num == 2)
        {
            cout << "Popped value: " << pop();
        }
        else if (num == 3)
        {
            display();
        }
        else
        {
            break;
        }
    }
}