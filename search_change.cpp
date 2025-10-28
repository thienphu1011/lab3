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
    if (infile){
        cout <<"File found. Contents of the file:\n";
        for (int i=1; i<=8 && getline (infile,line[i]); i++){
            if (!line[i].empty()&& line[i].back()=='\r'){ //new
                line[i].pop_back();//new
            }
            cout <<i<<"."<<line[i]<<endl;
        }
        infile.close();
    }
    else {
        cout <<"Error\n";
        return;
        
    }
    
    cout <<"Which line do you want to change (Enter 0 to exit)?: ";
    int lineNumber;
    cin >> lineNumber;
    

    if (lineNumber >0 && lineNumber <=8 && !line[lineNumber].empty()){
        cin.ignore();
        cout <<"Enter the new content for line "<<lineNumber<<": ";
        string newValue;
        getline(cin, newValue);

    // Giữ phần đầu (label) đến dấu ':' rồi nối với nội dung mới
    size_t pos = line[lineNumber].find(':');
    if (pos != string::npos) {
        string label = line[lineNumber].substr(0, pos + 1); // giữ phần nhãn
        line[lineNumber] = label + " " + newValue;          // ghép lại
    } else {
        line[lineNumber] = newValue; // fallback nếu dòng không có dấu ':'
    }
        outfile.open (filename.c_str());
        if(outfile){
            for (int i=1; i<=8 && !line[i].empty(); i++){
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
