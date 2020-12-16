#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

char getMazeCharacter(int i, int j) {
    
}

int main(){

    vector<string> map;
    ifstream inFile;
    inFile.open("input.txt");

    if(!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    while(!inFile.eof()) {
        getline(inFile, map.at(0));      
    }
    inFile.close();

}