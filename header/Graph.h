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
    vector<vector<float >> adjencyMatrix;

public:
    int getNumNodes() const;

    void setNumNodes(int numNodes);

    const vector<vector<float>> &getAdjencyMatrix() const;

    void setAdjencyMatrix(const vector<vector<float>> &adjacencyMatrix);

    explicit Graph(int numNodes);

    void addEdge(int src, int dest, int dist);

    void tsp(vector<bool>& v, int currPos,
                    int n, int count, int cost, float & ans);

    vector<int> tspTriangularApproximation(const Graph& graph);
};


#endif //DA2_GRAPH_H
