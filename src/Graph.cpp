//
// Created by nesma on 26/05/2023.
//

#include "../header/Graph.h"

Graph::Graph() = default;

Graph::Graph(int orig, int dest, float dist) : orig(orig), dest(dest), dist(dist) { }

void Graph::addEdge(const Graph edge){
    this -> twEdges.push_back(edge);
}

void Graph::addTwoWayEdge(const Graph& edge) {
    twEdges.push_back(edge);
    Graph reverseEdge(edge.dest, edge.orig, edge.dist);
    twEdges.push_back(reverseEdge);
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