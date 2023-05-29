//
// Created by nesma on 26/05/2023.
//

#include "../header/Graph.h"

Graph::Graph() = default;

Graph::Graph(int orig, int dest, float dist) : orig(orig), dest(dest), dist(dist) { }

Graph::Graph(int n) : numVertices(n), adjacencyMatrix(n, vector<int>(n, 0)) { }

void Graph::addEdge(int src, int dest, int dist) {
    adjacencyMatrix[src][dest] = dist;
    adjacencyMatrix[dest][src] = dist;
}

void Graph::addTwoWayEdge(const Graph& edge) {
    twEdges.push_back(edge);
}

int Graph::getNumVertices() const {
    return numVertices;
}

int Graph::setNumVertices() const {
    return twEdges.size();
}

vector<Graph>& Graph::getEdges() {
    return twEdges;
}

int Graph::getOrigin() const {
    return orig;
}

int Graph::getDestination() const {
    return dest;
}

float Graph::getDistance() const {
    return dist;
}

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
}

int tspBacktrackingWrapper(const Graph& graph){
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
}

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
}
