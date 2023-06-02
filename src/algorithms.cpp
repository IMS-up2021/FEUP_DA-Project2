#include "../header/algorithms.h"
#include <iostream>
#include <climits>
#include <cmath>
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

/*4.3 Christofides Algorithm:
 an approximation algorithm that guarantees a solution within a factor of 1.5 of the optimal solution.
 It has a time complexity of O(n^3) and is suitable for larger graphs.
 */

 const float FIN = numeric_limits<float>::infinity();

// Helper function to calculate the Euclidean distance between two points
float calcDistance(const pair<float, float>& p1, const pair<float, float>& p2) {
    float dx = p1.first - p2.first;
    float dy = p1.second - p2.second;
    return sqrt(dx * dx + dy * dy);
}

// Helper function to find the index of the minimum element in a vector, excluding  the visited nodes
int findMinIndex(const vector<float>& values, const vector<bool>& visited) {
    float minVal = FIN;
    int minIndex = -1;
    for (int i = 0; i < values.size(); ++i) {
        if (!visited[i] && values[i] < minVal) {
            minVal = values[i];
            minIndex = i;
        }
    }
    return minIndex;
}

/* Function to find the minimum spanning tree using Prim's algorithm
 *  This function takes a vector of nodes as input and returns the minimum spanning tree (MST)
 *  adjacency matrix using Prim's algorithm. The algorithm starts with node 0 as the root and
 *  iteratively adds the node with the minimum distance to the MST.
 *  The MST adjacency matrix is constructed using the parent array.
 */
vector<vector<float>> findMinimumSpanningTree(const vector<pair<float, float>>& nodes) {
    int n = nodes.size();
    vector<bool> visited(n, false);
    vector<float> minDistances(n, FIN);
    vector<int> parent(n, -1);

    // Start with node 0 as the root
    minDistances[0] = 0;

    // Construct the minimum spanning tree
    for (int i = 0; i < n - 1; ++i) {
        int u = findMinIndex(minDistances, visited);
        visited[u] = true;

        for (int v = 0; v < n; ++v) {
            if (!visited[v]) {
                float distance = calcDistance(nodes[u], nodes[v]);
                if (distance < minDistances[v]) {
                    minDistances[v] = distance;
                    parent[v] = u;
                }
            }
        }
    }

    // Build the minimum spanning tree adjacency matrix
    vector<vector<float>> mst(n, vector<float>(n, FIN));
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) {
            mst[parent[i]][i] = calcDistance(nodes[parent[i]], nodes[i]);
            mst[i][parent[i]] = mst[parent[i]][i];
        }
    }

    return mst;
}

/* Function to find the minimum perfect matching on odd-degree vertices
 * This function takes the MST adjacency matrix as input and returns the
 * minimum perfect matching on odd-degree vertices.
 * It identifies the odd-degree vertices and finds the minimum weight edge
 * for each vertex to form the matching.
 */
vector<pair<int, int>> findMinimumPerfectMatching(const vector<vector<float>>& graph) {
    int n = graph.size();
    vector<pair<int, int>> matching;

    // Find odd-degree vertices
    vector<int> oddDegreeVertices;
    for (int i = 0; i < n; ++i) {
        int degree = 0;
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != FIN) {
                degree++;
            }
        }
        if (degree % 2 != 0) {
            oddDegreeVertices.push_back(i);
        }
    }

    vector<bool> visited(n, false);
    for (int i = 0; i < oddDegreeVertices.size(); ++i) {
        if (!visited[oddDegreeVertices[i]]) {
            int u = oddDegreeVertices[i];
            float minDistance = FIN;
            int minIndex = -1;

            for (int v = 0; v < n; ++v) {
                if (u != v && !visited[v] && graph[u][v] < minDistance) {
                    minDistance = graph[u][v];
                    minIndex = v;
                }
            }

            visited[u] = true;
            visited[minIndex] = true;
            matching.push_back(make_pair(u, minIndex));
        }
    }

    return matching;
}

/* Function to find an Eulerian tour in a graph
 * This function takes a graph adjacency matrix as input and returns an Eulerian tour in the graph.
 * The algorithm starts with a random node and repeatedly traverses unvisited edges until it returns
 * to the starting node, forming a tour.
 */
vector<int> findEulerianTour(const vector<vector<float>>& graph) {
    int n = graph.size();
    vector<int> tour;
    vector<vector<float>> tempGraph = graph;

    int u = 0;
    tour.push_back(u);

    while (true) {
        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (tempGraph[u][i] != FIN) {
                v = i;
                break;
            }
        }

        if (v == -1) break;

        tour.push_back(v);
        tempGraph[u][v] = FIN;
        tempGraph[v][u] = FIN;
        u = v;
    }

    return tour;
}

/* Function to find the optimal tour using the Christofides algorithm
 * This function takes a vector of nodes as input and returns the optimal tour length using the Christofides algorithm.
 * The algorithm combines the steps of finding the minimum spanning tree, minimum perfect matching, and Eulerian tour to obtain an approximate solution to the TSP.
 * The optimal path is obtained by removing repeated vertices from the Eulerian tour.
 * The optimal path and tour length are printed and returned.
*/
float tspChristofides(const vector<pair<float, float>>& nodes) {
    int n = nodes.size();

    // Step 1: Construct the minimum spanning tree
    vector<vector<float>> mst = findMinimumSpanningTree(nodes);

    // Step 2: Find the minimum perfect matching on odd-degree vertices
    vector<pair<int, int>> matching = findMinimumPerfectMatching(mst);

    // Step 3: Combine the minimum spanning tree and the matching to form a multigraph
    vector<vector<float>> multigraph(n, vector<float>(n, FIN));
    for (const auto& edge : matching) {
        int u = edge.first;
        int v = edge.second;
        multigraph[u][v] = calcDistance(nodes[u], nodes[v]);
        multigraph[v][u] = multigraph[u][v];
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mst[i][j] != FIN) {
                multigraph[i][j] = mst[i][j];
                multigraph[j][i] = mst[i][j];
            }
        }
    }

    // Step 4: Find an Eulerian tour in the multigraph
    vector<int> eulerianTour = findEulerianTour(multigraph);

    // Step 5: Remove repeated vertices to obtain the optimal tour
    vector<bool> visited(n, false);
    vector<int> tour;
    for (int node : eulerianTour) {
        if (!visited[node]) {
            visited[node] = true;
            tour.push_back(node);
        }
    }

    // Add the starting node to complete the tour
    tour.push_back(tour[0]);

    // Calculate the tour length
    float tourLength = 0.0;
    for (int i = 0; i < n; ++i) {
        int u = tour[i];
        int v = tour[i + 1];
        tourLength += calcDistance(nodes[u], nodes[v]);
    }

    // Print the optimal path
    cout << "Optimal Path: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;

    // Return the optimal tour length
    return tourLength;
}
