#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.h"
using namespace std;

void searchAndChanging(){
    string line[8];
    string name;
    ifstream infile;
    ofstream outfile;
    char choice;
    cout<<"Enter the file name that neeeds to be displayed and changed: ";
    cin.ignore();
    getline (cin,name);
    string filename=name +".txt";
    infile.open (filename.c_str());
    
    cout <<"Which line do you want to change (Enter 0 to exit)?: ";
    int lineNumber;
    cin >> lineNumber;
    

    if (lineNumber >0 && lineNumber <=8 && !line[lineNumber -1].empty()){
        cin.ignore();
        cout <<"Enter the new content for line "<<lineNumber<<": ";
        getline (cin,line[lineNumber -1]);
        outfile.open (filename.c_str());
        if(outfile){
            for (int i=0; i<8 && !line[i].empty(); i++){
                outfile <<line[i]<<endl;
                }
                outfile.close();
                cout <<"Line "<<lineNumber<<" updated successfully.\n";
            }else {
                cout <<"Error opening file for writing.\n";
            }
            
        
    }
    else if (lineNumber ==0){
        cout <<"No changes made. Exiting.\n";
    }
    else {
        cout <<"Invalid line number.\n";
    }
}
