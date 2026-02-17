#include <iostream>
using namespace std;

// Structure for a Node in the Linked List
struct Node
{
    int data;   // To store the integer value
    Node *next; // Pointer to the next node in the sequence
};

Node *head = NULL; // Global head pointer, initialized to NULL (Empty List)

// Function to add a node at the end of the list (Tail Insertion)
void add(int value)
{
    Node *newNode = new Node(); // Dynamically allocate memory for new node
    newNode->data = value;
    newNode->next = NULL;

    // If list is empty, make the new node the head
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    // Traverse to the last node
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode; // Link the last node to the new node
}

// Function to display the list from start to end
void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

// Function to print the list in reverse using Recursion
void display_reverse(Node *ptr)
{
    if (ptr == NULL) // Base Case: Stop if pointer is NULL
    {
        return;
    }

    display_reverse(ptr->next); // Recursive Call: Move to the end of list
    cout << ptr->data << "  ";  // Backtracking: Print data while returning
}

// Function to delete a specific value from the list
void delete_val(int value)
{
    if (head == NULL)
    {
        cout << "List is Empty";
        return;
    }
    bool valueFound = false;

    // CASE 1: Value found at the Head node
    if (head->data == value)
    {
        Node *temp = head;
        head = head->next; // Move head to the next node
        valueFound = true;
        delete temp; // Deallocate memory
    }
    // CASE 2: Value might be in the middle or end
    else
    {
        Node *previous = head;
        Node *current = head->next;
        while (current != NULL)
        {
            if (current->data == value)
            {
                Node *temp = current;
                previous->next = current->next; // Bypass the current node
                free(temp);
                valueFound = true;
                break;
            }
            previous = current;
            current = current->next;
        }
    }
    if (!valueFound)
    {
        cout << "Value Not Found\n";
    }
    else
    {
        cout << value << " deleted successfully\n";
    }
    display();
}

// Function to search for a value and return its index
void search(int value)
{
    Node *current = head;
    int i = 0;
    while (current != NULL)
    {
        if (value == current->data)
        {
            cout << "Value found at index " << i << endl;
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
        cout << "\n\nWhich operation do you want to perform:\n1. Add\n2. Delete\n3. Search\n4. Display\n5. Display Reverse\n6. Exit:\n";
        cin >> num;

        if (num == 1)
        {
            int value;
            cout << "Enter value to add: ";
            cin >> value;
            add(value);
        }
        else if (num == 2)
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            delete_val(value);
        }
        else if (num == 3)
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
        }
        else if (num == 4)
        {
            display();
        }
        else if (num == 5)
        {
            display_reverse(head);
        }
        else
        {
            break;
        }
    }
    return 0;
}
