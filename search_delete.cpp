#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
using namespace std;

void searchAndDelete()
{
    ifstream infile;
    string name;
    string line;
    char choose;
    cout << "Enter the account name that need to be displayed: ";
    cin.ignore();
    getline(cin, name);
    string filename = name + ".txt";
    infile.open(filename.c_str());
    if(infile)
    {
        while(getline(infile, line))
             cout << line << endl;
        infile.close();
    }else cout << "Error. File cannot be read" << endl;
    
    cout << "Do you want to delete this file? (y/n)";
    cin >> choose;
    if(choose == 'y' || choose == 'Y')
    {
        if (remove(filename.c_str())==0)
        {
            cout << "File " << filename << " deleted successfully" << endl;
        }else 
        {
            cout << "Error. Unable to delete file " << filename << endl;
        }
    }else if(choose == 'n' || choose == 'N')
        cout << "File " << filename << " is not deleted"<<endl;
    else if(choose != 'y' || choose != 'Y' || choose != 'n' || choose != 'N')
        cout << "Error. Unable to delete file " << filename << endl;
}