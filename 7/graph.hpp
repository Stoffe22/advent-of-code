#pragma once

#include <vector>
struct node {
    string name;
    vector<string> neighbours;
    bool isVisited;

    void addNeighbour(string name);

};

struct graph {
    vector<node> nodes;
    static int nrOfNodes;

    graph(ifstream &inFile);
    void insertNode(node& n);
    void traverse();
};