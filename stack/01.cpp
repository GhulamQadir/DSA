#include <iostream>
using namespace std;

struct StackNode
{
    int data;
    StackNode *next;
};

// Global pointer to the top of the stack
StackNode *top = NULL;

// Pushes an element onto the stack
// new elements are always added at the head (top)
void push(int n)
{
    // Create a new node in dynamic memory
    StackNode *new_node = new StackNode();
    new_node->data = n;

    // Case: If stack is empty, new node becomes the top
    if (top == NULL)
    {
        new_node->next = NULL;
        top = new_node;
        return;
    }

    // Link the new node to the current top and update the top pointer
    // This ensures LIFO: Last In is at the front
    new_node->next = top;
    top = new_node;
}

// Removes and returns the top element from the stack.
// Follows LIFO (Last In, First Out) principle.
int pop()
{
    // Underflow check: Cannot pop from an empty stack
    if (top == NULL)
    {
        cout << "Stack is empty";
        return -1;
    }

    // Temporary pointer to the current top to free its memory later
    StackNode *temp = top;

    // Move the top pointer to the next node in the sequence
    top = top->next;
    int temp_data = temp->data;

    // Free the memory of the removed node
    delete temp;
    return temp_data;
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Push \n2. Pop\n3. Exit:\n";
        cin >> num;
        if (num == 1)
        {
            cout << "Enter value to add: ";
            int n;
            cin >> n;
            push(n);
        }
        else if (num == 2)
        {
            cout << "Popped value: " << pop();
        }
        else
        {
            break;
        }
    }
}