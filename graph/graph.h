#include <iostream>
#include "queue.h"
#include "stack.h"

struct Vertex
{
    char data;
    Vertex *next_vertex;
    Edge *edge_list;
    Vertex *parent;
    bool isVisited;
    bool rec_stack;
};

struct Edge
{
    int weight;
    Vertex *destin_vertex;
    Edge *next_edge;
};

class Graph
{
private:
    Vertex *graph;
    bool is_directed;

protected:
    bool is_graph_empty()
    {
        if (graph == nullptr)
        {
            std::cout << "Graph is empty";
            return true;
        }
    }
    Vertex *find_vertex(char val)
    {
        Vertex *current = graph;
        while (current != nullptr)
        {
            if (current->data == val)
            {
                return current;
            }
            current = current->next_vertex;
        }
        return current;
    }

    Edge *create_edge(int weight, Vertex *destin_vertex)
    {
        Edge *new_edge = new Edge();
        new_edge->weight = weight;
        new_edge->destin_vertex = destin_vertex;
        new_edge->next_edge = nullptr;
        return new_edge;
    }

    Vertex *create_vertex(char val)
    {
        Vertex *new_vertex = new Vertex();
        new_vertex->data = val;
        new_vertex->next_vertex = nullptr;
        new_vertex->isVisited = false;
        new_vertex->rec_stack = false;
        new_vertex->parent = nullptr;
        return new_vertex;
    }

    void reset_graph()
    {
        Vertex *curr_vertex = graph;
        while (curr_vertex != nullptr)
        {
            curr_vertex->isVisited = false;
            curr_vertex->rec_stack = false;
            curr_vertex->parent = nullptr;
            curr_vertex = curr_vertex->next_vertex;
        }
    }
    void path_backtrack(Vertex *vtr)
    {
        if (vtr->parent == nullptr)
        {
            std::cout << vtr->data;
            return;
        }
        path_backtrack(vtr->parent);
        std::cout << vtr->data;
    }

    bool dfs_for_cycle_detection(Vertex *vtr)
    {
        vtr->isVisited = true;
        vtr->rec_stack = true;

        Edge *temp_edge = vtr->edge_list;
        while (temp_edge != nullptr)
        {
            Vertex *neighbour = temp_edge->destin_vertex;
            if (neighbour->isVisited && neighbour->rec_stack)
            {
                return true;
            }
            if (neighbour->isVisited == false)
            {
                bool result = dfs_for_cycle_detection(temp_edge->destin_vertex);
                if (result == true)
                {
                    return true;
                }
            }

            temp_edge = temp_edge->next_edge;
        }
        vtr->rec_stack = false;
        return false;
    }
    bool delete_from_edge_list(Vertex *curr_vertex, char val_to_delete)
    {
        if (curr_vertex->edge_list == nullptr)
        {
            return false;
        }

        Edge *curr_edge = curr_vertex->edge_list;
        if (curr_edge->destin_vertex->data == val_to_delete)
        {
            Edge *temp = curr_edge;
            curr_vertex->edge_list = temp->next_edge;
            delete temp;
            return true;
        }

        Edge *prev_edge = curr_edge;
        curr_edge = curr_edge->next_edge;
        while (curr_edge != nullptr)
        {
            if (curr_edge->destin_vertex->data == val_to_delete)
            {
                prev_edge->next_edge = curr_edge->next_edge;
                delete curr_edge;
                return true;
            }
            prev_edge = curr_edge;
            curr_edge = curr_edge->next_edge;
        }
        return false;
    }

    void dfs_helper(Vertex *vtr)
    {
        vtr->isVisited = true;
        cout << vtr->data << "   ";

        Edge *temp_edge = vtr->edge_list;
        while (temp_edge != nullptr)
        {
            if (temp_edge->destin_vertex->isVisited == false)
            {
                dfs_helper(temp_edge->destin_vertex);
            }
            temp_edge = temp_edge->next_edge;
        }
    }

