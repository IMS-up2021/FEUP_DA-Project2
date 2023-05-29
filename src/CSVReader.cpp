//
// Created by nesma on 18/05/2023.
//

#include "../header/CSVReader.h"
#include "../header/Graph.h"

CSVReader::CSVReader()= default;;

void CSVReader::read_TG(string fileString, Graph *graph) {
    ifstream file(fileString);
    string line;

    // Skip the header line
    getline(file, line);

    unordered_set<int> nodes;
    int source, destination;
    float distance;

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        source = stoi(token);

        getline(ss, token, ',');
        destination = stoi(token);

        getline(ss, token, ',');
        distance = stof(token);

        nodes.insert(source);
        nodes.insert(destination);
    }

    int numNodes = nodes.size();
    *graph = Graph(numNodes);

    file.clear();
    file.seekg(0);  // Reset file pointer to read again from the beginning

    // Skip the header line
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string token;

        getline(ss, token, ',');
        source = stoi(token);

        getline(ss, token, ',');
        destination = stoi(token);

        getline(ss, token, ',');
        distance = stof(token);

        graph->addEdge(source, destination, distance);
    }
}

/*void CSVReader::read_RWG(const string& file, Graph* graph) {
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
}*/
