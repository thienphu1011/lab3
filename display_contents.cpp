#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.h"
using namespace std;

void displayContents(){
    string line ;
    string name;
    ifstream infile;
    ofstream outfile;
    char choice;
    cout <<"Enter the account name of customer to display :";
    cin.ignore();
    getline (cin,name);
    string filename=name +".txt";
    infile.open (filename.c_str());

    if (infile){
        cout <<"Customer found.Contents of the file:\n";
        while (getline (infile,line)){
            cout <<line<<endl;
        }
        infile.close();
    }
    else {
        cout <<"Error\n";
        
    }
}