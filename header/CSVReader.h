//
// Created by nesma on 18/05/2023.
//

#ifndef DA2_CSVREADER_H
#define DA2_CSVREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
#include "Graph.h"

using namespace std;


class CSVReader {
public:
    CSVReader();
    static void read_TG(string file, Graph* graph);
    static void read_RWG(string &file, Graph* graph);

};


#endif //DA2_CSVREADER_H
