//
// Created by nesma on 26/05/2023.
//
#include <bits/stdc++.h>
#include "../header/GraphAM.h"
using namespace std;

GraphAM::GraphAM(int nodes) : numNodes(nodes), adjacencyMatrix(nodes, vector<float>(nodes, 0.0)) {}

int GraphAM::getNumNodes() const {
    return numNodes;
}

void GraphAM::setNumNodes(int numNodes) {
    GraphAM::numNodes = numNodes;
}

const vector<vector<float>> &GraphAM::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

void GraphAM::setAdjacencyMatrix(const vector<vector<float>> &adjacencyMatrix) {
    GraphAM::adjacencyMatrix = adjacencyMatrix;
}

void GraphAM::addEdge(int src, int dest, int dist) {
    adjacencyMatrix[src][dest] = dist;
    adjacencyMatrix[dest][src] = dist;
}

// Function to find the minimum weight Hamiltonian Cycle
void GraphAM::tsp(vector<bool>& v, int currPos, int n, int count, int cost, float& minDistance, vector<int>& path) {
    // If last node is reached and there is a link to the starting node,
    // update the minimum distance and store the path
    path.push_back(currPos);
    if (count == n && adjacencyMatrix[currPos][0]) {
        float totalDistance = cost + adjacencyMatrix[currPos][0];
        path.push_back(0);
        if (totalDistance < minDistance) {
            minDistance = totalDistance;
            // Output the path
            cout << "Path: ";
            for (int node : path) {
                cout << node << " ";
            }
            cout << endl;


        }
        path.pop_back();
        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency matrix of currPos node and increase the count
    // by 1 and cost by adjacencyMatrix[currPos][i] value
    for (int i = 0; i < n; i++) {
        if (!v[i] && adjacencyMatrix[currPos][i]) {
            // Mark as visited
            v[i] = true;
            tsp(v, i, n, count + 1, cost + adjacencyMatrix[currPos][i], minDistance, path);
            path.pop_back();
            // Mark the current node as unvisited
            v[i] = false;
        }
    }
}



float GraphAM::getWeight(int node1, int node2) const {
    return adjacencyMatrix[node1][node2];
}

