#include <iostream>
using namespace std;

// Node structure for the Linked List based Stack
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

int main()
{
    string infix;
    cout << "Enter infix equation: ";
    cin >> infix;

    string postfix = generate_postfix(infix);
    display(postfix);
}