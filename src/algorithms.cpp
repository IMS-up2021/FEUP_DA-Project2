
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
    cout << "Minimum distance between all nodes and back to initial: " << min << endl;

    // Format and output the execution time with 2 decimal places
    cout << "Execution time: " << fixed << setprecision(2) << executionTime << " seconds" << endl << endl;
}

void Algorithms::triangularapproximationTG(const string& filename) {
    // Create the graph and read the data
    Graph graph = Graph(0);
    CSVReader::read_TG(filename, &graph);

    int numNodes = graph.getNumNodes();

    // Initialize variables
    vector<bool> visited(numNodes, false);
    vector<int> tour;
    int startNode = 0;
    visited[startNode] = true;
    tour.push_back(startNode);

    // Measure execution time
    auto start = chrono::high_resolution_clock::now();

    // Construct the approximate tour using the triangular approximation algorithm
    while (tour.size() < numNodes) {
        int currentNode = tour.back();
        int nextNode = -1;
        float minDistance = INT_MAX;

        // Find the nearest unvisited neighbor with the minimum distance
        for (int neighbor = 0; neighbor < numNodes; ++neighbor) {
            if (!visited[neighbor]) {
                float distance = graph.getWeight(currentNode, neighbor);
                if (distance < minDistance) {
                    minDistance = distance;
                    nextNode = neighbor;
                }
            }
        }

        // Mark the next node as visited and add it to the tour
        visited[nextNode] = true;
        tour.push_back(nextNode);
    }

    // Add the start node to complete the tour
    tour.push_back(startNode);

    // Calculate the total distance of the tour
    float totalDistance = 0.0;
    for (int i = 0; i < numNodes - 1; ++i) {
        int currentNode = tour[i];
        int nextNode = tour[i + 1];
        totalDistance += graph.getWeight(currentNode, nextNode);
    }

    // Measure end execution time
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double executionTime = duration.count();

    // Output the approximate tour, total distance, and execution time
    cout << "Approximate TSP Tour: ";
    for (int node : tour) {
        cout << node << " ";
    }
    cout << endl;
    cout << "Total Distance: " << totalDistance << endl;
    cout << "Execution Time: " << executionTime << " seconds" << endl;
}
