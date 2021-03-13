#include <iostream>
#include <string>
#include "Graph.hpp"


int main(int argc, char** argv) {
    
    const char* fileNameBuffer;
    fileNameBuffer = argv[1];
    std::string fileName(fileNameBuffer);
    std::string filePath = "../../" + fileName;
    Graph graph(filePath);

    graph.print();
    std::cout << Graph::nrOfNodes;


}