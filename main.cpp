#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.h"
using namespace std;


int main() {
    
    int option=0;
    do {
        cout << "Menu:\n";
        cout << "1. New records\n";
        cout << "2. Search and Displays\n";
        cout << "3. Search and deletes\n";
        cout << "4. Search and changes\n";
        cout << "5. Display the contents of entire file\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;
        string file_name;

        switch(option) {
            case 1:
                file_name = getRecord();
                updateListFile(file_name);
                break;
            case 2:
                searchAndDisplay();
                break;
            case 3:
                searchAndDelete();
                break;
            case 4:
                searchAndChanging();
                break;
            case 5:

                displayContents();
                
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }while(option != 6);

    return 0;
}