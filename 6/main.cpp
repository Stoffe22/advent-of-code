#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

// template <typename T> void printVector(vector<T> &vec) {
    
//     for (typename vector<T>::iterator it = vec.begin(); it != vec.end(); it++) {
//         cout << *it << endl;
//     }
// }

int main() {

    ifstream inFile("input.txt");
    string buffer = " ";

    int counter = 0;
    int sum = 0;

    bool charExist;

    while (!inFile.eof()) 
    {
        string str;
        inFile >> str;
        if (str.empty()) {
            buffer = " ";
            charExist = false;
            counter = 0;
        } else {

            for (auto ch1: str) {
                cout << "ch1: " << ch1 << endl;
                for (auto ch2: buffer) {

                    if (ch1 == ch2) {
                        charExist = true;
                        break;
                    }
                cout << "ch2: " << ch2 << endl;
                }
                cout << "buffer: " << buffer << endl;
                if (!charExist) {
                    buffer.push_back(ch1);
                }
            }
        } 
    }
}