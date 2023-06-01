#include <iostream>
#include <climits>
#include "../header/menu.h"
#include "../header/CSVReader.h"
#include "../header/algorithms.h"

using namespace  std;


void mainMenu() {
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|        Routing Algorithm for Ocean Shipping and Urban Deliveries       |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Backtracking Heuristic                                      |" << endl;
    cout << "|  Option 2: Triangular Approximation Heuristic                          |" << endl;
    cout << "|  Option 3: Other Heuristics                                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 4: About                                                       |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 4:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                cout << endl << "Thank you for using our Program!" << endl;
                exit(0);
            case 1:
                Menu1();
                break;
            case 2:
                Menu2();
                break;
            case 3:
                Menu3();
                break;
            case 4:
                Menu4();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}


void Menu1(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                         Backtracking Heuristic                         |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 2:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu11();
                break;
            case 2:
                Menu12();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

void Menu11(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                          Backtracking Heuristic                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                             |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                             |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                            |" << endl;
    cout << "|  Option 4: GraphMade (TOY GRAPH)                                       |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                /*GraphAL graphAl;
                string filename = "../data/RWG/graph1/";
                CSVReader::read_RWG(filename, &graphAl);*/
                string filename = "../data/RWG/graphMade/";
                Algorithms::backtrackingRWG(filename);
            }
                break;
            case 2:
                // Add code for case 2
                break;
            case 3:
                // Add code for case 3
                break;
            case 4:
            {
                /*GraphAL graphAl = GraphAL();
                string filename = "../data/RWG/graphMade/";
                CSVReader::read_RWG(filename, &graphAl);*/
                string filename = "../data/RWG/graphMade/";
                Algorithms::backtrackingRWG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

void Menu12(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                          Backtracking Heuristic                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1: {
                string filename = "../data/TG/shipping.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 2:{
                string filename = "../data/TG/stadiums.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            case 3:{
                string filename = "../data/TG/tourism.csv";
                Algorithms::backtrackingTG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }

}



void Menu2(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                            Reading the Data                            |" << endl;
    cout << "|                    Triangular Approximation Heuristic                  |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Real-Word Graphs                                            |" << endl;
    cout << "|  Option 2: Toy Graphs                                                  |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 2:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
            case 1:
                Menu21();
                break;
            case 2:
                Menu22();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

void Menu21(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                    Reading the Data - Real-World Graphs                |" << endl;
    cout << "|                     Triangular Approximation Heuristic                 |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: GraphAM 1 (1k Nodes, 500 Edges)                               |" << endl;
    cout << "|  Option 2: GraphAM 2 (5k Nodes, 3M  Edges)                               |" << endl;
    cout << "|  Option 3: GraphAM 3 (10K Nodes, 10M Edges)                              |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}

void Menu22(){
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                      Reading the Data - Toy Graphs                     |" << endl;
    cout << "|                   Triangular Approximation Heuristic                   |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Shipping                                                    |" << endl;
    cout << "|  Option 2: Stadiums                                                    |" << endl;
    cout << "|  Option 3: Tourism                                                     |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            case 1:
            {
                string filename = "../data/TG/shipping.csv";
                Algorithms::triangularapproximationTG(filename);
            }
                break;
            case 2: {

                string filename = "../data/TG/shipping.csv";
                Algorithms::triangularapproximationTG(filename);
            }
                break;
            case 3: {
                string filename = "../data/TG/tourism.csv";
                Algorithms::triangularapproximationTG(filename);
            }
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }

}

void Menu3(){
}


void Menu4(){

    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                  About                                 |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|  Program Done by:                                                      |" << endl;
    cout << "|  -Luis Filipe Pinto Cunha (up201709375@up.pt)                          |" << endl;
    cout << "|  -Ines Martin Soares (up202108852@up.pt)                               |" << endl;
    cout << "|  -Pedro Miguel Martins Romao (up202108660@up.pt)                       |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|    The goal of this assignment is twofold. First, implement a basic    |" << endl;
    cout << "|  exhaustive approach for the classic routing problem using the TSP     |" << endl;
    cout << "|  abstraction, therefore learning first hand that although such an      |" << endl;
    cout << "|  approach can find optimal solutions, its applicability is restricted  |" << endl;
    cout << "|  to very small graphs. Second, refine your critical thinking skills, by|" << endl;
    cout << "|  developing and analysing a set of approximate solutions to the TSP.   |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Back                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                mainMenu();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}
