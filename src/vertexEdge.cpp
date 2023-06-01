#include "../header/vertexEdge.h"

using namespace std;

/************************* Vertex  **************************/

Vertex::Vertex(int id, double lg , double lat): id(id), lg(lg), lat(lat){}

int Vertex::getID() const{
    return this -> id;
}

double Vertex::getLG() const{
    return this -> lg;
}

double Vertex::getLAT() const{
    return this -> lat;
}


std::vector<Edge> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}


void Vertex::setVisited(bool visited) {
    this->visited = visited;
}

int Vertex::getId() const {
    return id;
}

void Vertex::setId(int id) {
    Vertex::id = id;
}

double Vertex::getLg() const {
    return lg;
}

void Vertex::setLg(double lg) {
    Vertex::lg = lg;
}

double Vertex::getLat() const {
    return lat;
}

void Vertex::setLat(double lat) {
    Vertex::lat = lat;
}

void Vertex::setAdj(const vector<Edge > &adj) {
    Vertex::adj = adj;
}

void Vertex::addEdge(Edge edge) {
    adj.push_back(edge);
}

/********************** Edge  ****************************/



Vertex * Edge::getDest() const {
    return this->dest;
}
double  Edge::getDist() const {
    return this->dist;
}

void Edge::setDest(Vertex *dest) {
    Edge::dest = dest;
}

void Edge::setDist(double dist) {
    Edge::dist = dist;
}

<<<<<<< HEAD

void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

=======
Edge::Edge(Vertex *dest, double dist):dest(dest), dist(dist) {}
>>>>>>> 1d3e5711de9744cc8d1854da4e62dc06f014e8ee
