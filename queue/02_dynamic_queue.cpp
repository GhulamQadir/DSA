#include <iostream>
using namespace std;

struct QNode
{
    int data;
    QNode *next;
};

QNode *front = nullptr;
QNode *rear = nullptr;

void enqueue(int value)
{
    // Create a new node in dynamic memory (Heap)
    QNode *new_node = new QNode();
    new_node->data = value;
    new_node->next = nullptr;

    // Case: If queue is empty, the new node becomes both front and rear
    if (front == nullptr)
    {
        front = new_node;
        rear = new_node;
        return;
    }

    // Link the current rear's next to the new node and update rear
    rear->next = new_node;
    rear = new_node;
}

int dequeue()
{
    // Underflow check: If front is null, queue is empty
    if (front == nullptr)
    {
        cout << "Queue is Empty: ";
        return -1;
    }

    // Temporary pointer to hold the current front for deletion
    QNode *temp = front;
    int val_to_return = temp->data;

    // Move front to the next node in the list
    front = front->next;

    // If front becomes null, the queue is empty, so reset rear as well
    if (front == nullptr)
    {
        rear = nullptr;
    }

    // Free the memory of the dequeued node
    delete temp;
    return val_to_return;
}

void display()
{
    if (front == nullptr)
    {
        cout << "Queue is empty: ";
        return;
    }
    QNode *current = front;
    while (current != nullptr)
    {
        cout << current->data << "\n";
        current = current->next;
    }
    return;
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Enqueue \n2. Dequeue\n3. Display\n4. Exit:\n";
        cin >> num;
        if (num == 1)
        {
            cout << "Enter value to add: ";
            int n;
            cin >> n;
            enqueue(n);
        }
        else if (num == 2)
        {
            cout << dequeue();
        }

        else if (num == 3)
        {
            cout << "Queue: \n";
            display();
        }
        else
        {
            break;
        }
    }
}