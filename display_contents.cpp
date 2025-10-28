#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.h"
using namespace std;

void displayContents() {
    ifstream list("list.txt");
    if (!list) {
        cout << "Error opening list.txt file.\n";
        return;
    }

    string name;
    int count = 0;

    while (getline(list, name)) {
        if (name.empty()) continue;

        string filename = name;
        
        if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt") {
            filename += ".txt";
        }

        cout << ++count << ". Displaying contents of file: " << filename << "\n";

        ifstream infile(filename.c_str());
        if (!infile) {
            cout << "   (Error opening file)\n\n";
            continue;
        }

        string line;
        int lineCount = 0;
        while (getline(infile, line)) {
            // xử lý ký tự \r nếu file được tạo trên Windows
            if (!line.empty() && line.back() == '\r') line.pop_back();
            cout << "   " << line << "\n";
            ++lineCount;
        }
        if (lineCount == 0) cout << "   (Empty file)\n";

        cout << "-------------------------------------\n";
        infile.close();
    }

    if (count == 0) {
        cout << "No customers file listed.\n";
    }
}
  
    
