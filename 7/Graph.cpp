#include "Graph.hpp"

#include <string>
#include <boost/algorithm/string.hpp>

#include "lib/StringHandler.hpp"




void Node::addNeighbour(const std::string& name)
{
    neighbours.push_back(std::move(name));
}

Node::Node(std::string&& name)
    : name_(name), isVisited(false)
{
}

const std::string& Node::getName() { return name_;}

int Graph::addNode(Node& n)
{
    nodes.push_back(n);
    nrOfNodes++;
    return nrOfNodes;
}

Node& Graph::getNode(int index)
{
    return nodes[0];//TODO: implement body
}

const bool Graph::nodeExist(const std::string& name)
{
    for (auto& node: nodes)
        if (node.getName() == name)
        {
            return true;
        }
    return false;
}

int Graph::nrOfNodes = 0;

Graph::Graph(const std::string& filename) {
    std::string line; 
    std::ifstream inFile(filename.c_str());
    int j;
    while(!inFile.eof()) 
    {
        getline(inFile, line);
        
        std::vector<std::string> nodeList;
        boost::split(nodeList, line, [] (char c){return c == ', ' || isdigit(c);});
        std::string originName = nodeList[0];
        cleanString(originName);
        
        if(!nodeExist(originName))
        {
            Node originNode(std::move(originName));
            j = addNode(originNode);
        }

        Node& originNode = getNode(j);
        for (auto nodeIter = nodeList.begin() + 1; nodeIter != nodeList.end(); nodeIter++)
        {
            originNode.addNeighbour(*nodeIter);

            if(!nodeExist(*nodeIter))
            {
                Node neighbourNode(std::move(*nodeIter));
                addNode(neighbourNode);
            }
        }
    }
}