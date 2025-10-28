#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include <filesystem> 
using namespace std;




void updateListFile(string file_name) {
    ofstream listFile("list.txt", ios::app); 
    if (!listFile) {
        cout << "Error: cannot create list.txt\n";
        return;
    }

    int count = 0;
    string line;
    cin.ignore();
    listFile << file_name << '\n';

    // while (getline(file_name, line)) { 

       
    //     if (file_name.empty()) continue;

       
        // if (name == "done") break;

        
        // if (name == "list.txt") {
        //     cout << "Skip: cannot write 'list.txt' into itself.\n";
        //     continue;
        // }

        // nếu CHƯA có đuôi .txt thì thêm vào
        // if (!(name.size() >= 4 && name.substr(name.size() - 4) == ".txt")) {
        //     name += ".txt";
        // }

        // // sau khi thêm, vẫn tránh ghi 'list.txt' (phòng trường hợp ai đó gõ "list")
        // if (name == "list.txt") {
        //     cout << "Skip: cannot write 'list.txt' into itself.\n";
        //     continue;
        // }

    //     listFile << file_name << '\n';
    //     ++count;
    // }

    listFile.close();
    cout << file_name << " was written to list.txt successfully.\n";
}
/*void updateListFile() {
    ofstream listFile("list.txt"); // mở (tạo mới) file list.txt để ghi
    if (!listFile) {
        cout << "Error: cannot create list.txt\n";
        return;
    }

    int count = 0;

    // Duyệt tất cả file trong thư mục hiện tại
    for (const auto& entry : fs::directory_iterator(fs::current_path())) {
        if (entry.is_regular_file()) {
            string filename = entry.path().filename().string();

            // chỉ lấy file có đuôi .txt, và bỏ qua list.txt chính nó
            if (filename.size() > 4 && filename.substr(filename.size() - 4) == ".txt"
                && filename != "list.txt") {
                listFile << filename << '\n'; // ghi tên file vào list.txt
                ++count;
            }
        }
    }

    listFile.close();
    cout  << count << " file names written to list.txt successfully.\n";
}
*/