    bool check_cycle_for_undirected()
    {
        Stack s;
        Vertex *curr_vtr = graph;
        while (curr_vtr != nullptr)
        {
            if (curr_vtr->isVisited == false)
            {
                s.push(curr_vtr);
                curr_vtr->isVisited = true;

                while (!s.is_stack_empty())
                {
                    Vertex *vtr = s.pop();
                    Edge *temp_edge = vtr->edge_list;
                    while (temp_edge != nullptr)
                    {
                        if (temp_edge->destin_vertex->isVisited == false)
                        {
                            temp_edge->destin_vertex->isVisited = true;
                            s.push(temp_edge->destin_vertex);
                            temp_edge->destin_vertex->parent = vtr;
                        }
                        else if (temp_edge->destin_vertex->isVisited == true && temp_edge->destin_vertex != vtr->parent)
                        {
                            return true;
                        }
                        temp_edge = temp_edge->next_edge;
                    }
                }
            }
            curr_vtr = curr_vtr->next_vertex;
        }
        reset_graph();
        return false;
    }

public:
    Graph(bool directed)
    {
        graph = nullptr;
        is_directed = directed;
    }

    void add_vertex(char val)
    {
        if (graph == nullptr)
        {
            Vertex *new_vertex = create_vertex(val);
            graph = new_vertex;
        }
        else
        {
            Vertex *current = graph;
            Vertex *previous = nullptr;
            while (current != nullptr)
            {
                if (current->data == val)
                {
                    std::cout << "Duplicate Vertex found";
                    return;
                }
                previous = current;
                current = current->next_vertex;
            }

            Vertex *new_vertex = create_vertex(val);
            previous->next_vertex = new_vertex;
        }
    }

    void add_edge(int weight, char source, char destination)
    {
        if (is_graph_empty())
        {
            return;
        }

        Vertex *src = find_vertex(source);
        Vertex *destin = find_vertex(destination);

        if (src == nullptr)
        {
            std::cout << "Source not found";
            return;
        }

        if (destin == nullptr)
        {
            std::cout << "Destination not found";
            return;
        }

        else
        {
            Edge *temp = src->edge_list;
            while (temp != nullptr)
            {
                if (temp->destin_vertex == destin)
                {
                    std::cout << "Duplicate edge found";
                    return;
                }
                temp = temp->next_edge;
            }
            Edge *src_edge = create_edge(weight, destin);

            src_edge->next_edge = src->edge_list;
            src->edge_list = src_edge;

            if (!is_directed)
            {
                Edge *destin_edge = create_edge(weight, src);
                destin_edge->next_edge = destin->edge_list;
                destin->edge_list = destin_edge;
            }
        }
    }

    void remove_edge(char src_val, char destin_val)
    {
        if (is_graph_empty())
        {
            return;
        }

        Vertex *src_vtr = find_vertex(src_val);
        if (src_vtr == nullptr)
        {
            std::cout << "Source not found";
            return;
        }

        bool result = delete_from_edge_list(src_vtr, destin_val);
        if (!result)
        {
            cout << "Edge not deleted!";
            return;
        }

        if (!is_directed)
        {
            Vertex *destin_vtr = find_vertex(destin_val);
            delete_from_edge_list(destin_vtr, src_val);
        }

        cout << "Edge Deleted Successfully";
    }

    int out_degree(char val)
    {
        Vertex *current_vertex = find_vertex(val);
        if (current_vertex == nullptr)
        {
            std::cout << "Vertex not found";
            return -1;
        }
        Edge *curr_edge = current_vertex->edge_list;
        int degree = 0;
        while (curr_edge != nullptr)
        {
            degree++;
            curr_edge = curr_edge->next_edge;
        }
        return degree;
    }

    int in_degree(char val)
    {
        Vertex *vertex_to_find = find_vertex(val);
        if (vertex_to_find == nullptr)
        {
            std::cout << "Vertex not found";
            return -1;
        }

        Vertex *current_vertex = graph;
        int degree = 0;
        while (current_vertex != nullptr)
        {
            Edge *current_edge = current_vertex->edge_list;
            while (current_edge != nullptr)
            {
                if (current_edge->destin_vertex == vertex_to_find)
                {
                    degree++;
                    break;
                }
                current_edge = current_edge->next_edge;
            }
            current_vertex = current_vertex->next_vertex;
        }
        return degree;
    }

    void degree(char val)
    {
        if (!is_directed)
        {
            Vertex *vertex_to_find = find_vertex(val);

            if (vertex_to_find == nullptr)
            {
                std::cout << "Vertex Not Found";
                return;
            }
            Vertex *current_vertex = vertex_to_find;
            Edge *current_edge = current_vertex->edge_list;
            int deg = 0;
            while (current_edge != nullptr)
            {
                if (current_edge->destin_vertex == vertex_to_find)
                {
                    deg += 2;
                }
                else
                {
                    deg++;
                }
                current_edge = current_edge->next_edge;
            }
            std::cout << "Undirected Degree: " << deg;
            return;
        }
        int in_deg = in_degree(val);
        int out_deg = out_degree(val);
        std::cout << "Directed: \nIn-Degree: " << in_deg << "Out-Degree: " << out_deg;
        return;
    }

