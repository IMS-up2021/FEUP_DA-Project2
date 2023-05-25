//
// Created by nesma on 18/05/2023.
//

#include "../header/CSVReader.h"

CSVReader::CSVReader()= default;;

void CSVReader::polpulate() {

}

void CSVReader::read_edges(string &file) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);
    int counter = 1;
    unordered_map<string, int> hashTable;

    while (getline(in, line)) {
        string origin;
        string dest;
        string dist;

        stringstream inputString(line);

        getline(inputString, origin, ',');
        getline(inputString, dest, ',');
        getline(inputString, dist, ',');
        //...
    }
}

void CSVReader::read_nodes(string &file) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);
    int counter = 1;
    unordered_map<string, int> hashTable;

    while (getline(in, line)) {
        string origin;
        string dest;
        string dist;

        stringstream inputString(line);

        getline(inputString, origin, ',');
        getline(inputString, dest, ',');
        getline(inputString, dist, ',');
        //...string &file
    }
}
