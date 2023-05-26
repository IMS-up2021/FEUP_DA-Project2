//
// Created by nesma on 26/05/2023.
//

#ifndef DA2_GRAPH_H
#define DA2_GRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

class Graph {
private:
    int orig;
    int dest;
    float dist;
    vector<Graph> twEdges;
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Graph();
    Graph(int orig, int dest, float dist);
    Graph(int n);
    void addEdge(const Graph edge);
    void addTwoWayEdge(const Graph& edge);
    int getNumVertices() const;
    vector<Graph>& getEdges();
    int getOrigin() const;
    int getDestination() const;
    float getDistance() const;

};


#endif //DA2_GRAPH_H
