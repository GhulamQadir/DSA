#include <iostream>
using namespace std;

// Structure for the Binary Search Tree Node
struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};

// Global root pointer, initially empty
BSTNode *root = nullptr;

// Function to insert a value into the BST recursively
BSTNode *insert(BSTNode *current, int value)
{
    // Base Case: If we reach a NULL position, create a new node
    if (current == nullptr)
    {
        BSTNode *temp = new BSTNode();
        temp->data = value;
        temp->left = temp->right = nullptr;
        return temp;
    }

    // If value is smaller, move to the left subtree
    if (value < current->data)
    {
        current->left = insert(current->left, value);
    }

    // If value is larger, move to the right subtree
    else
    {
        current->right = insert(current->right, value);
    }
    return current; // Return the updated node pointer
}

// DFS Traversal: Root -> Left -> Right
void preorder_display(BSTNode *current)
{
    if (current != nullptr)
    {
        cout << current->data << "  ";
        preorder_display(current->left);
        preorder_display(current->right);
    }
}

// DFS Traversal: Left -> Right -> Root
void postorder_display(BSTNode *current)
{
    if (current != nullptr)
    {
        postorder_display(current->left);
        postorder_display(current->right);
        cout << current->data << "  ";
    }
}

// DFS Traversal: Left -> Root -> Right (Produces sorted output)
void inorder_display(BSTNode *current)
{
    if (current != nullptr)
    {
        inorder_display(current->left);
        cout << current->data << "  ";
        inorder_display(current->right);
    }
}

// Function to find a specific value in the tree
BSTNode *search(BSTNode *current, int value)
{
    if (current == nullptr)
    {
        cout << "Value Not Found";
        return current;
    }
    if (current->data == value)
    {
        cout << "Value found\n";
        cout << "Data: " << current->data << "\n";
        return current;
    }
    if (value < current->data)
    {
        return search(current->left, value);
    }
    else
    {
        return search(current->right, value);
    }
}

// Function to delete a node from the BST
BSTNode *delete_val(BSTNode *current, int value)
{
    if (current == nullptr)
    {
        cout << "Value not found\n";
        return nullptr;
    }

    // Step 1: Navigate to the node to be deleted
    if (value < current->data)
    {
        current->left = delete_val(current->left, value);
    }
    else if (value > current->data)
    {
        current->right = delete_val(current->right, value);
    }

    // Node found: Handling deletion cases
    else
    {
        // Case 1: Leaf Node (No children)
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }

        // Case 2: Having 1 Child
        else if ((current->left != nullptr && current->right == nullptr) || (current->left == nullptr && current->right != nullptr))
        {
            // Pick the existing child (left or right)
            BSTNode *temp = current->left != nullptr ? current->left : current->right;
            delete current; // Delete current node
            return temp;    // Link the child directly to the grandparent
        }

        // Having 2 children
        else if (current->left != nullptr && current->right != nullptr)
        {
            // Find Inorder Successor (Smallest value in the right subtree)
            BSTNode *temp = current->right;
            while (temp->left != nullptr)
            {
                temp = temp->left;
            }

            // Replace current node's data with successor's data
            current->data = temp->data;

            // Delete the successor node from the right subtree
            current->right = delete_val(current->right, temp->data);
        }
    }
    return current;
}

int main()
{
    while (true)
    {
        int num;
        cout << "\n\nWhich operation do you want to perform:\n1. Insert\n2. Delete\n3. Search\n4. Inorder Display\n5. Preorder Display\n6. Postorder Display\n7. Display Tree\n";
        cin >> num;

        if (num == 1)
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
        }
        else if (num == 2)
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            root = delete_val(root, value);
        }
        else if (num == 3)
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            search(root, value);
        }
        else if (num == 4)
        {
            inorder_display(root);
        }
        else if (num == 5)
        {
            preorder_display(root);
        }
        else if (num == 6)
        {
            postorder_display(root);
        }
        else
        {
            break;
        }
    }
}