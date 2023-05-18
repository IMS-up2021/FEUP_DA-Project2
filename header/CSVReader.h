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

using namespace std;


class CSVReader {
private:
    void polpulate();

public:
    CSVReader();
    static void read_edges();
    static void read_nodes();

};


#endif //DA2_CSVREADER_H
