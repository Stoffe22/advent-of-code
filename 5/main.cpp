#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

pair<int, int> calcSeat(string seat) {
    int rowStart = 0;
    int rowEnd = 127;
    int colStart = 0;
    int colEnd = 8;
    int rowPos;
    int colPos;

    for (int i = 0; i < 7; i++) {
        char c = seat.at(i);
        
        if (c == 'F') {
            if (i == 6) {
                rowPos = rowStart;
            }
            rowEnd = rowStart + (rowEnd - rowStart)/2;
        } else if (c == 'B') {
            if (i == 6) {
                rowPos = rowEnd;
            }
            rowStart = rowStart + (rowEnd - rowStart)/2;
        }       
    }

    for (int j = 7; j < 10; j++) {
        char c = seat.at(j);
        if (c == 'L') {
            if (j == 9) {
                colPos = colStart;
            }
            colEnd = colStart + (colEnd - colStart)/2;
        } else if (c == 'R') {
            if (j == 9) {
                colPos = colEnd;
            }
            colStart = colStart + (colEnd - colStart)/2;
        }
    }

    return std::make_pair(rowPos, colPos);
}

int main() {

    vector<string> seatCodes;
    ifstream inFile("input.txt");
    
    while(!inFile.eof()) {
        string seat;
        inFile >> seat;
        seatCodes.push_back(seat);
    }

    int idMax = 0;
    for (string line: seatCodes) {
        if(line.empty()) {
            break;
        }

        pair<int, int> pos = calcSeat(line);
        int id = pos.first*8 + pos.second;

        if (id > idMax) {
            idMax = id;
        }
    }

    cout << "The maximum id-number is: " << idMax << endl;

    return 0;
}