#include <iostream>
using namespace std;
#include <vector>

// Function to convert the edge list into an Adjacency List.
vector<vector<int>> build_adjacency_list(int n, vector<vector<int>> &edges, int source, int destination)
{
    // Initialize a 2D vector with 'n' empty lists
    vector<vector<int>> adjacen_list(n);
    for (int i = 0; i < edges.size(); i++)
    {
        // Since it is undirected graph, add connections for both nodes
        adjacen_list[edges[i][0]].push_back(edges[i][1]);
        adjacen_list[edges[i][1]].push_back(edges[i][0]);
    }
    return adjacen_list;
}

// Depth First Search (DFS) helper function to explore the graph.
bool dfs(int curr, int destination, vector<vector<int>> &adjacen_list, vector<bool> &visited)
{
    // Base Case: If we reached the destination, a path exists
    if (curr == destination)
    {
        return true;
    }

    // Mark the current node as visited to avoid infinite loops/cycles
    visited[curr] = true;
    int i = 0;
    // Iterate through all neighbors of the current node
    while (i < adjacen_list[curr].size())
    {
        int neighbor = adjacen_list[curr][i];

        // If the neighbor hasn't been visited yet, explore it
        if (visited[neighbor] == false)
        {
            bool result = dfs(neighbor, destination, adjacen_list, visited);

            // If any recursive path finds the destination, propagate 'true' upwards
            if (result)
            {
                return result;
            }
        }
        i++;
    }
    // If all neighbors are explored and destination isn't found, return false
    return false;
}

// Main logic to check if a valid path exists between source and destination.
bool find_path(int n, vector<vector<int>> &edges, int source, int destination)
{
    // Step 1: Pre-process the input into an adjacency list
    vector<vector<int>> adjacen_list = build_adjacency_list(n, edges, source, destination);

    // Step 2: Track visited nodes to prevent re-visiting the same node
    vector<bool> visited(n);

    // Step 3: Start the DFS search from the source node
    bool result = dfs(source, destination, adjacen_list, visited);
    return result;
}

int main()
{
    // Test Case 1: Simple Path
    // n = 3, edges = [[0,1], [1,2], [2,0]], source = 0, destination = 2
    int n1 = 3;
    vector<vector<int>> edges1 = {{0, 1}, {1, 2}, {2, 0}};
    int source1 = 0, destination1 = 2;

    cout << "Test Case 1: ";
    if (find_path(n1, edges1, source1, destination1))
    {
        cout << "Path Exists" << endl;
    }
    else
    {
        cout << "No Path Found" << endl;
    }

    // Test Case 2: No Path (Disconnected Graph)
    // n = 6, edges = [[0,1], [0,2], [3,5], [5,4]], source = 0, destination = 5
    int n2 = 6;
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}};
    int source2 = 0, destination2 = 5;

    cout << "\nTest Case 2: ";
    if (find_path(n2, edges2, source2, destination2))
    {
        cout << "Path Exists" << endl;
    }
    else
    {
        cout << "No Path Found" << endl;
    }

    return 0;
}