#include <iostream>
#include <string>
#include "Graph.hpp"


int main(int argc, char** argv) {
    
   
    /*const char* fileNameBuffer;
    fileNameBuffer = argv[1];
    std::string fileName(fileNameBuffer);
    std::string filePath = "../../" + fileName;*/
    std::string filePath = "input.txt"; 
    Graph graph(filePath);

    //graph.print();
    //std::cout << Graph::nrOfNodes;

    // Choose origin-node and traverse graph from there
    /*char str[30];
    printf("Enter origin node: ");
    scanf("%s", str);
    std::string originNode(str);*/
    std::string origName = "vibrantpurple";
    Node& origNode = graph.getNode(origName);
    graph.traverse(origNode);

    return 0;
    
}