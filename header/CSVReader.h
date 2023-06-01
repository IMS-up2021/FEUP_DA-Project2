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
#include "GraphAM.h"
#include "GraphAL.h"

using namespace std;


class CSVReader {
public:
    CSVReader();
    static void read_TG(const string& file, GraphAM* graph);
    static void read_RWG(string &file, GraphAL* graph);

};


#endif //DA2_CSVREADER_H
