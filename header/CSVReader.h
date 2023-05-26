//
// Created by nesma on 18/05/2023.
//

#ifndef DA2_CSVREADER_H
#define DA2_CSVREADER_H


#include <fstream>
#include <sstream>
#include <queue>
#include <string>
#include <list>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include ""../src/Graph.cpp"

using namespace std;


class CSVReader {
public:
    CSVReader();
    static void read_TG(string &file, Graph* graph);
    static void read_RWG(string &file, Graph* graph);

};


#endif //DA2_CSVREADER_H
