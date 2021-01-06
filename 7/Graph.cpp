#include <string>
#include "Graph.hpp"

void node::addNeighbour(const std::string& name)
{
    neighbours.push_back(name);
}

graph::graph(const std::string& filename) {
    std::string line;
    std::ifstream inFile(filename.c_str());
    while(!inFile.eof()) {
        getline(inFile, line);
        std::cout << line << std::endl; //TODO: make print func
        std::cout << "-------------------" << std::endl;
    }
}