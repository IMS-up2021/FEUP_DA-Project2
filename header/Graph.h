//
// Created by nesma on 26/05/2023.
//

#ifndef DA2_GRAPH_H
#define DA2_GRAPH_H


class Graph {
private:
    int orig;
    int dest;
    float dist;
    vector<Graph> twEdges;

public:
    Graph();
    Graph(int orig, int dest, float dist);
    void addEdge(const Graph edge);
    void addTwoWayEdge(const Graph& edge);
    vector<Graph>& getEdges();
    int getOrigin() const;
    int getDestination() const;
    float getDistance() const;
};


#endif //DA2_GRAPH_H
