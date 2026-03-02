#include <iostream>
using namespace std;

// Structure for a Node in the Linked List
struct Node
{
    int data;   // To store the integer value
    Node *next; // Pointer to the next node in the sequence
};

Node *head = nullptr; // Global head pointer, initialized to NULL (Empty List)

// Function to add a node at the end of the list (Tail Insertion)
void add(int value)
{
    Node *newNode = new Node(); // Dynamically allocate memory for new node
    newNode->data = value;
    newNode->next = nullptr;

    // If list is empty, make the new node the head
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode; // Link the last node to the new node
}

// Function to display the list from start to end
void display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}
Node *reverse(Node *current, Node *previous)
{
    // Safety check: If the list is empty
    if (current == nullptr)
    {
        return nullptr;
    }
    // BASE CASE: If we have reached the last node (the Tail)
    if (current->next == nullptr)
    {
        // 1. Point the last node back to the previous node
        current->next = previous;

        // 2. Return this node's address; it is our new Head!
        return current;
    }

    // RECURSIVE STEP:
    // We move forward until we hit the Base Case.
    // We pass 'current' as the 'previous' for the next call.
    Node *newHead = reverse(current->next, current);

    // UNWINDING PHASE (Backtracking):
    // As the recursion returns, each node updates its 'next' pointer
    // to point to its original predecessor (the 'previous' parameter).
    current->next = previous;

    // Pass the newHead pointer all the way back up to the main function
    return newHead;
}

int main()
{
    add(5);
    add(95);
    add(53);
    add(27);
    add(16);
    display();
    head = reverse(head, nullptr);
    cout << "\n";
    display();
}