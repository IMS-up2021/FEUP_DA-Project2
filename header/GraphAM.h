

#ifndef DA2_GRAPHAM_H
#define DA2_GRAPHAM_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
class GraphAM {
private:

    int numNodes;
    vector<vector<float >> adjacencyMatrix;

public:
    int getNumNodes() const;

    void setNumNodes(int numNodes);

    const vector<vector<float>> &getAdjacencyMatrix() const;

    void setAdjacencyMatrix(const vector<vector<float>> &adjacencyMatrix);

    explicit GraphAM(int numNodes);

    void addEdge(int src, int dest, int dist);

    void tsp(vector<bool>& v, int currPos, int n, int count, int cost, float & ans);

    static void tspTriangularApproximation(const GraphAM& graph);
};


#endif //DA2_GRAPHAM_H
