#include <iostream>
using namespace std;

struct ListNode
{
    int value;
    ListNode *next;
};

ListNode *head = nullptr;

// Adds a new node at the beginning of the list.
void push(int val)
{
    ListNode *new_node = new ListNode();
    new_node->value = val;
    new_node->next = head; // Point new node to current head
    head = new_node;       // Make new node the new head
}

// Detects if a cycle exists using Floyd's Cycle-Finding Algorithm.
bool hasCycle()
{
    // If list is empty or has only one node, a cycle is impossible
    if (head == nullptr || head->next == nullptr)
    {
        return false;
    }

    // Slow moves 1 step at a time, Fast moves 2 steps
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (slow != nullptr && fast != nullptr)
    {
        // If slow and fast meet, it confirms a loop exists
        if (slow == fast)
        {
            cout << "Loop has cycle";
            return true;
        }
        slow = slow->next; // Move 1 step
        fast = fast->next; // Move first half of the 2-step jump

        // Safety check before the second half of the jump to avoid crash
        if (fast != nullptr)
        {
            fast = fast->next;
        }
    }
    return false;
}

// Manually creates a cycle for testing purposes.
// Connects the last node (tail) to a previous node at a given index.
void createCycle(int index)
{
    if (head == nullptr)
        return;

    ListNode *temp = head;
    ListNode *cycleNode = nullptr;
    ListNode *tail = head;

    int count = 0;
    // 1. Find the node at the given index and the last node (tail)
    while (tail->next != nullptr)
    {
        if (count == index)
        {
            cycleNode = tail; // This is where the loop will point back to
        }
        tail = tail->next;
        count++;
    }

    // Special case: if index was the last node itself
    if (count == index)
        cycleNode = tail;

    // 2. Create the loop
    if (cycleNode != nullptr)
    {
        tail->next = cycleNode; // Tail now points to an internal node instead of NULL
        cout << "\nCycle created pointing back to node at index " << index << endl;
    }
    else
    {
        cout << "\nInvalid index! Cycle not created." << endl;
    }
}
int main()
{
    while (true)
    {
        cout << "Which operation do you want to perform?\n1. Push\n2. Check Cycle?\n";
        int ch;
        cin >> ch;
        if (ch == 1)
        {
            int value;
            cout << "Enter Value to push: ";
            cin >> value;
            push(value);
        }
        else if (ch == 2)
        {
            cout << "\nStatus: " << (hasCycle() ? "True" : "False") << endl;
        }
        else if (ch == 3)
        {
            int idx;
            cout << "Enter index to point the tail to (0-indexed): ";
            cin >> idx;
            createCycle(idx);
        }
        else
        {
            break;
        }
    }
}