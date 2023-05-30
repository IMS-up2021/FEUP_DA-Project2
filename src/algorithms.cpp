
#include "../header/algorithms.h"
#include <iostream>
#include <climits>
#include "../header/CSVReader.h"
#include <chrono>
#include <iomanip>

using namespace std;

void Algorithms::backtrackingTG(const string& filename) {
    // Create the graph and read the data
    Graph graph = Graph(0);
    CSVReader::read_TG(filename, &graph);

    // Initialize variables
    int n = graph.getNumNodes();
    vector<bool> v(n);
    for (int i = 0; i < n; i++)
        v[i] = false;
    v[0] = true;
    float min = INT_MAX;

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Find the minimum weight Hamiltonian Cycle
    graph.tsp(v, 0, n, 1, 0, min);

    // Calculate execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // Output the minimum distance and execution time
    cout << "Minimum distance between all nodes: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}

void Algorithms::triangularapproximationTG(const string& filename) {
    // Create the graph and read the data
    Graph graph = Graph(0);
    CSVReader::read_TG(filename, &graph);
    Graph::tspTriangularApproximation(graph);
}