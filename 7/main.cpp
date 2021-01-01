#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct node {
    string name;
    vector<string> neighbours;
    bool isVisited;

    void addNeighbour(string name) {
        this->neighbours.push_back(name);
    }


};

struct graph {
    vector<node> nodes;
    static int nrOfNodes;

    graph(string filename) {
        string line;
        ifstream inFile(filename);
        while(!inFile.eof()) {
            getline(inFile, line);
        }
    }

    void insertNode(node& n);
    void traverse();
};


int main() {

    string file = "input.txt";
    graph graph(file);
    
}