#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){

    ifstream file ("asg4.txt");
    string readout,
    taskNum,state,statement,line;
    bool quit = false;

    while(!quit){
    cout << "Select from one of the options:(1-4)";
    cout << "\n\n";
    cout << "1. Display all items\n";
    cout << "2. Display selected item\n";
    cout << "3. Mark as task done\n";
    cout << "4. Exit the program\n";

 int selection;

 cin >> selection;
    switch (selection) {
        case 1:
            if (file.is_open()) {
                while (getline(file, readout)) {
                    cout << readout << endl;
                }

            }
            break;
        case 2:
            cout << "Which item would you like to see?(1-4)\n";

            if (file.is_open()) {
                int Line;
                cin >> Line;
                for (int i = 1; i <= Line; i++)
                    getline(file, line);
                cout << line;

            }
            break;
        case 3:
            cout << "Mark as task done" << endl;
            break;
        case 4:
            quit = true;

    }
    }
    return 0;
};