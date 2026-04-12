#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next; // Points to the next node, or back to head if it's the last node
};

Node *head; // Global head pointer

// Function to insert a new node at the end of the circular list
void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    // Case 1: If the list is empty
    if (head == nullptr)
    {
        head = newNode;
        head->next = newNode; // Points to itself to maintain circularity
        return;
    }

    // Case 2: Traverse to find the current last node
    Node *temp = head;
    // In CLL, the last node's next is always head
    while (temp->next != head)
    {
        temp = temp->next;
    }
    // Link the old last node to the new node
    temp->next = newNode;
    // Link the new node back to head to complete the circle
    newNode->next = head;
}

void display()
{
    Node *temp = head;
    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;

    } while (temp != head);
}

// Function to delete a node by its value
void del(int value)
{
    if (head == nullptr)
    {
        cout << "List is empty";
        return;
    }

    Node *current = head;

    // Case 1: Deleting the Head node
    if (head->data == value)
    {
        // Sub-case: Only one node exists in the list
        if (head->next == head)
        {
            delete head;
            head = nullptr; // Reset head to prevent dangling pointer
            return;
        }

        // Find the last node to update its 'next' pointer before deleting head
        while (current->next != head)
        {
            current = current->next;
        }

        Node *temp = head;    // Save old head to delete it later
        head = head->next;    // Move head to the second node
        current->next = head; // Last node now points to the new head
        delete temp;
        return;
    }
    else
    {
        // Case 2: Deleting a node other than the head
        Node *previous = current;
        current = current->next;

        // Search for the value in the rest of the list
        while (current->data != value)
        {
            // If we've circled back to head, the value isn't in the list
            if (current == head)
            {
                cout << "Value Not Found";
                return;
            }
            // Skip the 'current' node to remove it from the sequence
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
    }
    display();
}

// Function to search for a value and print its index
void search(int value)
{
    Node *current = head;
    int i = 0;
    while (true)
    {
        if (value == current->data)
        {
            cout << "Value found at index " << i << endl;
            return;
        }
        if (current->next == head && value != current->data)
        {
            cout << "Value not found" << endl;
            return;
        }
        current = current->next;
        i++;
    }
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Add\n2. Display\n3. Delete\n4. Search\n5.Exit:\n";
        cin >> num;

        if (num == 1)
        {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            insertAtEnd(value);
        }
        else if (num == 2)
        {
            cout << "Display: ";
            display();
        }
        else if (num == 3)
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            del(value);
        }
        else if (num == 4)
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
        }
        else if (num == 5)
        {
            break;
        }
    }
    return 0;
}
