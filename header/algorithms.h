#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>
#include "Graph.h"

using namespace std;

class Algorithms{

public:
    static void backtrackingTG(const string& filename);
    static void backtrackingRWG(string& filename);

    static void triangularapproximationTG(const string& filename);
    static void tspTriangularApproximation(const Graph& graph);

};


#endif