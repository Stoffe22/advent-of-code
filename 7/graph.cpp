#include <iostream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include "graph.hpp"

using namespace std;

node::node() {};

void node::addNeighbour(string name) {
    this->neighbours.push_back(name);
}

graph::graph(ifstream &inFile) {

    string line;
    while(!inFile.eof()) {
        getline(inFile, line);
        string results;
        boost::split(results, line, [](char c){return c == ' ';});
        cout << results;
        break;
    }

}

