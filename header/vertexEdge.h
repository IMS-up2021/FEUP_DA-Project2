#ifndef DA1_VERTEXEDGE_H
#define DA1_VERTEXEDGE_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(int id, double lg , double lat);


    vector<Edge *> getAdj() const;
    bool isVisited() const;
    int getID() const;
    double getLG() const;
    double getLAT() const;



    void setVisited(bool visited);
    Edge * addEdge( Vertex *dest, double dist);

    /**friend class MutablePriorityQueue<Vertex>;**/
protected:

    int id;
    double lg;
    double lat;
    vector<Edge *> adj;  // outgoing edges


    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    Edge *path = nullptr;

    vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double dist);

    Vertex * getOrig() const;
    Vertex * getDest() const;
    double getDist() const;
    bool isSelected() const;
    Edge *getReverse() const;

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
protected:
    Vertex *orig;
    Vertex *dest;
    double dist;


    // auxiliary fields
    bool selected = false;

    // used for bidirectional edges
    Edge *reverse = nullptr;


};

#endif //DA1_VERTEXEDGE_H
