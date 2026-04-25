#include <iostream>

struct Vertex
{
    char data;
    Vertex *next_vertex;
    Edge *edge_list;
    Vertex *parent;
    bool isVisited;
};

struct Edge
{
    int weight;
    Vertex *destin_vertex;
    Edge *next_edge;
};

struct VertexStack
{
    Vertex *vertex;
    VertexStack *next;
};

class Stack
{
private:
    VertexStack *top = nullptr;

public:
    void push(Vertex *vtr)
    {
        // Create a new node in dynamic memory
        VertexStack *new_node = new VertexStack();
        new_node->vertex = vtr;

        if (top == nullptr)
        {
            new_node->next = nullptr;
            top = new_node;
            return;
        }

        new_node->next = top;
        top = new_node;
    }

    Vertex *pop()
    {
        if (top == nullptr)
        {
            return nullptr;
        }

        VertexStack *temp = top;

        top = top->next;
        Vertex *temp_vtr = temp->vertex;

        delete temp;
        return temp_vtr;
    }

    bool is_stack_empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }
};