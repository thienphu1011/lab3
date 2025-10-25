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

void enter_record(){
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
            return;
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
        return;
    }
    outfile<<"Name: "<<record.name<<endl;
    outfile<<"Address: "<<record.address<<endl;
    outfile<<"City: "<<record.city<<endl;
    outfile<<"State: "<<record.state<<endl;
    outfile<<"ZIP code: "<<record.zip<<endl;
    outfile<<"Phone number: "<<record.phone<<endl;
    outfile<<"Account balance: "<<record.balance<<endl;
    outfile<<"Date of last payment: "<<record.lastpayment<<endl;
    outfile.close();
    cout <<"Account file "<<filePath<<" saved successfully.\n";
}



void SearchAndDisplay(){
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
void SearchAndDelete(){
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
void SearchAndChanging(){
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
        for (int i=0; i<8 && getline (infile,line[i]); i++){
            cout <<i+1<<". "<<line[i]<<endl;
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




int main() {
    int customerCount=0;
    int option=0;
    do {
        cout << "Menu:\n";
        cout << "1. New records\n";
        cout << "2. Search and Displays\n";
        cout << "3. Search and deletes\n";
        cout << "4. Search and changes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1:
                enter_record();
                break;
            case 2:
                SearchAndDisplay();
                break;
            case 3:
                SearchAndDelete();
                break;
                case 4:
                SearchAndChanging();
                break;
                case 5:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }while(option != 5);

    return 0;
}