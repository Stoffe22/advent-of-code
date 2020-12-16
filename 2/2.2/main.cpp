#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>


int main() {

    std::string line;
    std::ifstream inFile;
    inFile.open("input.txt");

    if(!inFile) {
        std::cout << "Unable to open file";
        exit(1);
    }

    std::string lower, upper;
    std::string range;
    char letter;
    char colon;
    std::string word;
    int counter = 0;
    
    while(!inFile.eof()) {
        getline(inFile, line);

        std::stringstream ss(line);
        ss >> range >> letter >> colon >> word;
        
        std::stringstream ss2(range);
        std::getline(ss2, lower, '-');
        std::getline(ss2, upper, '-');

        std::string::size_type sz;
        int lowerNr = std::stoi(lower, &sz);
        int upperNr = std::stoi(upper, &sz);

        if(letter == word[upperNr - 1] || letter == word[lowerNr - 1]) {
            if(letter == word[upperNr - 1] && letter == word[lowerNr - 1]) {
                continue;
            }
            counter++;
        }

        
    }
    inFile.close();
    
    std::cout << "The answer is: " << counter - 1 << std::endl; // Minus 1 because last line is empty
}