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

    //Find the pair of values that sum to 2020
    int answerToPuzzle;
    int counter = 0;
    for(auto val: numbers) {
        for(std::vector<int>::iterator it = numbers.begin() + counter; it != numbers.end(); it++){
            if ((val + *it) == 2020) {
                answerToPuzzle = val * (*it);
                break;
            }
        }
        counter++;
    }

    std::cout << "The answer to the puzzle is: " << answerToPuzzle << std::endl;

}