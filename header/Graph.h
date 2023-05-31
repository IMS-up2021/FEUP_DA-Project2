//
// Created by nesma on 26/05/2023.
//

#ifndef DA2_GRAPH_H
#define DA2_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
class Graph {
private:

    int numNodes;
    vector<vector<float >> adjacencyMatrix;

public:

    void setNumNodes(int numNodes);

    const vector<vector<float>> &getAdjacencyMatrix() const;

    void setAdjacencyMatrix(const vector<vector<float>> &adjacencyMatrix);

    explicit Graph(int numNodes);

    void addEdge(int src, int dest, int dist);

    float getWeight(int node1, int node2);

    void tsp(vector<bool>& v, int currPos, int n, int count, int cost, float & ans);

    static void tspTriangularApproximation();

    int getNumNodes();
};


#endif //DA2_GRAPH_H
