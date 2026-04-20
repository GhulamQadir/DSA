#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node *next;
};

int length = 0;       // Keeps track of the total number of elements
Node *head = nullptr; // Points to the first node
Node *tail = nullptr; // Points to the last node for efficient tail operations

// Adds a new node with value before the first element of the linked list
void addAtHead(int val)
{
    Node *new_node = new Node();
    new_node->val = val;
    new_node->next = head;

    head = new_node;
    length++;

    // If the list was empty, the new node is also the tail
    if (tail == nullptr)
    {
        tail = head;
    }
}

// Appends a node with value 'val' to the last element of the linked list
void addAtTail(int val)
{
    Node *new_node = new Node();
    new_node->val = val;
    new_node->next = nullptr;
    length++;

    // If list is empty, new node becomes both head and tail
    if (tail == nullptr)
    {
        head = tail = new_node;
        return;
    }
    // Link current tail to new node and update tail pointer
    tail->next = new_node;
    tail = new_node;
}

// Add a node of value 'val' before the index-th node in the linked list
// If index equals size, the node is appended to the end of the list
void addAtIndex(int index, int val)
{
    // Case: Index is out of valid bounds
    if (index > length || index < 0)
    {
        return;
    }
    // Case: Adding at the end (Tail)
    else if (index == length)
    {
        addAtTail(val);
    }
    // Case: Adding at the start (Head)
    else if (index == 0)
    {
        addAtHead(val);
    }
    // Case: Inserting in the middle
    else
    {
        int i = 0;
        Node *previous = nullptr;
        Node *current = head;

        // Traverse to the specified index
        while (i < index)
        {
            previous = current;
            current = current->next;
            i++;
        }
        Node *new_node = new Node();
        new_node->val = val;
        new_node->next = current;  // Point new node to current node at index
        previous->next = new_node; // Link previous node to new node
        length++;
    }
}

// Delete the index-th node in the linked list, if the index is valid
void deleteAtIndex(int index)
{
    // Invalid index check
    if (index >= length || index < 0)
    {
        return;
    }
    // Case: Deleting the Head node
    else if (index == 0)
    {
        Node *temp = head;
        head = head->next;
        // If list becomes empty after deletion, update tail
        if (head == nullptr)
        {
            tail = nullptr;
        }
        delete temp;
    }
    // Case: Deleting a node after the head
    else
    {
        int i = 0;
        Node *current = head;
        Node *previous = current;

        // Traverse to find the node to delete
        while (i < index)
        {
            previous = current;
            current = current->next;
            i++;
        }
        // Unlink the node from the list
        previous->next = current->next;

        // If we deleted the last node, update the tail pointer
        if (index == length - 1)
        {
            tail = previous;
        }
        delete current;
    }
    length--; // Decrement list size
}

// Get the value of the index-th node. If index is invalid, return -1
int get_by_index(int index)
{
    if (index >= length || index < 0)
    {
        return -1;
    }
    int i = 0;
    Node *current = head;

    // Walk through the list until reaching the index
    while (i < index)
    {
        current = current->next;
        i++;
    }
    return current->val;
}

void display()
{
    if (head == nullptr)
    {
        cout << "List is empty";
        return;
    }
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->val << "   ";
        current = current->next;
    }
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Add at head\n2. Add at tail\n3. Add at index\n4. Delete by index\n5. Get By Index\n6. Display\n7. Exit:\n";
        cin >> num;

        if (num == 1)
        {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            addAtHead(value);
        }
        else if (num == 2)
        {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            addAtTail(value);
        }
        else if (num == 3)
        {
            int index;
            cout << "Enter index ";
            cin >> index;

            int value;
            cout << "Enter value to add: ";
            cin >> value;
            addAtIndex(index, value);
        }
        else if (num == 4)
        {
            int index;
            cout << "Enter index: ";
            cin >> index;
            deleteAtIndex(index);
        }

        else if (num == 5)
        {
            int index;
            cout << "Enter index: ";
            cin >> index;
            cout << get_by_index(index);
        }
        else if (num == 6)
        {
            display();
        }
        else
        {
            break;
        }
    }
    return 0;
}
