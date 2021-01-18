#include <string>
#include "Graph.hpp"
#include <boost/algorithm/string.hpp>


void Node::addNeighbour(const std::string& name)
{
    neighbours.push_back(std::move(name));
}

Node::Node(std::string&& name)
    : name(name)
{
}

const std::string& Node::getName() { return name;}

const bool Graph::nodeExist(const std::string& name)
{
    for (auto& node: nodes)
        if (node.getName() == name)
        {
            return true;
        }
    return false;
}

Graph::Graph(const std::string& filename) {
    std::string line; 
    std::ifstream inFile(filename.c_str());
    while(!inFile.eof()) 
    {
        getline(inFile, line);
        
        std::vector<std::string> results;
        boost::split(results, line, [] (char c){return c == ', ' || isdigit(c);});
        for (std::vector<std::string>::iterator nameIter = results.begin();
             nameIter != results.end(); nameIter++)
            if (nameIter == results.begin())
            {   
                Node n(std::move(*nameIter));
                int j = insertNode(n);
            }
            else
            {
                // getNode by intex
                // then add neighbour

            }
            


            
    }
}