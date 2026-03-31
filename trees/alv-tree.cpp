#include <iostream>
using namespace std;
#include <cstdlib>

struct AVLTree
{
    AVLTree *left;
    AVLTree *right;
    int value;
    int height = 0;
};

AVLTree *root = nullptr;

int height(AVLTree *node)
{
    return node == nullptr ? -1 : node->height;
}

AVLTree *rotateLeft(AVLTree *root)
{
    AVLTree *temp = root->right;
    root->right = temp->left;
    root->height = 1 + max(height(root->left), height(root->right));
    temp->left = root;
    temp->height = 1 + max(height(temp->left), height(temp->right));
    return temp;
}

AVLTree *rotateRight(AVLTree *root)
{
    AVLTree *temp = root->left;
    root->left = temp->right;
    root->height = 1 + max(height(root->left), height(root->right));
    temp->right = root;
    temp->height = 1 + max(height(temp->left), height(temp->right));
    return temp;
}

AVLTree *insert(AVLTree *current, int value)
{
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
        int difference = height(current->left) - height(current->right);
        if (abs(difference) == 2)
        {
            if (value < current->left->value)
            {
                current = rotateRight(current);
            }
            else
            {
                current->left = rotateLeft(current->left);
                current = rotateRight(current);
            }
        }
    }
    else
    {
        current->right = insert(current->right, value);
        int difference = height(current->left) - height(current->right);
        if (abs(difference) == 2)
        {
            if (value > current->right->value)
            {
                current = rotateLeft(current);
            }
            else
            {
                current->right = rotateRight(current->right);
                current = rotateLeft(current);
            }
        }
    }
    current->height = 1 + max(height(current->left), height(current->right));
    return current;
}

AVLTree *delete_val(AVLTree *current, int val_to_delete)
{
    if (current == nullptr)
    {
        cout << "Value not found";
        return nullptr;
    }
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
        // having 0 children (leaf node case)
        if (current->left == nullptr && current->right == nullptr)
        {
            delete current;
            return nullptr;
        }
        // having single child case
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
        // having 2 children
        else
        {
            AVLTree *temp = current->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            current->value = temp->value;

            current->right = delete_val(current->right, temp->value);
        }
    }
    
    current->height = 1 + max(height(current->left), height(current->right));
    int balance = height(current->left) - height(current->right);

    // LEFT HEAVY
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
    // RIGHT HEAVY
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

int main()
{
    while (true)
    {
        cout << "\n\n1. Insertion\n2. Delete\n";
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
        else
        {
            break;
        }
    }
}