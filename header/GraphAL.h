//
// Created by pedroromao on 5/31/23.
//

#ifndef DA2_GRAPHAL_H
#define DA2_GRAPHAL_H


#include "vertexEdge.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
class GraphAL {
private:
    vector<Vertex> nodes;

public:

    GraphAL();

     const vector<Vertex> &getNodes() ;

     void setNodes(const vector<Vertex> &nodes1);

     void addNode(int id, double lg , double lat);

     void addEdgetoAdj(Edge edge, int idNode);

     Vertex* getVertexAt(int location);

     void setVisitedNode(int pos);

     void tsp( int currPos, int count, int cost, float & ans);

     pair<bool,float> thereIsPathFromTo(int posInit , int posFinal);



};


#endif //DA2_GRAPHAL_H
