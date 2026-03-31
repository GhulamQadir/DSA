#include <iostream>
using namespace std;

// Structure for AVL Tree Node
struct AVLTree
{
    AVLTree *left;
    AVLTree *right;
    int value;
    int height = 0; // Height of the node (used for balancing)
};

AVLTree *root = nullptr;

// Helper function to get the height of a node safely
int height(AVLTree *node)
{
    return node == nullptr ? -1 : node->height;
}

// Left Rotation: Used when the right child is heavy
AVLTree *rotateLeft(AVLTree *root)
{
    AVLTree *temp = root->right;
    root->right = temp->left;
    // Update height of the old root first
    root->height = 1 + max(height(root->left), height(root->right));
    temp->left = root;
    // Update height of the new root
    temp->height = 1 + max(height(temp->left), height(temp->right));
    return temp;
}

// Right Rotation: Used when the left child is heavy
AVLTree *rotateRight(AVLTree *root)
{
    AVLTree *temp = root->left;
    root->left = temp->right;
    // Update height of the old root first
    root->height = 1 + max(height(root->left), height(root->right));
    temp->right = root;
    // Update height of the new root
    temp->height = 1 + max(height(temp->left), height(temp->right));
    return temp;
}

// Function to insert a value and maintain balance
AVLTree *insert(AVLTree *current, int value)
{
    // Standard BST Insertion
    if (current == nullptr)
    {
        AVLTree *temp = new AVLTree();
        temp->value = value;
        temp->left = temp->right = nullptr;
        temp->height = 0;
        return temp;
    }
    if (value < current->value)
    {
        current->left = insert(current->left, value);

        // Rebalancing if the left side becomes too heavy
        int difference = height(current->left) - height(current->right);
        if (abs(difference) == 2)
        {
            if (value < current->left->value) // Left-Left Case
            {
                current = rotateRight(current);
            }
            else // Left-Right Case
            {
                current->left = rotateLeft(current->left);
                current = rotateRight(current);
            }
        }
    }
    else
    {
        current->right = insert(current->right, value);

        // Rebalancing if the right side becomes too heavy
        int difference = height(current->left) - height(current->right);
        if (abs(difference) == 2)
        {
            if (value > current->right->value) // Right-Right Case
            {
                current = rotateLeft(current);
            }
            else // Right-Left Case
            {
                current->right = rotateRight(current->right);
                current = rotateLeft(current);
            }
        }
    }
    // Update height after insertion and possible rotations
    current->height = 1 + max(height(current->left), height(current->right));
    return current;
}

// Function to delete a node and maintain AVL property
AVLTree *delete_val(AVLTree *current, int val_to_delete)
{
    if (current == nullptr)
    {
        cout << "Value not found";
        return nullptr;
    }

    // Step 1: Standard BST Deletion logic
    else if (val_to_delete < current->value)
    {
        current->left = delete_val(current->left, val_to_delete);
    }
    else if (val_to_delete > current->value)
    {
        current->right = delete_val(current->right, val_to_delete);
    }
    else
    {
        // Case 1: Leaf Node (No children)
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }
        // Case 2: Single Child
        else if ((current->left != nullptr && current->right == nullptr) || (current->left == nullptr && current->right != nullptr))
        {
            if (current->left != nullptr)
            {
                AVLTree *temp = current;
                current = temp->left;
                delete temp;
            }
            else
            {
                AVLTree *temp = current;
                current = temp->right;
                delete temp;
            }
        }
        // Case 3: Two Children
        else
        {
            // Find Inorder Successor (Smallest in the right subtree)
            AVLTree *temp = current->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            current->value = temp->value;

            current->right = delete_val(current->right, temp->value);
        }
    }

    // Step 2: Update height and check balance factor for rebalancing
    current->height = 1 + max(height(current->left), height(current->right));
    int balance = height(current->left) - height(current->right);

    // Left Heavy Cases
    if (balance > 1)
    {
        // left-left Case
        if (height(current->left->left) >= height(current->left->right))
        {
            return rotateRight(current);
        }
        // left-right case
        else
        {
            current->left = rotateLeft(current);
            return rotateRight(current);
        }
    }
    // Right Heavy Cases
    else if (balance < -1)
    {
        // right-right Case
        if (height(current->right->right) >= height(current->right->left))
        {
            return rotateLeft(current);
        }
        // right-left Case
        else
        {
            current->right = rotateRight(current);
            return rotateLeft(current);
        }
    }
    return current;
}

// Display: Root -> Left -> Right
void preorder_display(AVLTree *current)
{
    if (current != nullptr)
    {
        cout << current->value << "  ";
        preorder_display(current->left);
        preorder_display(current->right);
    }
}
// Display: Left -> Right -> Root
void postorder_display(AVLTree *current)
{
    if (current != nullptr)
    {
        postorder_display(current->left);
        postorder_display(current->right);
        cout << current->value << "  ";
    }
}

// Display: Left -> Root -> Right (Sorted Output)
void inorder_display(AVLTree *current)
{
    if (current != nullptr)
    {
        inorder_display(current->left);
        cout << current->value << "  ";
        inorder_display(current->right);
    }
}

int main()
{
    while (true)
    {
        cout << "\nBalanced BST (AVL Tree)\n\n1. Insertion\n2. Delete\n3. PreOrder Display\n4. PostOrder Display\n5. InOrder Display\n";
        int num;
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
            preorder_display(root);
        }
        else if (num == 4)
        {
            postorder_display(root);
        }
        else if (num == 5)
        {
            inorder_display(root);
        }
        else
        {
            break;
        }
    }
}