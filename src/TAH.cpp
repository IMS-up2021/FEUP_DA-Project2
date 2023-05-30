//
// Created by nesma on 29/05/2023.
//

#include <iostream>
#include <vector>
#include "vertexEdge.cpp"

using namespace std;

//-----------------------RWG-----------------------------//
vector<int> tah_rwg(const vector<Vertex>& vertices) {
    int numVertices = vertices.size();
    vector<bool> visited(numVertices, false);
    vector<int> tour;
    int current = 0;

    visited[current] = true;
    tour.push_back(current);

    while (tour.size() < numVertices) {
        int nearestNeighbor = -1;
        double minDistance = numeric_limits<double>::max();

        const Vertex& currentVertex = vertices[current];
        const std::vector<Edge*>& adjEdges = currentVertex.getAdj();

        for (Edge* edge : adjEdges) {
            Vertex* neighbor = edge->getDest();
            if (!neighbor->isVisited() && edge->getDist() < minDistance) {
                nearestNeighbor = neighbor->getID();
                minDistance = edge->getDist();
            }
        }

        visited[nearestNeighbor] = true;
        tour.push_back(nearestNeighbor);
        current = nearestNeighbor;
    }

    tour.push_back(0);

    return tour;
}
