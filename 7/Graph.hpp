#pragma once

#include <iostream>
#include <fstream>
#include <vector>

struct node {
    node() {};
    std::string name;
    std::vector<std::string> neighbours;
    bool isVisited;

    void addNeighbour(const std::string& name);
};

struct graph {
    std::vector<node> nodes;
    static int nrOfNodes;

    graph(const std::string& filename);
        
    void insertNode(node& n);
    void traverse();
    void print();
    ~graph() = default; 
};