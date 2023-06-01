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


    vector<Edge > getAdj() const;
    bool isVisited() const;
    int getID() const;
    double getLG() const;
    double getLAT() const;



    void setVisited(bool visited);
    void addEdge( Edge edge );

    int getId() const;

    void setId(int id);

    double getLg() const;

    void setLg(double lg);

    double getLat() const;

    void setLat(double lat);

    void setAdj(const vector<Edge > &adj);

    /**friend class MutablePriorityQueue<Vertex>;**/
protected:

    int id;
    double lg;
    double lat;
    vector<Edge > adj;  // outgoing edges


    // auxiliary fields
    bool visited = false;
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge( Vertex *dest, double dist);

    Vertex * getDest() const;
    double getDist() const;


    void setDest(Vertex *dest);

    void setDist(double dist);

protected:
    Vertex *dest;
    double dist;

};

#endif //DA1_VERTEXEDGE_H
