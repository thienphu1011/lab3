#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <fstream>
#include <string>
#include <limits>
using namespace std;

struct customer{
    string name,address,city,state;
    string zip,phone;
    double balance=0.0;
    string lastpayment;
};

void getRecord();
void searchAndDisplay();
void searchAndDelete();
void searchAndChanging();
void displayContents();



#endif 