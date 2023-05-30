//
// Created by nesma on 26/05/2023.
//
#include <bits/stdc++.h>
#include "../header/Graph.h"
using namespace std;

Graph::Graph(int nodes) : numNodes(nodes), adjencyMatrix(nodes, vector<float>(nodes, 0.0)) {}

int Graph::getNumNodes() const {
    return numNodes;
}

void Graph::setNumNodes(int numNodes) {
    Graph::numNodes = numNodes;
}

const vector<vector<float>> &Graph::getAdjencyMatrix() const {
    return adjencyMatrix;
}

void Graph::setAdjencyMatrix(const vector<vector<float>> &adjacencyMatrix) {
    Graph::adjencyMatrix = adjacencyMatrix;
}

void Graph::addEdge(int src, int dest, int dist) {
    adjencyMatrix[src][dest] = dist;
    adjencyMatrix[dest][src] = dist;
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
    if (count == n && adjencyMatrix[currPos][0]) {
        float helper = (cost + adjencyMatrix[currPos][0]);
        ans = min(ans,  helper);

        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increasing the count
    // by 1 and cost by adjencyMatrix[currPos][i] value
    for (int i = 0; i < n; i++) {
        if (!v[i] && adjencyMatrix[currPos][i]) {

            // Mark as visited
            v[i] = true;
            tsp( v, i, n, count + 1,
                cost + adjencyMatrix[currPos][i], ans);

            // Mark ith node as unvisited
            v[i] = false;
        }
    }
};

//function of Triangular Approximation Heuristic
vector<int> Graph::tspTriangularApproximation(const Graph& graph){
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

    return tour;
}



/*
void tspBacktracking(const Graph& graph, vector<int>& path, vector<bool>& visited, int currVertex, int& minCost, int& numIterations){
    int num Vertices = graph.getNumVertices();

    if (numVisited == numVertices && graph.getDistance(currVertex, 0) > 0){
        minCost = min(minCost, path[numVisited - 1] + graph.getDistance(currVertex,0));
        numIterations++;
        return;
    }

    for (int nextVertex = 0; nextVertex < numVertices; nextVertex++){
        if(!visited[nextVertex] && graph.getDistance(currVertex, nextVertex) > 0){
            visited[nextVertex] = true;
            path[numVisited] = graph.getDistance(currVertex, nextVertex);
            tspBacktracking(graph, path, visited, nextVertex, numVisited + 1, minCost, numIterations);
            visited[nextVertex] = false;
        }
    }
}*/

/*int tspBacktrackingWrapper(const Graph& graph){
    int numVertices = graph.getNumVertices();
    vector<int> path(numVertices, 0);
    vector<bool> visited(numVertices, false),
    visited[0] = true; //Starting vertex is fixed

    int minCost = INT_MAX;
    int numIterations = 0;

    tspBacktracking(graph, path, visited, 0, 1, minCost, numIterations);

    cout << "Minimum Cost: " << minCost << endl;
    cout << "Number of Iterations: " << numIterations << endl;

    return minCost;
}*/
/*
void tspTriangularApproximation(const Graph& graph) {
    int numVertices = graph.getNumVertices();

    std::vector<bool> visited(numVertices, false);
    visited[0] = true;

    int currVertex = 0;
    int nextVertex = 0;
    int minDistance = std::numeric_limits<int>::max();
    int totalCost = 0;

    std::cout << "Tour: " << currVertex << " -> ";

    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = 0; j < numVertices; j++) {
            if (!visited[j] && graph.getDistance(currVertex, j) < minDistance) {
                minDistance = graph.getDistance(currVertex, j);
                nextVertex = j;
            }
        }

        std::cout << nextVertex << " -> ";
        visited[nextVertex] = true;
        totalCost += minDistance;
        currVertex = nextVertex;
        minDistance = std::numeric_limits<int>::max();
    }

    totalCost += graph.getDistance(currVertex, 0);
    std::cout << "0" << std::endl;

    std::cout << "Total Cost: " << totalCost << std::endl;
}*/
