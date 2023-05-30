//
// Created by nesma on 26/05/2023.
//
#include <bits/stdc++.h>
#include "../header/Graph.h"
using namespace std;

Graph::Graph(int nodes) : numNodes(nodes), adjacencyMatrix(nodes, vector<float>(nodes, 0.0)) {}

int Graph::getNumNodes() const {
    return numNodes;
}

void Graph::setNumNodes(int numNodes) {
    Graph::numNodes = numNodes;
}

const vector<vector<float>> &Graph::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

void Graph::setAdjacencyMatrix(const vector<vector<float>> &adjacencyMatrix) {
    Graph::adjacencyMatrix = adjacencyMatrix;
}

void Graph::addEdge(int src, int dest, int dist) {
    adjacencyMatrix[src][dest] = dist;
    adjacencyMatrix[dest][src] = dist;
}

// Function to find the minimum weight Hamiltonian Cycle
void Graph::tsp(vector<bool>& v, int currPos,
         int n, int count, int cost, float & ans)
{

    // If last node is reached and it has a link
    // to the starting node i.e the source then
    // keep the minimum value out of the total cost
    // of traversal and "ans"
    // Finally return to check for more possible values
    if (count == n && adjacencyMatrix[currPos][0]) {
        float helper = (cost + adjacencyMatrix[currPos][0]);
        ans = min(ans,  helper);

        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increasing the count
    // by 1 and cost by adjencyMatrix[currPos][i] value
    for (int i = 0; i < n; i++) {
        if (!v[i] && adjacencyMatrix[currPos][i]) {

            // Mark as visited
            v[i] = true;
            tsp( v, i, n, count + 1,
                cost + adjacencyMatrix[currPos][i], ans);

            // Mark ith node as unvisited
            v[i] = false;
        }
    }
};

//function of Triangular Approximation Heuristic
void Graph::tspTriangularApproximation(const Graph& graph){
    int numNodes = graph.getNumNodes();

    vector<int> tour;
    // Start and end at the node with zero-identifier label
    tour.push_back(0);

    vector <bool> visited(numNodes, false);
    visited[0] = true;

    while (tour.size() < numNodes) {
        int current = tour.back();
        int closest = -1;
        float minDist = numeric_limits<float>::infinity();

        for (int i = 0; i < numNodes; ++i) {
            if (!visited[i] && graph.getAdjacencyMatrix()[current][i] < minDist) {
                closest = i;
                minDist = graph.getAdjacencyMatrix()[current][i];
            }
        }

        tour.push_back(closest);
        visited[closest] = true;
    }

    // Print the tour
    cout << "TSP Tour: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;
}
