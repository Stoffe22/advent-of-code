#pragma once

#include <iostream>
#include <fstream>
#include <vector>

class Node 
{
public:
    Node(const std::string& name);
    Node() = default;
    void addNeighbour(const std::string& name);
    const std::string& getName();

private:
    std::string name_;
    std::vector<std::string> neighbours;
    bool isVisited;
};

class Graph 
{
public:
    Graph(const std::string& filename);
    const bool nodeExist(const std::string& name); 
    void nodeInsert(const std::string& nodeName);
    Node& getNode(const std::string& nodeName);
    void traverse(Node& node);
    void print();
    ~Graph() = default;

    std::vector<Node> nodes;
    static int nrOfNodes;
};
