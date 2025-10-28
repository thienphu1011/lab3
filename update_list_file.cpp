#include <iostream>
#include <fstream>
#include <string>
#include "main.h"
#include <filesystem> 
using namespace std;
namespace fs = std::filesystem;

void updateListFile() {
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
