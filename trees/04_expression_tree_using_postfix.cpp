#include <iostream>
using namespace std;

struct StackNode
{
    char value;
    StackNode *next;
};

StackNode *top = nullptr;

// Function to define operator Precedence
int precedence(char opr)
{
    switch (opr)
    {
    case '*':
    case '/':
    case '%':
        return 5; // Higher priority
    case '+':
    case '-':
        return 4;
    case '>':
    case '<':
    case '!':
    case '=':
        return 3;
    case '&':
        return 2;
    case '|':
        return 1; // Lower priority
    default:
        return 0;
    }
}

// Push operation to add an operator to the stack
void push(char value)
{
    StackNode *newNode = new StackNode();
    newNode->value = value;
    if (top == nullptr)
    {
        newNode->next = nullptr;
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

// Pop operation to remove and return the top operator
char pop()
{
    if (top == nullptr)
    {
        cout << "Stack is empty";
        return '.';
    }
    StackNode *temp = top;
    char opr = temp->value;
    top = top->next;
    delete temp;
    return opr;
}

// Main logic to convert Infix expression to Postfix
string generate_postfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        // If the character is an Operand (A-Z, a-z, or 0-9), add to output
        if ((infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122) || (infix[i] >= 48 && infix[i] <= 57))
        {
            postfix += infix[i];
        }
        else
        {
            int precedence_val = precedence(infix[i]);

            // If stack is empty and char is an operator or '(', just push it
            if (top == nullptr && (precedence_val > 0 || infix[i] == '('))
            {
                push(infix[i]);
            }
            else
            {
                // Opening bracket always goes to stack
                if (infix[i] == '(')
                {
                    push(infix[i]);
                }
                // Closing bracket pops everything until '(' is found
                else if (infix[i] == ')')
                {
                    while (top->value != '(')
                    {
                        postfix += pop();
                    }
                    pop(); // Remove '(' from stack
                }
                else
                {
                    /* While top of stack has higher or equal precedence,
                       pop it to the output string */
                    while (top != nullptr)
                    {
                        if (precedence_val <= precedence(top->value) && top->value != '(')
                        {
                            postfix += pop();
                        }
                        else
                        {
                            break;
                        }
                    }
                    push(infix[i]); // Finally, push the current operator
                }
            }
        }
    }
    // Pop all remaining operators from the stack
    while (top != nullptr)
    {
        postfix += pop();
    }
    return postfix;
}

void display(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        cout << postfix[i] << "  ";
    }
}

// Node structure for the actual Expression Tree
struct ETNode
{
    char data;
    ETNode *left;
    ETNode *right;
};

// Stack to store Tree Node pointers during Tree construction
struct TreeStackNode
{
    ETNode *node;
    TreeStackNode *next;
};

TreeStackNode *tree_stack_top = nullptr;

// Push a tree node pointer into the Tree Stack
void push_in_tree_stack(ETNode *node)
{
    TreeStackNode *new_node = new TreeStackNode();
    new_node->node = node;
    if (tree_stack_top == nullptr)
    {
        tree_stack_top = new_node;
        tree_stack_top->next = nullptr;
        return;
    }
    new_node->next = tree_stack_top;
    tree_stack_top = new_node;
}

// Pop a tree node pointer from the Tree Stack
ETNode *pop_from_tree_stack()
{
    if (tree_stack_top == nullptr)
    {
        cout << "Tree is empty";
        return nullptr;
    }
    TreeStackNode *temp = tree_stack_top;
    tree_stack_top = tree_stack_top->next;
    ETNode *node = temp->node;
    delete temp;
    return node;
}

// Logic to build the Expression Tree from Postfix
// Rules: Operands become leaves, Operators become roots of subtrees
ETNode *build_ET_Tree(string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        ETNode *new_node = new ETNode();
        int preced = precedence(postfix[i]);

        // If it's an operand, it's a leaf (no children)
        if (preced < 1)
        {
            new_node->data = postfix[i];
            new_node->left = nullptr;
            new_node->right = nullptr;
        }
        else
        {
            //  If it's an operator, pop two nodes from stack.
            //    First pop becomes RIGHT child, second pop becomes LEFT child.
            new_node->data = postfix[i];
            new_node->right = pop_from_tree_stack();
            new_node->left = pop_from_tree_stack();
        }
        // Push the newly created subtree/node back to stack
        push_in_tree_stack(new_node);
    }

    // Final node remaining in stack is the ROOT of the full tree
    ETNode *root = pop_from_tree_stack();
    if (tree_stack_top != nullptr)
    {
        cout << "Incorrect equation";
        return nullptr;
    }
    return root;
}

int main()
{
    string infix;
    cout << "Enter infix equation: ";
    cin >> infix;

    string postfix = generate_postfix(infix);
    display(postfix);

    ETNode *root = build_ET_Tree(postfix);
}