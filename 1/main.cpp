#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main() {

    std::vector<int> numbers;
    std::string line;
    std::ifstream inFile;
    inFile.open("input.txt");

    if(!inFile) {
        std::cout << "Unable to open file";
        exit(1);
    }

    int x;
    while(!inFile.eof()) {
        getline(inFile, line);
        std::stringstream ss(line);
        ss >> x;
        numbers.push_back(x);

    }
    inFile.close();

    //Find the triplets of values that sum to 2020
    int answerToPuzzle;
    for(auto val: numbers){
        for(auto val2: numbers){
            for(auto val3: numbers){
                if(val + val2 + val3){
                    if(val + val2 + val3 == 2020){
                        answerToPuzzle = val*val2*val3;
                        break;
                    }
                }
            }
        }
    }

    std::cout << "The answer to the puzzle is: " << answerToPuzzle << std::endl;

}