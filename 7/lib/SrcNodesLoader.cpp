
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <fstream>

#include "StringHandler.hpp"

void LoadSrcNodes(const std::string& file, std::vector<std::string>* srcNodes) {
    // Get src nodes
    std::ifstream inFile(file.c_str());
    std::string line;

    while(!inFile.eof())
    {
        getline(inFile, line);
        std::vector<std::string> result;
        boost::split(result, line, [] (char c){return c == ',' || isdigit(c);});
        std::string srcName = result[0];
        removeCharacter(srcName, ' ');
        removeWord(srcName, "contain");
        removeWord(srcName, "bag");
        removeWord(srcName, "bags");
        srcNodes->push_back(srcName);
    } 
}
