
#include "../header/algorithms.h"
#include <iostream>
#include <climits>
#include "../header/CSVReader.h"
#include <chrono>
#include <iomanip>
#include <vector>
#include <stack>
using namespace std;

// Backtracking Heuristic for the Toy Graphs
void Algorithms::backtrackingRWG(string &filename) {
    GraphAM graph = GraphAM(0);
    CSVReader::read_RWG(filename,&graph);
    int n = graph.getNumNodes();
    vector<bool> v(n);
    vector<int> path;  // Store the path
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    float min = INT_MAX;

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Find the minimum weight Hamiltonian Cycle and store the path
    graph.tsp(v, 0, n, 1, 0, min, path);

    // Calculate execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();



    // Output the minimum distance and execution time
    cout << "Distance for the PATH exactly above: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}
void Algorithms::backtrackingTG(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, &graph);

    // Initialize variables
    int n = graph.getNumNodes();
    vector<bool> v(n);
    vector<int> path;  // Store the path
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    float min = INT_MAX;

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Find the minimum weight Hamiltonian Cycle and store the path
    graph.tsp(v, 0, n, 1, 0, min, path);

    // Calculate execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();



    // Output the minimum distance and execution time
    cout << "Distance for the PATH exactly above: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}


// Backtracking Heuristic for the Real World Graph

void preorderWalk(int parent[],int V, int node,int & last) {
    std::cout << node << " ";  // Process current node
    last = node;
    // Recursively traverse the children of the current node
    for (int child = 0; child < V; ++child) {
        if (parent[child] == node) {
            preorderWalk(parent, V, child,last );
        }
    }
}


int minKey(int key[], int V,bool mstSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// A utility function to print the
// constructed MST stored in parent[]
void    printMST(int parent[],int V , vector<vector<float>> &graph, int & ans)
{
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
        ans += graph[i][parent[i]];
        cout << parent[i] << " - " << i << " \t"
             << graph[i][parent[i]] << " \n";
    }

}

// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation
void primMST(vector<vector<float>> graph,int V)
{
    // Array to store constructed MST
    int parent[V];

    // Key values used to pick minimum weight edge in cut
    int key[V];

    // To represent set of vertices included in MST
    bool mstSet[V];

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include first 1st vertex in MST.
    // Make key 0 so that this vertex is picked as first
    // vertex.
    key[0] = 0;

    // First node is always root of MST
    parent[0] = -1;

    // The MST will have V vertices
    for (int count = 0; count < V - 1; count++) {

        // Pick the minimum key vertex from the
        // set of vertices not yet included in MST
        int u = minKey(key, V,mstSet);

        // Add the picked vertex to the MST Set
        mstSet[u] = true;

        // Update key value and parent index of
        // the adjacent vertices of the picked vertex.
        // Consider only those vertices which are not
        // yet included in MST
        for (int v = 0; v < V; v++)

            // graph[u][v] is non zero only for adjacent
            // vertices of m mstSet[v] is false for vertices
            // not yet included in MST Update the key only
            // if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v]
                && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    int ans = 0;
    printMST(parent, V, graph, ans);
    int last;
    preorderWalk(parent,V, 0,last);cout  << "0\n";
    ans += graph[last][0];
    cout  <<"total:"<<ans<< "\n";

}

void Algorithms::triangularapproximationTG(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, &graph);

    int numNodes = graph.getNumNodes();
    primMST(graph.getAdjacencyMatrix(),numNodes);



}
void Algorithms::triangularapproximationRWG(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_RWG(const_cast<string &>(filename), &graph);

    int numNodes = graph.getNumNodes();
    primMST(graph.getAdjacencyMatrix(),numNodes);



}



void Algorithms::nearestNeighborTSP(const string& filename) {
    // Create the graph and read the data
    GraphAM graph = GraphAM(0);
    CSVReader::read_TG(filename, &graph);

    int numNodes = graph.getNumNodes();

    // Initialize variables
    vector<bool> visited(numNodes, false);
    vector<int> tour;
    int startNode = 0;
    visited[startNode] = true;
    tour.push_back(startNode);

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Construct the approximate tour using the nearest neighbor heuristic
    int currentNode = startNode;
    while (tour.size() < numNodes) {
        int nextNode = -1;
        float minDistance = INT_MAX;

        // Find the nearest unvisited neighbor with the minimum distance
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (!visited[neighbor]) {
                float distance = graph.getWeight(currentNode, neighbor);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextNode = neighbor;
                }
            }
        }

        // Mark the next node as visited and add it to the tour
        visited[nextNode] = true;
        tour.push_back(nextNode);
        currentNode = nextNode;
    }

    // Add the start node to complete the tour
    tour.push_back(startNode);

    // Calculate the total distance of the tour
    float totalDistance = 0.0;
    for (int i = 0; i < numNodes - 1; ++i) {
        int currentNode = tour[i];
        int nextNode = tour[i + 1];
        totalDistance += graph.getWeight(currentNode, nextNode);
    }

    // Measure end execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // Output the approximate tour, total distance, and execution time
    cout << "Nearest Neighbor Path: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Distance of the Path: " << totalDistance << endl;
    cout << "Execution Time: " << fixed << setprecision(2) << executionTime << " seconds" << endl;
}