    void breadth_first_traversal()
    {
        reset_graph();
        Queue q;
        Vertex *current_vertex = graph;
        while (current_vertex != nullptr)
        {
            if (current_vertex->isVisited == false)
            {
                current_vertex->isVisited = true;
                q.enqueue(current_vertex);
                while (!q.is_queue_empty())
                {
                    Vertex *vtr = q.dequeue();
                    std::cout << vtr->data;
                    Edge *temp_edge = vtr->edge_list;
                    while (temp_edge != nullptr)
                    {
                        if (temp_edge->destin_vertex->isVisited == false)
                        {
                            q.enqueue(temp_edge->destin_vertex);
                            temp_edge->destin_vertex->isVisited = true;
                        }
                        temp_edge = temp_edge->next_edge;
                    }
                }
            }
            current_vertex = current_vertex->next_vertex;
        }
    }

    void depth_first_traversal()
    {
        reset_graph();
        Stack s;
        Vertex *current_vertex = graph;
        while (current_vertex != nullptr)
        {
            if (current_vertex->isVisited == false)
            {
                s.push(current_vertex);
                while (!s.is_stack_empty())
                {
                    Vertex *vtr = s.pop();
                    vtr->isVisited = true;
                    std::cout << vtr->data;
                    Edge *temp_edge = vtr->edge_list;
                    while (temp_edge != nullptr)
                    {
                        if (temp_edge->destin_vertex->isVisited == false)
                        {
                            s.push(temp_edge->destin_vertex);
                        }
                        temp_edge = temp_edge->next_edge;
                    }
                }
            }
            current_vertex = current_vertex->next_vertex;
        }
    }

    void dfs_using_recursion()
    {
        reset_graph();
        Vertex *current_vertex = graph;
        while (current_vertex != nullptr)
        {
            if (current_vertex->isVisited == false)
            {
                dfs_helper(current_vertex);
            }
            current_vertex = current_vertex->next_vertex;
        };
    }

    void path(char src_val, char destin_val)
    {
        reset_graph();
        Queue q;
        bool path_found = false;

        Vertex *src_vtr = find_vertex(src_val);
        Vertex *destin_vtr = find_vertex(destin_val);
        if (src_vtr == nullptr)
        {
            cout << "Source Not Found!";
            return;
        }
        if (destin_vtr == nullptr)
        {
            cout << "Destination not found";
            return;
        }
        if (src_val == destin_val)
        {
            std::cout << src_val;
            return;
        }
        src_vtr->isVisited = true;
        q.enqueue(src_vtr);
        while (!q.is_queue_empty())
        {
            Vertex *vtr = q.dequeue();
            Edge *temp_edge = vtr->edge_list;
            while (temp_edge != nullptr)
            {
                if (temp_edge->destin_vertex->isVisited == false)
                {
                    q.enqueue(temp_edge->destin_vertex);
                    temp_edge->destin_vertex->isVisited = true;
                    temp_edge->destin_vertex->parent = vtr;
                    if (temp_edge->destin_vertex->data == destin_val)
                    {
                        path_found = true;
                        break;
                    }
                }
                temp_edge = temp_edge->next_edge;
            }
            if (path_found)
            {
                path_backtrack(destin_vtr);
                break;
            }
        }
        if (!path_found)
        {
            std::cout << "Path Not found";
        }
}

    bool check_cycle_for_directed()
    {
        reset_graph();
        Vertex *curr_vtr = graph;
        while (curr_vtr != nullptr)
        {
            if (curr_vtr->isVisited == false)
            {
                bool result = dfs_for_cycle_detection(curr_vtr);
                if (result)
                {
                    return result;
                }
            }
            curr_vtr = curr_vtr->next_vertex;
        }
        return false;
    }

    bool hasCycle()
    {
        bool result;
        if (!is_directed)
        {
            result = check_cycle_for_directed();
        }
        else
        {
            result = check_cycle_for_directed();
        }
        return result;
    }
};