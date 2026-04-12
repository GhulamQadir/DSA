#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *previous;
};

Node *head; // Global pointer to the start of the list

// Function to add a node at the very end of the list
void insertAtEnd(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->previous = nullptr;

    // Case 1: If list is empty, make new node the head
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Case 2: Traverse to the last node
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    // Update pointers to link the new node
    temp->next = newNode;     // Link current last node to the new node
    newNode->previous = temp; // Link new node back to the previous last node
}

void display()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// Function to delete a node with a specific value
void del(int value)
{
    if (head == nullptr)
    {
        return;
    }

    // Case 1: Deleting the Head node
    Node *current = head;
    if (value == head->data)
    {
        head = head->next;        // Move head to the second node
        head->previous = nullptr; // Disconnect the old head
        delete current;
        return;
    }

    // Case 2: Deleting middle or last node
    current = current->next; // Start searching from the second node
    while (current != nullptr)
    {
        if (current->data == value)
        {
            Node *previous = current->previous;

            // Scenario A: If it's the last node
            if (current->next == nullptr)
            {
                previous->next = nullptr;
            }
            // Scenario B: If it's a middle node
            else
            {
                previous->next = current->next;     // Link previous node to the next one
                current->next->previous = previous; // Link next node back to the previous one
            }
            delete current; // Free memory
            return;
        }
        current = current->next;
    }
    display();
}

// Function to search for a value and return its position
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
        if (current->next == nullptr && value != current->data)
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
