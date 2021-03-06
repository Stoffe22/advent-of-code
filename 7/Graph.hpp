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
    std::vector<std::string>& getNeighbours();
    void setVisited(bool state);
    bool IsVisited();

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
    bool isConnected(const std::string& src, const std::string& dest);
    void resetIsVisited();
    ~Graph() = default;

    std::vector<Node> nodes;
    static int nrOfNodes;
};
