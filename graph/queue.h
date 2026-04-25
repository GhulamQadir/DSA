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

struct VertexQueue
{
    Vertex *vertex;
    VertexQueue *next;
};

class Queue
{
private:
    VertexQueue *front = nullptr;
    VertexQueue *rear = nullptr;

public:
    void enqueue(Vertex *vtr)
    {
        // Create a new node in dynamic memory (Heap)
        VertexQueue *new_node = new VertexQueue();
        new_node->vertex = vtr;
        new_node->next = nullptr;

        // Case: If queue is empty, the new node becomes both front and rear
        if (front == nullptr)
        {
            front = new_node;
            rear = new_node;
            return;
        }

        // Link the current rear's next to the new node and update rear
        rear->next = new_node;
        rear = new_node;
    }

    Vertex *dequeue()
    {
        // Underflow check: If front is null, queue is empty
        if (front == nullptr)
        {
            std::cout << "Queue is Empty: ";
            return nullptr;
        }

        // Temporary pointer to hold the current front for deletion
        VertexQueue *temp = front;
        Vertex *vtr_to_return = temp->vertex;

        // Move front to the next node in the list
        front = front->next;

        // If front becomes null, the queue is empty, so reset rear as well
        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
        return vtr_to_return;
    }

    bool is_queue_empty(){
        if(front ==nullptr){
            return true;
        }
        return false;
    }

};