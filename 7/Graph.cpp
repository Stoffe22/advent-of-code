#include "Graph.hpp"

#include <string>
#include <boost/algorithm/string.hpp>
#include <stdexcept>
#include <queue>

#include "lib/StringHandler.hpp"


void Node::addNeighbour(const std::string& name)
{
    neighbours.push_back(name);
}

Node::Node(const std::string& name)
    : name_(name), isVisited(false)
{
}

bool Node::IsVisited() { return isVisited; }

const std::string& Node::getName() { return name_; }

std::vector<std::string>& Node::getNeighbours() { return neighbours; }

void Node::setVisited(bool state)
{
    Node::isVisited = state;
} 

void Graph::nodeInsert(const std::string& nodeName)
{
    Node node(nodeName);
    nodes.push_back(node);
    nrOfNodes++;
}

Node& Graph::getNode(const std::string& nodeName)
{
    for (auto& node: nodes) {
        if (node.getName() == nodeName) {
            return node;
        }
    }

    throw std::invalid_argument("asked to get non-existing node!");
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
    std::cout << "Started constructing graph.." << std::endl;
    int i = 0;
    
    while(!inFile.eof()) 
    {
        getline(inFile, line);
        //std::cout << i++ << std::endl; 
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

        // Add origin node to graph
        if(!nodeExist(originName))
        {
            nodeInsert(originName);
        }

        for (size_t i = 1; i < nodeList.size(); i++)
        {   
            try 
            {
                Node& originNode = getNode(originName);
                originNode.addNeighbour(nodeList[i]);
                if(!nodeExist(nodeList[i]))
                {
                    nodeInsert(nodeList[i]);
                }
            }
            catch (const std::invalid_argument& e)
            {
                std::cout << "Error: "<< e.what() <<  std::endl;
            }
        }
    }
    std::cout << "Graph constructed!" << std::endl;
}

void Graph::print() 
{
    for (auto node: nodes)
    {
        std::cout << node.getName() << std::endl;
    } 
}

void Graph::traverse(Node& node) {
    std::queue<Node> q;
    node.setVisited(true);
    q.push(node);

    while(!q.empty())
    {
        Node origNode = q.front();
        q.pop();
        for (auto& neighName: origNode.getNeighbours())
        {   
            Node& neighNode = Graph::getNode(neighName);
            if (!neighNode.IsVisited())
            {
                neighNode.setVisited(true);
                q.push(neighNode);
            }
        }
    }
}

bool Graph::isConnected(const std::string& src, const std::string& dest)
{
    Node& srcNode = getNode(src);
    traverse(srcNode);
    Node& destNode = getNode(dest);
    return destNode.IsVisited();
}