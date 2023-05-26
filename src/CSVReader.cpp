//
// Created by nesma on 18/05/2023.
//

#include "../header/CSVReader.h"

CSVReader::CSVReader()= default;;

void CSVReader::read_TG(const string& file, Graph* graph) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);
    int counter = 0;

    while (getline(in, line)) {
        string origStr;
        string destStr;
        string distStr;

        stringstream inputString(line);

        getline(inputString, origStr, ',');
        getline(inputString, destStr, ',');
        getline(inputString, distStr, ',');

        int orig = stoi(origStr);
        int dest = stoi(destStr);
        float dist = stof(distStr);

        Graph edge(orig, dest, dist);
        graph->addTwoWayEdge(edge);
    }
    in.close();
}

void CSVReader::read_RWG(const string& file, Graph* graph) {
    ifstream in;
    in.open(file);
    static string line;
    getline(in, line);

    while (getline(in, line)) {
        string origStr;
        string destStr;
        string distStr;

        stringstream inputString(line);

        getline(inputString, origStr, ',');
        getline(inputString, destStr, ',');
        getline(inputString, distStr, ',');

        int orig = stoi(origStr);
        int dest = stoi(destStr);
        double dist = stod(distStr);

        Vertex* origVertex = graph->getVertex(orig);
        if (origVertex == nullptr) {
            origVertex = new Vertex(orig);
            graph->addVertex(origVertex);
        }
        Vertex* destVertex = graph->getVertex(dest);
        if (destVertex == nullptr) {
            destVertex = new Vertex(dest);
            graph->addVertex(destVertex);
        }

        Edge* edge = origVertex->addEdge(destVertex, dist);
    }

    in.close();
}
