#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <string>

using namespace std;

class Algorithms{

public:
    static void backtrackingTG(const string& filename);
    static void backtrackingRWG(string& filename);

    static void triangularapproximationTG(const string& filename);

    static void nearestNeighborTSP(const string& filename);

};


#endif