#include <iostream>
using namespace std;

struct HNode
{
    int value;
    HNode *next;
};

HNode *hashTable[10] = {nullptr};
int ht_length = sizeof(hashTable) / sizeof(hashTable[0]);

void insert(int n)
{
    HNode *new_node = new HNode();
    new_node->value = n;
    new_node->next = NULL;

    int index = n % ht_length;
    if (hashTable[index] == NULL)
    {
        hashTable[index] = new_node;
        return;
    }
    HNode *current_node = hashTable[index];
    HNode *previous_node = NULL;
    while (current_node != NULL)
    {
        if (current_node->value == n)
        {
            cout << "Duplicate Value Found";
            delete new_node;
            return;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = new_node;
}

void delete_node(int n)
{
    int index = n % ht_length;
    HNode *current = hashTable[index];
    HNode *previous = NULL;

    while (current != NULL)
    {
        if (current->value == n)
        {
            // Case A: Agar pehla hi node (Head) mitaana ho
            if (previous == NULL)
            {
                hashTable[index] = current->next;
            }
            // Case B: Agar beech mein ya aakhir mein ho
            else
            {
                previous->next = current->next;
            }
            delete current;
            cout << "Value " << n << " deleted successfully." << endl;
            return;
        }
        previous = current;
        current = current->next;
    }
    cout << "Value " << n << " not found in the table." << endl;
}
int search(int n)
{
    int index = n % ht_length;
    HNode *temp = hashTable[index];

    while (temp != NULL)
    {
        if (temp->value == n)
        {
            return index;
        }
        temp = temp->next;
    }
    return -1;
}
void display()
{
    for (int i = 0; i < ht_length; i++)
    {
        cout << "Index " << i << ": ";
        HNode *temp = hashTable[i];
        while (temp != NULL)
        {
            cout << "[" << temp->value << "] -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit:\n";
        cin >> num;

        switch (num)
        {
        case 1:
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            insert(value);
            break;
        }
        case 2:
        {

            int value;
            cout << "Enter value to Delete: ";
            cin >> value;
            delete_node(value);
            break;
        }
        case 3:
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            search(value);
            break;
        }
        case 4:
        {
            display();
            break;
        }
        default:
            break;
        }
    }
}