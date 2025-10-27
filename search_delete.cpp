#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include "main.h"
using namespace std;

void searchAndDelete(){
    string name;
    string line ;
    ifstream infile;
    ofstream outfile;
    char choice;
    cout <<"Enter the file name that need to display :";
    cin.ignore();
    getline (cin,name);
    string filename=name +".txt";
    infile.open (filename.c_str());

    if (infile){
        cout <<"File found. Contents of the file:\n";
        while (getline (infile,line)){
            cout <<line<<endl;
        }
        infile.close();
    }
    else {
        cout <<"Error\n";
    }
    char choose;
    cout <<"Do you want to delete this file ? (y/n) :";
    cin >> choose;
    if (choose=='y'){
        if (remove(filename.c_str())==0){
            cout <<"File deleted successfully.\n";
        }
        else {
            cout <<"Error deleting file.\n";
        }
    }
    else if (choose=='n'){
        cout <<"The file "<<filename<<" is not deleted.\n";
    }
}