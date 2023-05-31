//
// Created by nesma on 26/05/2023.
//
#include <bits/stdc++.h>
#include "../header/Graph.h"
using namespace std;

Graph::Graph(int nodes) : numNodes(nodes), adjacencyMatrix(nodes, vector<float>(nodes, 0.0)) {}

int Graph::getNumNodes(){
    return numNodes;
}

void Graph::setNumNodes(int numNodes) {
    Graph::numNodes = numNodes;
}

float Graph::getWeight(int node1, int node2) {
    return adjacencyMatrix[node1][node2];
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
void Graph::tsp(vector<bool>& v, int currPos, int n, int count, int cost, float & ans)
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
}
