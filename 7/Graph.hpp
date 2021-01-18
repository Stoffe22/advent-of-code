#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Node 
{
public:
    Node(std::string&& name) {};
    void addNeighbour(const std::string& name);
    const std::string& getName();

private:
    std::string name;
    std::vector<std::string> neighbours;
    bool isVisited;
};

class Graph 
{
public:
    Graph(const std::string& filename);
    const bool nodeExist(const std::string& name); 
    void insertNode(Node& n);
    void traverse();
    void print();
    ~Graph() = default;

    std::vector<Node> nodes;
    static int nrOfNodes;
};