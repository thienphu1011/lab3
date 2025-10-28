#include <iostream>
#include <fstream>
#include <string>
#include <limits>
#include <iomanip>
#include "main.h"
using namespace std;

string getRecord(){
    cout<<"Enter the account name :";
    string acc;
    customer record;
    cin.ignore();
    getline (cin,acc);
    string filePath = acc + ".txt";
    ifstream infile;
    ofstream outfile;
    infile.open(filePath.c_str());
    if (infile){
        cout <<"Account file"<<filePath<<" already exists. Do you want to overwrite it? (y/n).\n";
        char choice;
        cin >> choice;
        if (tolower(choice) != 'y'){
            cout <<"Operation cancelled. Returning to main menu.\n";
            infile.close();
            return "none.txt";
        }
    }
    infile.close();
    cout <<"Enter the name :"; getline (cin,record.name);
    cout <<"Enter the address :"; getline (cin,record.address);
    cout <<"Enter the city :"; getline (cin,record.city);
    cout <<"Enter the state :"; getline (cin,record.state);
    cout <<"Enter the ZIP code :"; getline (cin,record.zip);
    cout <<"Enter the phone number :"; getline (cin,record.phone);

    while (true){
    cout <<"Enter the account balance :"; cin >> record.balance;
    if (record.balance >=0) break;
    else cout <<"Invalid balance! Please enter a non-negative value.\n";    
    }

    cin.ignore();
    cout <<"Enter the date of last payment :"; getline (cin,record.lastpayment);
    outfile.open(filePath.c_str());
    if(!outfile){
        cout <<"Error creating file "<<filePath<<".\n";
        return "none.txt";
    }
    outfile<<"Name: "<<record.name<<endl;
    outfile<<"Address: "<<record.address<<endl;
    outfile<<"City: "<<record.city<<endl;
    outfile<<"State: "<<record.state<<endl;
    outfile<<"ZIP code: "<<record.zip<<endl;
    outfile<<"Phone number: "<<record.phone<<endl;
    outfile<<"Account balance: "<<record.balance<<endl;
    outfile<<"Date of last payment: "<<fixed<<setprecision(0)<<record.lastpayment<<endl;
    outfile.close();
    cout <<"Account file "<<filePath<<" saved successfully.\n";
    return filePath;
}