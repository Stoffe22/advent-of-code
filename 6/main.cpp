#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {

    ifstream inFile("input.txt");
    string strBuffer = "";
    int sum = 0;
    bool charExist;
    string str;

    while (!inFile.eof()) {
    
        getline(inFile, str);
        if (str.empty()) {
            sum += strBuffer.length();
            strBuffer = "";
        } else {
            for (auto ch1: str) {
                charExist = false;
                for (auto ch2: strBuffer) {
                    if (ch1 == ch2) {
                        charExist = true;
                        break;
                    }
                }
                if (!charExist) {
                    strBuffer.push_back(ch1);
                }
            }
        }
    }
    cout << "The sum is: " << sum << endl;
}