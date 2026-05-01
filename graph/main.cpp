#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    bool type;
    cin >> type;

    Graph myGraph(type);

    myGraph.add_vertex('A');
    myGraph.add_vertex('B');
    myGraph.add_vertex('C');
    myGraph.add_vertex('D');

    myGraph.add_edge(10, 'A', 'B');
    myGraph.add_edge(5, 'A', 'A');
    myGraph.add_edge(7, 'B', 'C');
    myGraph.add_edge(3, 'D', 'A');

    std::cout << "Graph Created Successfully\n"
              << std::endl;

    std::cout << "Testing Degrees for Vertex 'A':" << std::endl;
    myGraph.degree('A');

    std::cout << "\n\nTesting Degrees for Vertex 'B':" << std::endl;
    myGraph.degree('B');

    std::cout << "\n\nRemoving edge between A and B..." << std::endl;
    myGraph.remove_edge('A', 'B');

    std::cout << "Degrees for Vertex 'A' after removing edge A->B:" << std::endl;
    myGraph.degree('A');
}