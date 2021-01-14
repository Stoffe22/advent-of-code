#include <string>
#include "Graph.hpp"

#include <range/v3/view/split.hpp>

void node::addNeighbour(const std::string& name)
{
    neighbours.push_back(std::move(name));
}

graph::graph(const std::string& filename) {
    std::string line;
    std::ifstream inFile(filename.c_str());
    while(!inFile.eof()) {
        getline(inFile, line);

    }
}