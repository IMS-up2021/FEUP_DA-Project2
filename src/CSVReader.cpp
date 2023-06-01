
#include "../header/CSVReader.h"

CSVReader::CSVReader()= default;;

void CSVReader:: read_TG(const string& fileString, GraphAM *graph) {
    ifstream file(fileString);
    string line;
    if(fileString[8]!='E'){
        getline(file, line);// Skip the header line, but extra dnt have header
    }

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
    *graph = GraphAM(numNodes);

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

void populateNodes(GraphAL& graph, const string& nodesFile) {
    ifstream file(nodesFile);
    if (!file.is_open()) {
        cout << "Error opening file: " << nodesFile << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        stringstream ss(line);
        string idStr, lgStr, latStr;
        getline(ss, idStr, ',');
        getline(ss, lgStr, ',');
        getline(ss, latStr, ',');

        int id = stoi(idStr);
        double lg = stod(lgStr);
        double lat = stod(latStr);

        graph.addNode(id, lg, lat);
    }

    file.close();
}
// Function to parse the edges.csv file and populate the graph edges
void populateEdges(GraphAL& graph, const string& edgesFile) {
    ifstream file(edgesFile);
    if (!file.is_open()) {
        cout << "Error opening file: " << edgesFile << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header line

    while (getline(file, line)) {
        stringstream ss(line);
        string origemStr, destinoStr, distanciaStr;
        getline(ss, origemStr, ',');
        getline(ss, destinoStr, ',');
        getline(ss, distanciaStr, ',');

        int origem = stoi(origemStr);
        int destino = stoi(destinoStr);
        double distancia = stod(distanciaStr);
        Edge edge = Edge(graph.getVertexAt(destino),distancia);
        graph.addEdgetoAdj(edge,origem);
        Edge edge1 = Edge(graph.getVertexAt(origem),distancia);
        graph.addEdgetoAdj(edge1,destino);
    }

    file.close();
}


void CSVReader::read_RWG(string &file, GraphAL *graph) {
    populateNodes(*graph,file +"nodes.csv");
    populateEdges(*graph,file + "edges.csv");

}


