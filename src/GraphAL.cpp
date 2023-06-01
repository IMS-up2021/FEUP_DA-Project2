//
// Created by pedroromao on 5/31/23.
//

#include <utility>

#include "../header/GraphAL.h"


const vector<Vertex> &GraphAL::getNodes() {
    return nodes;
}

void GraphAL::setNodes(const vector<Vertex> &nodes1) {
    GraphAL::nodes = nodes1;
}


void GraphAL::addNode(int id, double lg , double lat) {
    Vertex node = Vertex(id, lg ,  lat);
    nodes.push_back(node);
}

GraphAL::GraphAL() = default;

void GraphAL::addEdgetoAdj(Edge edge, int orig) {
    nodes[orig].addEdge(edge);
}

Vertex *GraphAL::getVertexAt(int location) {
    return &nodes[location];
}

void GraphAL::setVisitedNode(int pos) {
    nodes[pos].setVisited(true);
}

pair<bool,float> GraphAL::thereIsPathFromTo(int posInit ,int posFinal) {
    for(Edge edge : nodes[posInit].getAdj()){
        if(edge.getDest()->getID()==posFinal)return {true,edge.getDist()};
    }
    return {false,-1};
};

void GraphAL::tsp( int currPos, int count, int cost, float & ans)
{

    // If last node is reached and it has a link
    // to the starting node i.e the source then
    // keep the minimum value out of the total cost
    // of traversal and "ans"
    // Finally return to check for more possible values
    pair<bool,float> pairExistDistance = thereIsPathFromTo(currPos,0);
    if (count == nodes.size() && pairExistDistance.first) {//percorri tudo e tenho caminho para o primeiro
        float helper = (cost + pairExistDistance.second);
        ans = min(ans,  helper);
        return;
    }

    // BACKTRACKING STEP
    // Loop to traverse the adjacency list
    // of currPos node and increasing the count
    // by 1 and cost by adjencyMatrix[currPos][i] value
    Vertex currentNode =  nodes[currPos];
    for (Edge& edge : (currentNode).getAdj()) {
        if (!edge.getDest()->isVisited()) {

            // Mark as visited
            edge.getDest()->setVisited(true);
            tsp( edge.getDest()->getID(),count + 1,cost + edge.getDist(),ans );

            // Mark ith node as unvisited
            edge.getDest()->setVisited(false);
        }
    }
}
