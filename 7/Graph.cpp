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

        // Remove irrelevant characters and words
        std::vector<std::string> nodeList;
        boost::split(nodeList, line, [] (char c){return c == ', ' || isdigit(c);});
        std::string originName = nodeList[0];
        removeCharacter(originName, ' ');
        removeWord(originName, "contain");
        removeWord(originName, "bag");
        removeWord(originName, "bags");
        
        for (std::vector<std::string>::iterator neighbourIt = nodeList.begin() + 1;
                neighbourIt != nodeList.end();
                neighbourIt++)
        {
            removeCharacter(*neighbourIt, ',');
            removeCharacter(*neighbourIt, ' ');
            removeCharacter(*neighbourIt, '.');
            removeWord(*neighbourIt, "bag");
            removeWord(*neighbourIt, "bags");
        } 

        if(!nodeExist(originName))
        {
            Node originNode(std::move(originName));
            j = addNode(originNode);
        }

        Node& originNode = getNode(j);
        for (auto neighbourName = nodeList.begin() + 1; neighbourName != nodeList.end();
             neighbourName++)
        {   
            originNode.addNeighbour(*neighbourName);
            if(!nodeExist(*neighbourName))
            {
                Node neighbourNode(std::move(*neighbourName));
                addNode(neighbourNode);
            }
        }
    }
}