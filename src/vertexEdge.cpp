#include "../header/vertexEdge.h"

using namespace std;

/************************* Vertex  **************************/

Vertex::Vertex(int id, double lg , double lat): id(id), lg(lg), lat(lat){}


Edge * Vertex::addEdge( Vertex *dest, double dist) {
    auto newEdge = new Edge(this, dest , dist);
    adj.push_back(newEdge);
    dest->incoming.push_back(newEdge);
    return newEdge;
}



int Vertex::getID() const{
    return this -> id;
}

double Vertex::getLG() const{
    return this -> lg;
}

double Vertex::getLAT() const{
    return this -> lat;
}


std::vector<Edge*> Vertex::getAdj() const {
    return this->adj;
}

bool Vertex::isVisited() const {
    return this->visited;
}


void Vertex::setVisited(bool visited) {
    this->visited = visited;
}


/********************** Edge  ****************************/

Edge::Edge(Vertex *orig, Vertex *dest, double dist): orig(orig), dest(dest), dist(dist) {}

Vertex * Edge::getOrig() const {
    return this->orig;
}

Vertex * Edge::getDest() const {
    return this->dest;
}
double  Edge::getDist() const {
    return this->dist;
}


Edge *Edge::getReverse() const {
    return this->reverse;
}

bool Edge::isSelected() const {
    return this->selected;
}


void Edge::setSelected(bool selected) {
    this->selected = selected;
}

void Edge::setReverse(Edge *reverse) {
    this->reverse = reverse;
}

