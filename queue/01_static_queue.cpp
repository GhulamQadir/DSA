#include <iostream>
using namespace std;

int front = -1, rear = -1;

int arr[4];
int arr_length = sizeof(arr) / sizeof(int);

// Adds an element to the back of the queue.
// Implements circular logic using the modulo operator.
void enqueue(int n)
{
    // Check for Queue Overflow: (rear + 1) % length == front
    // This happens when the next position of 'rear' is already occupied by 'front'
    if ((rear + 1) % arr_length == front)
    {
        cout << "\nQueue is full";
        return;
    }

    // If the queue is empty, initialize both pointers to 0
    if (front == -1)
    {
        front++;
        rear++;
    }
    else
    {
        // Move 'rear' to the next circular position
        rear = (rear + 1) % arr_length;
    }
    // Insert the element at the updated rear position
    arr[rear] = n;
}

// Removes and returns the element from the front of the queue.
int dequeue()
{
    // Check for Queue Underflow: If front is -1, the queue is empty
    if (front == -1)
    {
        cout << "Queue is empty: ";
        return -1;
    }
    int temp = arr[front];
    arr[front] = 0; // Optional: Visualizing deletion by setting to 0

    // Check if we just removed the last element in the queue
    if (front == rear)
    {
        cout << "Queue is empty: ";
        // Reset pointers to indicate an empty state
        front = -1;
        rear = -1;
    }
    else
    {
        // Move 'front' to the next circular position
        front = (front + 1) % arr_length;
    }
    return temp;
}

// Iterates and displays all indices of the static array.
void display()
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << "   ";
    }
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