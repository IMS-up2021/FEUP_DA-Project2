//
// Created by nesma on 29/05/2023.
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int orig;
    int dest;
    double dist;
};

vector<int> tah_tw(const vector<Node>& nodes){
    int nNodes = nodes.size();
    vector<bool> visited(nNodes, false);
    vector<int> tour;
    int current = 0;

    visited[current] = true;
    tour.push_back(current);

    while (tour.size() < nNodes) {
        int nearestNeighbor = -1;
        double minDist = numeric_limits<double>::max();

        for (int i = 0; i < nNodes; ++i) {
            if (i != current && !visited[i] && nodes[i].dist < minDist) {
                nearestNeighbor = i;
                minDist = nodes[i].dist;
            }
        }

        visited[nearestNeighbor] = true;
        tour.push_back(nearestNeighbor);
        current = nearestNeighbor;
    }

    tour.push_back(0);

    return tour;
}
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
