#include <iostream>
#include <fstream>
#include <cstring>

#include <vector>
#include <sstream>

using namespace std;

string getMazeCharacter(int rowIndex, int virtualColIndex, vector<string>& map, int nrCols) {
    string c;
    int colIndex = virtualColIndex % nrCols;
    cout << colIndex;
    c = map.at(rowIndex).at(colIndex);
    
    return c;
}

int main(){

    vector<string> map;
    ifstream inFile;
    inFile.open("input.txt");

    if(!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    int i = 0;
    while(!inFile.eof()) {
        string s;
        inFile >> s;
        map.push_back(s);
        i++;

    }
    inFile.close();

    int nrCols = map.at(0).size();
    int nrRows = map.size();
    int treeCounter = 0;


    for (int j = 0; j < nrRows-1; j++) {
        string c = getMazeCharacter(j, 3*j, map, nrCols);
        
        if(!strcmp(c.c_str(), "#")) {
            treeCounter++;
        }
    }
    cout << "The number of encountered trees are : " << treeCounter << endl;
}