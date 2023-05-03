#include <iostream>

using namespace  std;

void Menu1(){
}

void Menu2(){
}

void Menu3(){
}


void mainMenu() {
    int op;

    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|        Routing Algorithm for Ocean Shipping and Urban Deliveries       |" << endl;
    cout << "|                                Main Menu                               |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 1: Backtracking Algorithm                                      |" << endl;
    cout << "|  Option 2: Triangular Approximation Heuristic                          |" << endl;
    cout << "|  Option 3: Other Heuristics                                            |" << endl;
    cout << "|                                                                        |" << endl;
    cout << "|  Option 0: Exit                                                        |" << endl;
    cout << "+------------------------------------------------------------------------+" << endl;

    while (true) {
        cout << "Choose an Option between 0 and 3:" << endl;
        cin >> op;
        switch (op) {
            case 0:
                return;
            case 1:
                Menu1();
                break;
            case 2:
                Menu2();
                break;
            case 3:
                Menu3();
                break;
            default:
                cout << "Invalid Option! Please choose again." << endl;
                break;
        }
    }
}
