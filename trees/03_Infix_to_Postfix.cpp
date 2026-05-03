#include <iostream>
using namespace std;

// Node for the Character Stack (Used for Operators during conversion)
struct StackNode
{
    char value;
    StackNode *next;
};

// Node for the Float Stack (Used for operands during evaluation)
struct EvaluationStack
{
    float value;
    EvaluationStack *next;
};

// Global pointers for the top of the stacks
StackNode *top = nullptr;
EvaluationStack *eval_top = nullptr;

// Pushes a numeric value onto the evaluation stack
void eval_push(float value)
{
    EvaluationStack *newNode = new EvaluationStack();
    newNode->value = value;
    if (eval_top == nullptr)
    {
        newNode->next = nullptr;
        eval_top = newNode;
        return;
    }
    newNode->next = eval_top;
    eval_top = newNode;
}

// Pops and returns a numeric value from the evaluation stack
float eval_pop()
{
    if (eval_top == nullptr)
    {
        cout << "Stack is empty";
        return 0;
    }
    EvaluationStack *temp = eval_top;
    float value = temp->value;
    eval_top = eval_top->next;
    delete temp;
    return value;
}

// Defines the priority of operators. Higher return value = Higher priority.
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

// Pushes a character (operator/bracket) onto the conversion stack
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

// Pops and returns a character from the conversion stack
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

// Main logic to convert Infix (A+B) to Postfix (AB+)
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

// Logic to calculate the final result from a Postfix string
float evaluate_postfix(string postfix_equation)
{
    for (int i = 0; i < postfix_equation.length(); i++)
    {
        // Rule 1: If character is a digit, convert ASCII to int and push to eval_stack
        if ((postfix_equation[i] >= 48 && postfix_equation[i] <= 57))
        {
            eval_push(postfix_equation[i] - 48);
        }
        else
        {
            // Rule 2: If operator, pop two values and perform calculation
            // Note: First pop is val1 (right side), second pop is val2 (left side)
            float val1 = eval_pop();
            float val2 = eval_pop();

            float answer;
            switch (postfix_equation[i])
            {
            case '+':
                answer = val2 + val1;
                break;

            case '-':
                answer = val2 - val1;
                break;

            case '*':
                answer = val2 * val1;
                break;

            case '/':
                answer = val2 / val1;
                break;
            default:
                break;
            }
            // Push the intermediate result back to stack
            eval_push(answer);
        }
    }
    // Final result remains at the top of the stack
    float final_answer = eval_pop();

    // Integrity Check: Stack should be empty now
    if (eval_top != nullptr)
    {
        cout << "Incorrect Equation";
        return 0;
    }
    return final_answer;
}

int main()

{
    string infix;
    cout << "Enter infix equation: ";
    cin >> infix;

    string postfix = generate_postfix(infix);
    cout << "Postfix Notation: ";
    display(postfix);

    float postfix_answer = evaluate_postfix(postfix);
    cout << "\nFinal Answer: " << postfix_answer;
}
