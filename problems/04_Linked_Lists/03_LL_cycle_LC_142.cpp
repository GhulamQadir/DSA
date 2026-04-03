// Problem: LeetCode 142 - Linked List Cycle II
// Logic: Floyd's Cycle-Finding Algorithm
// Equation: L1 = C - L2 (Distance from head to start == Distance from meeting point to start)

#include <iostream>

struct ListNode
{
    int value;
    ListNode *next;
};

// Function to detect and return the node where the cycle begins
ListNode *detectCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    ListNode *slow = head;
    ListNode *fast = head;

    // Phase 1: Determine if a cycle exists
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            // Phase 2: Find the entry point of the cycle
            ListNode *entry = head;
            while (entry != slow)
            {
                entry = entry->next;
                slow = slow->next;
            }
            return entry; // This is the start of the cycle
        }
    }
    return nullptr; // No cycle found
}