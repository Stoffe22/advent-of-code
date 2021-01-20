#include <string>
#include "Graph.hpp"
#include <boost/algorithm/string.hpp>


void Node::addNeighbour(const std::string& name)
{
    neighbours.push_back(std::move(name));
}

Node::Node(std::string&& nodeName)
    : name(nodeName), isVisited(false)
{
    nodeName = nullptr;
}

const std::string& Node::getName() { return name;}

int Graph::addNode(Node& n)
{
    nodes[nrOfNodes++] = n;
    return nrOfNodes - 1;
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
        
        std::vector<std::string> results;
        boost::split(results, line, [] (char c){return c == ', ' || isdigit(c);});
        for (std::vector<std::string>::iterator nameIt = results.begin();
             nameIt != results.end(); nameIt++)
            if (nameIt == results.begin() && !nodeExist(*nameIt))
            {   
                Node n(std::move(*nameIt));
                j = addNode(n);
            }
            else
            {
                Node& n = getNode(j);
                n.addNeighbour(*nameIt);

                if(!nodeExist(*nameIt))
                {
                    Node newNode(std::move(*nameIt));
                }
            }
         
    }
}